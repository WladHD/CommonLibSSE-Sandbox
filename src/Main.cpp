#include "init/Logging.h"
#include "init/Messaging.h"
#include "init/Papyrus.h"
#include "init/Serialization.h"

namespace WladHD::HorseRNG {
    class GameStartedEvent : public RE::BSTEventSink<RE::TESCellFullyLoadedEvent>
    {
	public:
	    std::function<void()> callback;

	    RE::BSEventNotifyControl ProcessEvent(
		const RE::TESCellFullyLoadedEvent*,
		RE::BSTEventSource<RE::TESCellFullyLoadedEvent>* source
	    ) override
	    {
		callback();
		source->RemoveEventSink(this);
		return RE::BSEventNotifyControl::kContinue;
	    }
    };

    GameStartedEvent GameStartedEventListener;

    void OnGameStart()
    {
	logger::error("Game started!!!");
	// SkyrimScripting::Bind::setupEnv();
	formDataSafe();
    }

    SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
    {
	SetupLog();

	const auto plugin = SKSE::PluginDeclaration::GetSingleton();
	logs::info("{} v{} is loading...", plugin->GetName(), plugin->GetVersion());

	SKSE::Init(a_skse);
	InitMessaging();
	InitPapyrus();
	InitSerialization();

	GameStartedEventListener.callback = []() { OnGameStart(); };
	RE::ScriptEventSourceHolder::GetSingleton()->AddEventSink<RE::TESCellFullyLoadedEvent>(&GameStartedEventListener
	);

	// spdlog::info("sdf");
	// SKSE::log::info("sdf");
	// logger::trace("sdf");

	return true;
    }
} // namespace WladHD::HorseRNG
