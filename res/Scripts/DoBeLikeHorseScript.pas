.info
  .source "DoBeLikeHorseScript.psc"
  .modifyTime 1680549883
  .compileTime 1680549945
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
            CALLSTATIC debug Trace ::nonevar "Horse do be fancy load" 0 ;@line 4
          .endCode
        .endFunction
        .function OnInit 
          .userFlags 0
          .docString ""
          .return NONE
          .paramTable
          .endParamTable
          .localTable
            .local ::nonevar none
          .endLocalTable
          .code
            CALLSTATIC debug Trace ::nonevar "Horse do be fancy init" 0 ;@line 8
            CALLMETHOD RegisterForKey self ::nonevar 203 ;@line 9
          .endCode
        .endFunction
        .function OnKeyDown 
          .userFlags 0
          .docString ""
          .return NONE
          .paramTable
            .param KeyCode Int
          .endParamTable
          .localTable
            .local ::temp0 bool
            .local ::nonevar none
          .endLocalTable
          .code
            COMPAREEQ ::temp0 KeyCode 203 ;@line 13
            JUMPF ::temp0 label1 ;@line 13
            CALLSTATIC debug MessageBox ::nonevar "sdf" ;@line 14
            JUMP label0
            label1:
            label0:
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
            CALLSTATIC debug MessageBox ::nonevar "horsey sad" ;@line 19
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
            .local ::temp1 actor
            .local ::temp2 objectreference
            .local ::temp3 bool
          .endLocalTable
          .code
            CALLSTATIC debug Trace ::nonevar "Do Be on horse asd" 0 ;@line 23
            CALLSTATIC game GetPlayer ::temp1  ;@line 24
            CAST ::temp2 ::temp1 ;@line 24
            COMPAREEQ ::temp3 akActionRef ::temp2 ;@line 24
            JUMPF ::temp3 label3 ;@line 24
            CALLSTATIC debug MessageBox ::nonevar "Do Be on horse" ;@line 25
            JUMP label2
            label3:
            label2:
          .endCode
        .endFunction
      .endState
    .endStateTable
  .endObject
.endObjectTable