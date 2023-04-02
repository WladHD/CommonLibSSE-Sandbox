.info
  .source "DoBeLikeHorseScript.psc"
  .modifyTime 1680471086
  .compileTime 1680473554
  .user "Arbeitsplatz"
  .computer "DESKTOP-FB32QHR"
.endInfo
.userFlagsRef
  .flag conditional 1
  .flag hidden 0
.endUserFlagsRef
.objectTable
  .object DoBeLikeHorseScript ObjectReference
    .userFlags 0
    .docString ""
    .autoState 
    .variableTable
    .endVariableTable
    .propertyTable
    .endPropertyTable
    .stateTable
      .state
        .function GetState
          .userFlags 0
          .docString "Function that returns the current state"
          .return String
          .paramTable
          .endParamTable
          .localTable
          .endLocalTable
          .code
            RETURN ::state
          .endCode
        .endFunction
        .function GotoState
          .userFlags 0
          .docString "Function that switches this object to the specified state"
          .return None
          .paramTable
            .param newState String
          .endParamTable
          .localTable
            .local ::NoneVar None
          .endLocalTable
          .code
            CALLMETHOD onEndState self ::NoneVar
            ASSIGN ::state newState
            CALLMETHOD onBeginState self ::NoneVar
          .endCode
        .endFunction
        .function OnLoad 
          .userFlags 0
          .docString ""
          .return NONE
          .paramTable
          .endParamTable
          .localTable
            .local ::nonevar none
          .endLocalTable
          .code
            CALLSTATIC debug MessageBox ::nonevar "Horse do be fancy" ;@line 4
          .endCode
        .endFunction
        .function OnHit 
          .userFlags 0
          .docString ""
          .return NONE
          .paramTable
            .param akAggressor ObjectReference
            .param akSource Form
            .param akProjectile Projectile
            .param abPowerAttack bool
            .param abSneakAttack bool
            .param abBashAttack bool
            .param abHitBlocked bool
          .endParamTable
          .localTable
            .local ::nonevar none
          .endLocalTable
          .code
            CALLSTATIC debug MessageBox ::nonevar "horsey sad" ;@line 8
          .endCode
        .endFunction
        .function OnActivate 
          .userFlags 0
          .docString ""
          .return NONE
          .paramTable
            .param akActionRef ObjectReference
          .endParamTable
          .localTable
            .local ::nonevar none
            .local ::temp0 actor
            .local ::temp1 objectreference
            .local ::temp2 bool
          .endLocalTable
          .code
            CALLSTATIC debug MessageBox ::nonevar "Do Be on horse asd" ;@line 12
            CALLSTATIC game GetPlayer ::temp0  ;@line 13
            CAST ::temp1 ::temp0 ;@line 13
            COMPAREEQ ::temp2 akActionRef ::temp1 ;@line 13
            JUMPF ::temp2 label1 ;@line 13
            CALLSTATIC debug MessageBox ::nonevar "Do Be on horse" ;@line 14
            CALLSTATIC game GetPlayer ::temp0  ;@line 15
            CALLMETHOD OpenInventory ::temp0 ::nonevar true ;@line 15
            JUMP label0
            label1:
            label0:
          .endCode
        .endFunction
      .endState
    .endStateTable
  .endObject
.endObjectTable