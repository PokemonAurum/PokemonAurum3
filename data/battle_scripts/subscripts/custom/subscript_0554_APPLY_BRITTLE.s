.include "asm/include/battle_commands.inc"

.data

_000:
    // Shield Dust blocks secondary-effect infliction
    CompareVarToValue OPCODE_NEQ, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_INDIRECT, _printAttack
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_SHIELD_DUST, _244

_printAttack:
    CompareVarToValue OPCODE_NEQ, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_DIRECT, _gateChecks
    PrintAttackMessage
    Wait

_gateChecks:
    // Ability-caused infliction bypasses Substitute
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_ABILITY, _checkAlreadyInflicted
    CheckSubstitute BATTLER_CATEGORY_SIDE_EFFECT_MON, _244

_checkAlreadyInflicted:
    CompareMonDataToValue OPCODE_FLAG_SET, BATTLER_CATEGORY_SIDE_EFFECT_MON, BMON_DATA_STATUS2, STATUS2_BRITTLE, _260
    CompareVarToValue OPCODE_FLAG_SET, BSCRIPT_VAR_MOVE_STATUS_FLAGS, MOVE_STATUS_SEMI_INVULNERABLE|MOVE_STATUS_MISSED, _244
    CompareVarToValue OPCODE_FLAG_SET, BSCRIPT_VAR_SIDE_CONDITION_STAT_CHANGE, SIDE_CONDITION_SAFEGUARD, _326

_bypassSafeguard:
    CompareVarToValue OPCODE_NEQ, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_DIRECT, _action
    PlayMoveAnimation BATTLER_CATEGORY_ATTACKER
    Wait

_action:
    PlayBattleAnimation BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_BRITTLE
    Wait
    UpdateMonData OPCODE_FLAG_ON, BATTLER_CATEGORY_SIDE_EFFECT_MON, BMON_DATA_STATUS2, STATUS2_BRITTLE
    // {0} has become brittle!
    PrintMessage 1780, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    SetHealthbarStatus BATTLER_CATEGORY_SIDE_EFFECT_MON, BATTLE_ANIMATION_BRITTLE
    WaitButtonABTime 30
    End

_244:
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_INDIRECT, _End
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_ABILITY, _End
    WaitButtonABTime 30
    Call BATTLE_SUBSCRIPT_BUT_IT_FAILED
    End

_260:
    // Already has Brittle — silently fail for indirect/ability; "but it failed" for moves
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_INDIRECT, _End
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_ABILITY, _End
    WaitButtonABTime 30
    Call BATTLE_SUBSCRIPT_BUT_IT_FAILED
    End

_handleInfiltrator:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_ABILITY, ABILITY_INFILTRATOR, _bypassSafeguard
    GoTo _postInfiltratorCheck

_handleInfiltratorMoveEffect:
    CompareMonDataToValue OPCODE_EQU, BATTLER_CATEGORY_ATTACKER, BMON_DATA_ABILITY, ABILITY_INFILTRATOR, _bypassSafeguard
    End

_326:
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_DIRECT, _handleInfiltrator
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_MOVE_EFFECT, _handleInfiltratorMoveEffect
    CompareVarToValue OPCODE_EQU, BSCRIPT_VAR_SIDE_EFFECT_TYPE, SIDE_EFFECT_TYPE_INDIRECT, _End
_postInfiltratorCheck:
    WaitButtonABTime 30
    // {0} is protected by Safeguard!
    PrintMessage 200, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON

_337:
    Wait
    WaitButtonABTime 30
    UpdateVar OPCODE_FLAG_ON, BSCRIPT_VAR_MOVE_STATUS_FLAGS, MOVE_STATUS_NO_MORE_WORK

_End:
    End
