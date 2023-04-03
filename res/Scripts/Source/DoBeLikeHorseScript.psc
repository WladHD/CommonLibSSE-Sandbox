ScriptName DoBeLikeHorseScript extends ObjectReference

Event OnLoad()
    Debug.Trace("Horse do be fancy load")
EndEvent

Event OnInit()
    Debug.Trace("Horse do be fancy init")
    RegisterForKey(203)
EndEvent

Event OnKeyDown(Int KeyCode)
	If KeyCode == 203
		Debug.MessageBox("sdf")
	EndIf
EndEvent

Event OnHit(ObjectReference akAggressor, Form akSource, Projectile akProjectile, bool abPowerAttack, bool abSneakAttack, bool abBashAttack, bool abHitBlocked)
    Debug.MessageBox("horsey sad")
EndEvent

Event OnActivate(ObjectReference akActionRef)
    Debug.Trace("Do Be on horse asd")
    if akActionRef == Game.GetPlayer()
        Debug.MessageBox("Do Be on horse")
    endif
EndEvent