.info
  .source "DoBeLikeScript.psc"
  .modifyTime 1680540430
  .compileTime 1680549946
  .user "Arbeitsplatz"
  .computer "DESKTOP-FB32QHR"
.endInfo
.userFlagsRef
  .flag conditional 1
  .flag hidden 0
.endUserFlagsRef
.objectTable
  .object DoBeLikeScript Quest
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
        .function DBLSandboxMyNativeFunction native static
          .userFlags 0
          .docString ""
          .return string
          .paramTable
          .endParamTable
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
            CALLMETHOD RegisterForKey self ::nonevar 200 ;@line 6
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
            .local ::temp1 string
            .local ::nonevar none
          .endLocalTable
          .code
            COMPAREEQ ::temp0 KeyCode 200 ;@line 10
            JUMPF ::temp0 label1 ;@line 10
            CALLSTATIC dobelikescript DBLSandboxMyNativeFunction ::temp1  ;@line 11
            STRCAT ::temp1 "We are " ::temp1 ;@line 11
            STRCAT ::temp1 ::temp1 " around" ;@line 11
            CALLSTATIC debug Trace ::nonevar ::temp1 0 ;@line 11
            JUMP label0
            label1:
            label0:
          .endCode
        .endFunction
      .endState
    .endStateTable
  .endObject
.endObjectTable