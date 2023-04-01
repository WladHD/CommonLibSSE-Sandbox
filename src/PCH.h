#pragma once

#include <RE/Skyrim.h>
#include <REL/Relocation.h>
#include <SKSE/SKSE.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

namespace WinAPI = SKSE::WinAPI;
namespace logs	 = SKSE::log;
namespace fs	 = std::filesystem;
using namespace std::literals;

namespace stl {
    using namespace SKSE::stl;
}
