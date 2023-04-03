ScriptName DoBeLikeHorseScript extends ObjectReference

Event OnLoad()
    Debug.MessageBox("Horse do be fancy")
EndEvent

Event OnInit()
    RegisterForKey(203)
    Debug.MessageBox("We do be shillin")
EndEvent

Event OnKeyDown(Int KeyCode)
    Debug.MessageBox("hmm?")
	If KeyCode == 203
		Debug.MessageBox("sdf")
	EndIf
EndEvent

Event OnHit(ObjectReference akAggressor, Form akSource, Projectile akProjectile, bool abPowerAttack, bool abSneakAttack, bool abBashAttack, bool abHitBlocked)
    Debug.MessageBox("horsey sad")
EndEvent

Event OnActivate(ObjectReference akActionRef)
    Debug.MessageBox("Do Be on horse asd")
    if akActionRef == Game.GetPlayer()
        Debug.MessageBox("Do Be on horse")
        Game.GetPlayer().OpenInventory(true)
    endif
EndEvent