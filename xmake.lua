-- set minimum xmake version
set_xmakever("2.7.7")

-- set project
set_project("template-commonlibsse-ng")
set_version("0.1.0")
set_license("MIT License")
set_languages("c++23")
set_optimize("faster")
set_warnings("allextra", "error")

-- set allowed
set_allowedarchs("windows|x64")
set_allowedmodes("debug", "releasedbg")

-- set defaults
set_defaultarchs("windows|x64")
set_defaultmode("releasedbg")

-- add rules
add_rules("mode.debug", "mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")

-- set policies
set_policy("build.ccache", false)
set_policy("package.requires_lock", true)

-- require packages
add_requires("fmt")
add_requires("spdlog", { configs = { header_only = false } })
add_requires("commonlibsse-ng", { configs = { skyrim_vr = false } })

-- targets
target("do-be-like")
    -- add packages to target
    add_packages("fmt", "spdlog", "commonlibsse-ng")

    -- add commonlibsse-ng plugin
    add_rules("@commonlibsse-ng/plugin", {
        name = "do-be-like",
        author = "WladHD",
        description = "SKSE64 plugin template using CommonLibSSE-NG"
    })

    -- add src files
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    add_includedirs("src")
    set_pcxxheader("src/PCH.h")

    -- copy build files to MODS or SKYRIM paths
    after_build(function(target)

        local compilePapyrus = function(output)
            local papyrusCompilerPath = os.getenv("SKYRIM_FOLDER") .. "\\Papyrus Compiler\\PapyrusCompiler.exe"
            local papyrusCompileItems = os.match("res\\Data\\Scripts\\Source\\*.psc")
            local compilersImportScriptDirs = os.getenv("SKYRIM_FOLDER") .. "\\Data\\Scripts"
            local compilersImportScriptSourceDirs = compilersImportScriptDirs .. "\\Source"
            local papyrusFlagsFile = compilersImportScriptSourceDirs .. "\\TESV_Papyrus_Flags.flg"
            local compilersImportDirs = compilersImportScriptDirs .. ";" .. compilersImportScriptSourceDirs
            print("sdf")
            print(papyrusCompilerPath)

            for _, file in ipairs(papyrusCompileItems) do
                local pscFile = path.absolute(file)
                local pscFileMoveTo = compilersImportScriptSourceDirs .. "\\" .. path.filename(file)
                print(pscFileMoveTo)
                -- local pexFile = output -- .. "\\" .. path.basename(file, true) .. ".pex"
                print(pscFile)
                -- print(pexFile)

                os.cp(pscFile, pscFileMoveTo, {force = true})
                
                local execCompileCommand = "\"" .. papyrusCompilerPath .. "\" \"" .. pscFileMoveTo .. "\" -o=\"" .. output .. "\" -i=\"" .. compilersImportDirs .. "\" -f=\"" .. papyrusFlagsFile .. "\" -debug"
                
                print(execCompileCommand)
                os.iorun(execCompileCommand)
            end

            for _, file in ipairs(papyrusCompileItems) do
                local pscFile = path.absolute(file)
                local pscFileMoveTo = compilersImportScriptSourceDirs .. "\\" .. path.filename(file)
                os.rm(pscFileMoveTo)
            end
            print("sdf finish")
        end

        compilePapyrus("D:\\Freizeit\\Skyrim Coding\\Project HorseRNG\\template-commonlibsse-ng\\res\\Data\\Scripts")

        local copy = function(env, ext)
            for _, env in pairs(env:split(";")) do
                if os.exists(env) then
                    local plugins = path.join(env, ext, "SKSE/Plugins")
                    os.mkdir(plugins)
                    os.trycp(target:targetfile(), plugins)
                    os.trycp(target:symbolfile(), plugins)
                end
            end
        end
        if os.getenv("SKYRIM_MODS_FOLDER") then
            os.rm(path.join(os.getenv("SKYRIM_MODS_FOLDER"), target:name()))
            copy(os.getenv("SKYRIM_MODS_FOLDER"), target:name())
            os.trycp("res\\*", path.join(os.getenv("SKYRIM_MODS_FOLDER"), target:name()))
        elseif os.getenv("SKYRIM_FOLDER") then
            copy(os.getenv("SKYRIM_FOLDER"), "Data")
        end
    end)
