Scriptname DoBeLikeScript2 extends Quest

string function DBLSandboxMyNativeFunction() global native

Event OnInit()
    RegisterForKey(200)
    Debug.MessageBox("We papydo be " + DBLSandboxMyNativeFunction() + " very hard indeed")
    Game.GetPlayer().OpenInventory()
    Debug.Trace("a_stringToPrint" + DBLSandboxMyNativeFunction())
    Debug.Trace(DBLSandboxMyNativeFunction())  
EndEvent

Event OnKeyDown(Int KeyCode)
    Debug.MessageBox("Inv open?")
	If KeyCode == 200
        Game.GetPlayer().OpenInventory(true)
		Debug.MessageBox("We are " + DBLSandboxMyNativeFunction())
	EndIf
EndEvent