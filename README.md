# Goals of this branch
- Binding the "DoBeLikeScript.psc" to a quest (?) with C++
	- No fully dynamic binding yet
	- Binding is set by Creation Kit (new Quest -> adding existing Script)
	- DBLSandboxMyNativeFunction() is set in C++, works

ToDo:
- Create Quest dynamically and bind "DoBeLikeScript.psc" to that

# Plugin skeleton for CommonLibSSE-NG
- Generates a .dll file from C++
- Compiles all Papyrus code from PSC to PEX
- All above is saved in Vortex's stage folder

# Disclaimer
I'm not sure what I'm doing, but my goal is to create simple Skyrim AE plugins to gain experience with Skyrim development.
You're welcome to use this code, but please keep in mind that it may not work and/or may have flaws.

# Useful Repos
While learning Skyrim AE development, I found following repositories, which helped me with understanding the general structure
- https://github.com/Qudix/template-commonlibsse-ng by Qudix (this repo is based on it)
- https://gitlab.com/colorglass/commonlibsse-sample-plugin by Color-Glass Studios
- https://github.com/SkyrimDev/HelloWorld-using-CommonLibSSE-NG by SkyrimDev

# useful cmds
- xmake project -k vsxmake