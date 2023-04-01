#include "Papyrus.h"

std::string DBLSandboxMyNativeFunction(RE::StaticFunctionTag*) { return "shilling"; }

void InitPapyrus()
{
    logs::trace("Initializing papyrus bindings...");
    const auto intfc = SKSE::GetPapyrusInterface();
    if (!intfc->Register([](RE::BSScript::IVirtualMachine* a_vm) -> bool {
	    // Register papyrus functions here, or change this lambda to a function
	    a_vm->RegisterFunction("DBLSandboxMyNativeFunction", "DoBeLikeScript2", DBLSandboxMyNativeFunction);
	    return true;
	})) {
	stl::report_and_fail("Failed to initialize papyrus bindings.");
    }
}
