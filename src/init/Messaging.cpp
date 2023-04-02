#include "Messaging.h"

#include "Bind.h"

#include <RE/Skyrim.h>
#include <REL/Relocation.h>
#include <SKSE/SKSE.h>
#include <any>
#include <fstream>
#include <iostream>
#include <rapidjson/rapidjson.h>
#include <rapidjson/writer.h>
#include <regex>
#include <set>

template <typename T>
std::string int_to_hex(T i)
{
    std::stringstream stream;
    stream << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) << std::hex << i;
    return stream.str();
}

/*void attachScriptToNPC(RE::TESNPC* npc, const char* scriptName)
{
    FormPropertyMap propertyMap;
    PapyrusScriptBindings::BindToFormPointer(scriptName, npc, propertyMap, true);
}*/

void formDataSafe()
{
    // auto* con = RE::ConsoleLog::GetSingleton();
    // RE::FormID lookAtMyHorse = 0x10982B;
    // auto*      horses	     = RE::TESForm::LookupByID<RE::TESActorBase>(lookAtMyHorse);
    // con->Print("sdf");
    // con->Print("GetFormEditorID: %s", horses->GetFormEditorID());
    // RE::ConsoleLog::GetSingleton()->Print(horses->GetRefCount() + " rc");
    // con->Print("GetFormID: %lu", horses->GetFormID());
    // con->Print("GetGoldValue: %s", horses->GetGoldValue() + " g");
    // RE::ConsoleLog::GetSingleton()->Print("%s", "sdf");

    auto achr		    = 0;
    auto npc		    = 0;
    auto lvl		    = 0;
    const auto& [all, lock] = RE::TESNPC::GetAllForms();
    for (auto& [id, form] : *all) {

	auto achrl = 0;
	auto npcl  = 0;
	auto lvll  = 0;

	if (form->GetFormType() != RE::FormType::NPC) {
	    continue;
	}

	RE::TESNPC* formNpc   = static_cast<RE::TESNPC*>(form);
	std::string formIdHex = int_to_hex(form->formID);
	// RE::TESObjectREFR* ref = formNpc->AsReference();

	if (formNpc->GetRace()->fullName != "HorSe") {
	    continue;
	}

	if (form->GetFormType() == RE::FormType::ActorCharacter) {
	    achr++;
	    achrl++;
	}

	if (form->GetFormType() == RE::FormType::LeveledNPC) {
	    lvl++;
	    lvll++;
	}

	if (form->GetFormType() == RE::FormType::NPC) {
	    npc++;
	    npcl++;
	}

	SKSE::log::debug("A{} N{} LN{}", achrl, npcl, lvll);
	SKSE::log::debug("ObjectName: {}", form->GetObjectTypeName());
	SKSE::log::debug("GetFormType: {}", form->GetFormType());
	SKSE::log::debug("FORMTYPE: {}", form->FORMTYPE);
	SKSE::log::debug("formID: {}", formIdHex);

	// RE::FormID myHorse = 0x0010982B;

	SKSE::log::debug("npcClass->GetFullName: {}", formNpc->npcClass->GetFullName());
	SKSE::log::debug("GetRace()->GetFullName: {}", formNpc->GetRace()->GetFullName());

	NoESP::Bind::Bind_GeneratedObject("DoBeLikeHorseScript", formNpc);
    }

    SKSE::log::debug("A{} N{} LN{}", achr, npc, lvl);
}

void InitMessaging()
{
    logs::trace("Initializing messaging listener...");
    const auto intfc = SKSE::GetMessagingInterface();

    if (!intfc->RegisterListener([](SKSE::MessagingInterface::Message* a_msg) {
	    const auto	plugin = SKSE::PluginDeclaration::GetSingleton();
	    std::string str    = std::format(
		   "Well... gotta start somewhere: {} by {} - v{}\n",
		   plugin->GetName(),
		   plugin->GetAuthor(),
		   plugin->GetVersion()
	       );
	    const char* cstr = str.c_str();

	    switch (a_msg->type) {
		// Skyrim lifecycle events.
		case SKSE::MessagingInterface::kPostLoad: // Called after all plugins have finished running
							  // SKSEPlugin_Load.
		    // It is now safe to do multithreaded operations, or operations against other plugins.
		    break;
		case SKSE::MessagingInterface::kPostPostLoad: // Called after all kPostLoad message handlers have
							      // run.
		    break;
		case SKSE::MessagingInterface::kInputLoaded: // Called when all game data has been found.
		    break;
		case SKSE::MessagingInterface::kDataLoaded: // All ESM/ESL/ESP plugins have loaded, main menu is now
							    // active.
		    // It is now safe to access form data.

		    RE::ConsoleLog::GetSingleton()->Print(cstr);
		    

		    break;
		// Skyrim game events.
		case SKSE::MessagingInterface::kNewGame: // Player starts a new game from main menu.
		    break;
		case SKSE::MessagingInterface::kPreLoadGame: // Player selected a game to load, but it hasn't loaded
							     // yet.
		    // a_msg->data will be the name of the loaded save.
		    break;
		case SKSE::MessagingInterface::kPostLoadGame: // Player's selected save game has finished loading.
		    // a_msg->data will be a boolean indicating whether the load was successful.
		    formDataSafe();
		    break;
		case SKSE::MessagingInterface::kSaveGame: // Player has saved a game.
		    // a_msg->data will be the save name.
		    break;
		case SKSE::MessagingInterface::kDeleteGame: // Player deleted a saved game from within the load
							    // menu.
		    break;
	    }
	})) {
	stl::report_and_fail("Failed to initialize message listener.");
    }
}