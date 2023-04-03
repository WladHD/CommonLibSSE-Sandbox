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

    player->PlaceObjectAtMe(form, true);
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

class OurEventSink : public RE::BSTEventSink<RE::TESHitEvent>,
		     public RE::BSTEventSink<RE::TESActivateEvent>,
		     public RE::BSTEventSink<SKSE::CrosshairRefEvent>,
		     public RE::BSTEventSink<RE::MenuOpenCloseEvent>,
		     public RE::BSTEventSink<RE::InputEvent*>
{
	OurEventSink()				     = default;
	OurEventSink(const OurEventSink&)	     = delete;
	OurEventSink(OurEventSink&&)		     = delete;
	OurEventSink& operator=(const OurEventSink&) = delete;
	OurEventSink& operator=(OurEventSink&&)	     = delete;

    public:
	static OurEventSink* GetSingleton()
	{
	    static OurEventSink singleton;
	    return &singleton;
	}

	RE::BSEventNotifyControl ProcessEvent(const RE::TESHitEvent* event, RE::BSTEventSource<RE::TESHitEvent>*)
	{
	    auto targetName = event->target->GetBaseObject()->GetName();
	    auto sourceName = event->cause->GetBaseObject()->GetName();
	    logger::info("{} hit {}", sourceName, targetName);
	    if (event->flags.any(RE::TESHitEvent::Flag::kPowerAttack)) {
		logger::info("Ooooo power attack!");
	    }
	    return RE::BSEventNotifyControl::kContinue;
	}

	RE::BSEventNotifyControl
	ProcessEvent(const RE::TESActivateEvent* event, RE::BSTEventSource<RE::TESActivateEvent>*)
	{
	    auto activatedName = event->objectActivated->GetBaseObject()->GetName();
	    auto activatorName = event->actionRef->GetBaseObject()->GetName();
	    logger::info("{} activated {}", activatorName, activatedName);
	    return RE::BSEventNotifyControl::kContinue;
	}

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

	RE::BSEventNotifyControl
	ProcessEvent(const RE::MenuOpenCloseEvent* event, RE::BSTEventSource<RE::MenuOpenCloseEvent>*)
	{
	    if (event->opening) {
		logger::info("OPEN MENU {}", event->menuName);
	    } else {
		logger::info("CLOSE MENU {}", event->menuName);
	    }
	    return RE::BSEventNotifyControl::kContinue;
	}

	RE::BSEventNotifyControl ProcessEvent(RE::InputEvent* const* eventPtr, RE::BSTEventSource<RE::InputEvent*>*)
	{
	    if (!eventPtr) {
		return RE::BSEventNotifyControl::kContinue;
	    }

	    auto* event = *eventPtr;
	    if (!event) {
		return RE::BSEventNotifyControl::kContinue;
	    }

	    if (event->GetEventType() == RE::INPUT_EVENT_TYPE::kButton) {
		auto* buttonEvent = event->AsButtonEvent();
		auto  dxScanCode  = buttonEvent->GetIDCode();
		logger::info("Pressed key {}", dxScanCode);
	    }

	    return RE::BSEventNotifyControl::kContinue;
	}
};

class ModEventEventSink : public RE::BSTEventSink<RE::TESObjectLoadedEvent>
{
    public:
	RE::BSEventNotifyControl
	ProcessEvent(const RE::TESObjectLoadedEvent* event, RE::BSTEventSource<RE::TESObjectLoadedEvent>*)
	{
	    logger::info("Object loaded {} {} {} {}", event->formID, event->loaded, event->pad5, event->pad6);

	    return RE::BSEventNotifyControl::kContinue;
	}
};

void OnMessage(SKSE::MessagingInterface::Message* message)
{
    if (message->type == SKSE::MessagingInterface::kInputLoaded) {
	RE::BSInputDeviceManager::GetSingleton()->AddEventSink(OurEventSink::GetSingleton());
    }
}

void InitPapyrus()
{
    auto* eventSink = OurEventSink::GetSingleton();

    // ScriptSource
    auto* eventSourceHolder = RE::ScriptEventSourceHolder::GetSingleton();
    eventSourceHolder->AddEventSink<RE::TESHitEvent>(eventSink);
    eventSourceHolder->AddEventSink<RE::TESActivateEvent>(eventSink);
    eventSourceHolder->AddEventSink<RE::TESObjectLoadedEvent>(new ModEventEventSink());

    // SKSE
    SKSE::GetCrosshairRefEventSource()->AddEventSink(eventSink);

    // UI
    RE::UI::GetSingleton()->AddEventSink<RE::MenuOpenCloseEvent>(eventSink);

    // Input Device
    SKSE::GetMessagingInterface()->RegisterListener(OnMessage);

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