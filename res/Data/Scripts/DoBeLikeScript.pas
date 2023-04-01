.info
  .source "DoBeLikeScript.psc"
  .modifyTime 1680364040
  .compileTime 1680365277
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
            CALLSTATIC debug MessageBox ::nonevar "Hello, mod!" ;@line 4
          .endCode
        .endFunction
      .endState
    .endStateTable
  .endObject
.endObjectTable