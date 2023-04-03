# Goals of this branch
- DBLSandboxMyNativeFunction() is set in C++, works
- Quest dynamically created and "DoBeLikeScript.psc" bound

TODO
- Bind "DoBeLikeHorseScript.psc" to horse... kinda works
	- OnInit() event shot, but all other reference methods arent working (pain)

# Plugin skeleton for CommonLibSSE-NG
- Generates a .dll file from C++
- Compiles all Papyrus code from PSC to PEX
- All above is saved in Vortex's stage folder

# Disclaimer
I'm not sure what I'm doing, but my goal is to create simple Skyrim AE plugins to gain experience with Skyrim development.
You're welcome to use this code, but please keep in mind that it may not work and/or may have flaws.

# Useful Repos
While trying to code, I found following helpful repositories

## Structure - setup / minimalistic plugin 
While learning Skyrim AE development, I found following repositories, which helped me with understanding the general structure
- https://github.com/Qudix/template-commonlibsse-ng by Qudix (this repo is based on it)
- https://gitlab.com/colorglass/commonlibsse-sample-plugin by Color-Glass Studios
- https://github.com/SkyrimDev/HelloWorld-using-CommonLibSSE-NG by SkyrimDev

## Coding / Forms / Papyrus & C++
Here are unsorted links to repos which contain specific implementations
- https://github.com/mrowrpurr/LogWhatIsUnderMyCrosshair/blob/main/plugin.cpp
- https://gist.github.com/mrowrpurr/0c75be53e50618cbf5f9f1767cae5506
- https://github.com/mrowrpurr/SkySpec/blob/a80eb93d68676f948dcb574e357260c9268c369a/Papyrus.Reflection/include/Papyrus/Reflection/PapyrusScript.h
- https://github.com/egocarib/EnchantingAwakened/blob/master/EA_Extender/src/Events.cpp
- https://github.com/chesko256/SimplyKnock/blob/master/simplyknock_skse_plugin/skse/GameEvents.cpp
- https://github.com/SkyrimScripting/BIND/blob/main/plugin.cpp#L77

# useful cmds
- xmake project -k vsxmake