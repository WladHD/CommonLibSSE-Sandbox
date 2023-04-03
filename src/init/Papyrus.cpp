#include "Papyrus.h"

void Force_Link(std::string ScriptName)
{
    logs::info("Linking {} ...", ScriptName);
    RE::BSScript::Internal::VirtualMachine::GetSingleton()->linker.Process(RE::BSFixedString(ScriptName));
    logs::info("{} linked ...", ScriptName);
}

void Bind_Form(RE::TESForm* form, std::string ScriptName)
{
    Force_Link(ScriptName);

    auto handle = RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetObjectHandlePolicy()->GetHandleForObject(
	form->GetFormType(), form
    );
    RE::BSTSmartPointer<RE::BSScript::Object> object;
    auto isgut = RE::BSScript::Internal::VirtualMachine::GetSingleton()->CreateObject(ScriptName, object);
    RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetObjectBindPolicy()->BindObject(object, handle);

    logs::info(
	"Bound form {:x} to {} (isgut? {} - size {})",
	form->GetFormID(),
	ScriptName,
	isgut,
	RE::BSScript::Internal::VirtualMachine::GetSingleton()->GetObjectBindPolicy()->attachedScripts.size()
    );
}

std::string DBLSandboxMyNativeFunction(RE::StaticFunctionTag*)
{
    logger::info("Placing horse");
    RE::FormID		 lookAtMyHorse = 0x10982B;
    RE::TESNPC*		 form	       = RE::TESForm::LookupByID<RE::TESNPC>(lookAtMyHorse);
    RE::PlayerCharacter* player	       = RE::PlayerCharacter::GetSingleton();

    player->PlaceObjectAtMe(form, false);
    logger::info(
	"Placed horse EID'{}' FID'{}' R'{}' P'{}' U'{}' Dynamic?{}",
	form->GetFormEditorID(),
	form->GetFormID(),
	form->GetRefCount(),
	form->IsProtected(),
	form->IsUnique(),
	form->IsDynamicForm()
    );

    Bind_Form(form, "DoBeLikeHorseScript");

    return "shilling";
}

void Bind_GeneratedQuest(std::string ScriptName, std::string editorID = "")
{
    logs::info("Generating Quest for {} ...", ScriptName);
    RE::TESQuest* form = RE::IFormFactory::GetConcreteFormFactoryByType<RE::TESQuest>()->Create();
    if (!editorID.empty()) {
	form->SetFormEditorID(editorID.c_str());
    }
    Bind_Form(form, ScriptName);
    logs::info("Bound {} to ...", ScriptName);
    logs::info("Bound {} to {}", ScriptName, form->GetFormEditorID());
}

class ModEventEventSink : public RE::BSTEventSink<SKSE::CrosshairRefEvent>
{
    public:
	RE::BSEventNotifyControl
	ProcessEvent(const SKSE::CrosshairRefEvent* event, RE::BSTEventSource<SKSE::CrosshairRefEvent>*) override
	{
	    auto* ref = event->crosshairRef.get();
	    if (ref) {
		auto* base = ref->GetBaseObject();
		logger::info(
		    "REF:{:x} [{}] '{}' | BASE:{:x} [{}] '{}'",
		    ref->GetFormID(),
		    ref->GetFormEditorID(),
		    ref->GetDisplayFullName(),
		    base->GetFormID(),
		    base->GetFormEditorID(),
		    base->GetName()
		);
	    }
	    return RE::BSEventNotifyControl::kContinue;
	}
};

void InitPapyrus()
{
    SKSE::GetCrosshairRefEventSource()->AddEventSink(new ModEventEventSink());
    logs::trace("Initializing papyrus bindings...");
    const auto intfc = SKSE::GetPapyrusInterface();
    if (!intfc->Register([](RE::BSScript::IVirtualMachine* a_vm) -> bool {
	    // Register papyrus functions here, or change this lambda to a function
	    a_vm->RegisterFunction("DBLSandboxMyNativeFunction", "DoBeLikeScript", DBLSandboxMyNativeFunction);
	    return true;
	})) {
	stl::report_and_fail("Failed to initialize papyrus bindings.");
    }
}

void BindPapyrusScripts() { Bind_GeneratedQuest("DoBeLikeScript"); }