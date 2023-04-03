#pragma once

namespace SkyrimScripting::Bind {
    void setupEnv();

    void Bind_GeneratedObject(std::string ScriptName, RE::TESForm* baseForm = nullptr);

    void Bind_Form(RE::TESForm* form, std::string ScriptName);

    void Bind_GeneratedObject_BaseFormID(RE::FormID baseFormID, std::string ScriptName);
} // namespace SkyrimScripting::Bind