#include "Messaging.h"

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
		case SKSE::MessagingInterface::kPostPostLoad: // Called after all kPostLoad message handlers have run.
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
		    break;
		case SKSE::MessagingInterface::kSaveGame: // Player has saved a game.
		    // a_msg->data will be the save name.
		    break;
		case SKSE::MessagingInterface::kDeleteGame: // Player deleted a saved game from within the load menu.
		    break;
	    }
	})) {
	stl::report_and_fail("Failed to initialize message listener.");
    }
}