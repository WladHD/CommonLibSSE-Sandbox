#include "Papyrus.h"

int AddIntsHehe(RE::StaticFunctionTag*, int a, int b) { return a + b; }

void InitPapyrus()
{
    logs::trace("Initializing papyrus bindings...");
    const auto intfc = SKSE::GetPapyrusInterface();
    if (!intfc->Register([](RE::BSScript::IVirtualMachine* /*a_vm*/) -> bool {
	    // Register papyrus functions here, or change this lambda to a function
	    // a_vm->RegisterFunction("AddIntsHehe", "PapyrusTest", AddIntsHehe);
	    return true;
	})) {
	stl::report_and_fail("Failed to initialize papyrus bindings.");
    }
}
