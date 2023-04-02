ScriptName DoBeLikeHorseScript extends ObjectReference

Event OnLoad()
    Debug.MessageBox("Horse do be fancy")
endEvent

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