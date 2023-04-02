#include "init/Logging.h"
#include "init/Messaging.h"
#include "init/Papyrus.h"
#include "init/Serialization.h"

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
    SetupLog();

    const auto plugin = SKSE::PluginDeclaration::GetSingleton();
    logs::info("{} v{} is loading...", plugin->GetName(), plugin->GetVersion());

    SKSE::Init(a_skse);
    InitMessaging();
    InitPapyrus();
    InitSerialization();

    // spdlog::info("sdf");
    // SKSE::log::info("sdf");
    // logger::trace("sdf");

    return true;
}
