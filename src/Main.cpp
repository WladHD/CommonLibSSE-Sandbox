#include "init/Logging.h"
#include "init/Messaging.h"
#include "init/Papyrus.h"
#include "init/Serialization.h"

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
    InitLogging();

    const auto plugin = SKSE::PluginDeclaration::GetSingleton();
    logs::info("{} v{} is loading...", plugin->GetName(), plugin->GetVersion());

    SKSE::Init(a_skse);
    InitMessaging();
    InitPapyrus();
    InitSerialization();

    logs::info("{} loaded.", plugin->GetName());

    return true;
}
