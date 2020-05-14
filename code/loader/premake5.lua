project "Open1560"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    warnings "Extra"
    flags "FatalWarnings"

    useARTSPCH()
    includeARTS()

    targetname "dinput"

    files { "loader.cpp" }

    links { "arts_midtown", "DbgHelp", "Winmm" }

    if MM1_GAME_DIRECTORY ~= nil then
        local game_files = path.join(ROOT_DIR, "game")

        postbuildcommands {
            '{COPY} "%{cfg.buildtarget.abspath}" "' .. MM1_GAME_DIRECTORY .. '"',
            '{COPY} "%{cfg.buildtarget.directory}%{cfg.buildtarget.basename}.pdb" "' .. MM1_GAME_DIRECTORY .. '"',
            '{COPY} "' .. game_files .. '" "' .. MM1_GAME_DIRECTORY .. '"',
        }

        debugdir (MM1_GAME_DIRECTORY)
        debugcommand (MM1_GAME_DIRECTORY .. 'Open1560.exe')

        if MM1_COMMAND_LINE ~= nil then
            debugargs (MM1_COMMAND_LINE)
        end
    end
