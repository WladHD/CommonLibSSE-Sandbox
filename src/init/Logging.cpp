#include "Logging.h"

void InitLogging()
{
    auto path = logs::log_directory();
    if (!path) {
	return;
    }

    const auto plugin = SKSE::PluginDeclaration::GetSingleton();
    *path /= fmt::format("{}.log", plugin->GetName());

    std::shared_ptr<spdlog::sinks::sink> sink;
    if (WinAPI::IsDebuggerPresent()) {
	sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
    } else {
	sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
    }

    auto logger = std::make_shared<spdlog::logger>("global", sink);
    logger->set_level(spdlog::level::info);
    logger->flush_on(spdlog::level::info);

    spdlog::set_default_logger(std::move(logger));
    spdlog::set_pattern("[%^%L%$] %v");
}
