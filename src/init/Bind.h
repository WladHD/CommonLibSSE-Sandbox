#pragma once

namespace NoESP::Bind {
    void Bind_Form(RE::TESForm* form, std::string scriptName)
    {
	RE::BSScript::Internal::VirtualMachine* vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
	auto handle = vm->GetObjectHandlePolicy()->GetHandleForObject(form->GetFormType(), form);
	RE::BSTSmartPointer<RE::BSScript::Object> object;
	vm->CreateObject(scriptName, object);
	vm->GetObjectBindPolicy()->BindObject(object, handle);
	logger::info("Bound form {:x} to {}", form->GetFormID(), scriptName);
    }

    void Bind_GeneratedObject(std::string scriptName, RE::TESForm* baseForm = nullptr)
    {
	RE::TESForm*	   DefaultBaseFormForCreatingObjects = RE::TESForm::LookupByID(0xAEBF3); // DwarvenFork
	RE::TESObjectREFR* LocationForPlacingObjects =
	    RE::TESForm::LookupByID<RE::TESObjectREFR>(0xBBCD1); // The chest in WEMerchantChests

	if (!baseForm) {
	    baseForm = DefaultBaseFormForCreatingObjects; // By default, simply puts a fork next to the WEMerchantChest
							  // in the WEMerchantChests cell. Forking awesome.
	}
	auto niPointer =
	    LocationForPlacingObjects->PlaceObjectAtMe(skyrim_cast<RE::TESBoundObject*, RE::TESForm>(baseForm), true);
	if (niPointer) {
	    Bind_Form(niPointer.get(), scriptName);
	} else {
	    logger::info(
		"BIND ERROR ({}) Could not generate object ({}, {})",
		scriptName,
		baseForm->GetFormID(),
		baseForm->GetName()
	    );
	}
    }
} // namespace NoESP::Bind