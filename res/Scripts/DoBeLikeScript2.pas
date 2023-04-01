.info
  .source "DoBeLikeScript2.psc"
  .modifyTime 1680374231
  .compileTime 1680374285
  .user "Arbeitsplatz"
  .computer "DESKTOP-FB32QHR"
.endInfo
.userFlagsRef
  .flag conditional 1
  .flag hidden 0
.endUserFlagsRef
.objectTable
  .object DoBeLikeScript2 Quest
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
            .local ::temp0 string
            .local ::nonevar none
          .endLocalTable
          .code
            CALLSTATIC dobelikescript2 DBLSandboxMyNativeFunction ::temp0  ;@line 6
            STRCAT ::temp0 "We do be " ::temp0 ;@line 6
            STRCAT ::temp0 ::temp0 " very hard" ;@line 6
            CALLSTATIC debug MessageBox ::nonevar ::temp0 ;@line 6
            CALLSTATIC dobelikescript2 DBLSandboxMyNativeFunction ::temp0  ;@line 7
            STRCAT ::temp0 "a_stringToPrint" ::temp0 ;@line 7
            CALLSTATIC debug Trace ::nonevar ::temp0 0 ;@line 7
            CALLSTATIC dobelikescript2 DBLSandboxMyNativeFunction ::temp0  ;@line 8
            CALLSTATIC debug Trace ::nonevar ::temp0 0 ;@line 8
          .endCode
        .endFunction
      .endState
    .endStateTable
  .endObject
.endObjectTable