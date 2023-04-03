.info
  .source "DoBeLikeScript2.psc"
  .modifyTime 1680459512
  .compileTime 1680481286
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
            .local ::nonevar none
            .local ::temp0 string
            .local ::temp1 actor
          .endLocalTable
          .code
            CALLMETHOD RegisterForKey self ::nonevar 200 ;@line 6
            CALLSTATIC dobelikescript2 DBLSandboxMyNativeFunction ::temp0  ;@line 7
            STRCAT ::temp0 "We papydo be " ::temp0 ;@line 7
            STRCAT ::temp0 ::temp0 " very hard indeed" ;@line 7
            CALLSTATIC debug MessageBox ::nonevar ::temp0 ;@line 7
            CALLSTATIC game GetPlayer ::temp1  ;@line 8
            CALLMETHOD OpenInventory ::temp1 ::nonevar false ;@line 8
            CALLSTATIC dobelikescript2 DBLSandboxMyNativeFunction ::temp0  ;@line 9
            STRCAT ::temp0 "a_stringToPrint" ::temp0 ;@line 9
            CALLSTATIC debug Trace ::nonevar ::temp0 0 ;@line 9
            CALLSTATIC dobelikescript2 DBLSandboxMyNativeFunction ::temp0  ;@line 10
            CALLSTATIC debug Trace ::nonevar ::temp0 0 ;@line 10
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
            .local ::nonevar none
            .local ::temp2 bool
            .local ::temp3 actor
            .local ::temp4 string
          .endLocalTable
          .code
            CALLSTATIC debug MessageBox ::nonevar "Inv open?" ;@line 14
            COMPAREEQ ::temp2 KeyCode 200 ;@line 15
            JUMPF ::temp2 label1 ;@line 15
            CALLSTATIC game GetPlayer ::temp3  ;@line 16
            CALLMETHOD OpenInventory ::temp3 ::nonevar true ;@line 16
            CALLSTATIC dobelikescript2 DBLSandboxMyNativeFunction ::temp4  ;@line 17
            STRCAT ::temp4 "We are " ::temp4 ;@line 17
            CALLSTATIC debug MessageBox ::nonevar ::temp4 ;@line 17
            JUMP label0
            label1:
            label0:
          .endCode
        .endFunction
      .endState
    .endStateTable
  .endObject
.endObjectTable