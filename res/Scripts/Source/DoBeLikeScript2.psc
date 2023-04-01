Scriptname DoBeLikeScript2 extends Quest

string function DBLSandboxMyNativeFunction() global native

Event OnInit()
    Debug.MessageBox("We do be " + DBLSandboxMyNativeFunction() + " very hard")
    Debug.Trace("a_stringToPrint" + DBLSandboxMyNativeFunction())
    Debug.Trace(DBLSandboxMyNativeFunction())
EndEvent