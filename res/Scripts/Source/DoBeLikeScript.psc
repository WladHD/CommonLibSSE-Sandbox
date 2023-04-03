Scriptname DoBeLikeScript extends Quest

string function DBLSandboxMyNativeFunction() global native

Event OnInit()
    RegisterForKey(200)
EndEvent

Event OnKeyDown(Int KeyCode)
	If KeyCode == 200
		Debug.Trace("We are " + DBLSandboxMyNativeFunction() + " around")
	EndIf
EndEvent