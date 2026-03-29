.include "asm/include/battle_commands.inc"

.data

_000:
    // {0} fled in fear!
    PrintMessage 1661, TAG_NICKNAME, BATTLER_CATEGORY_MSG_TEMP
    Wait
    WaitButtonABTime 30
    UpdateVar OPCODE_SET, BSCRIPT_VAR_SIDE_EFFECT_PARAM, MOVE_SUBSCRIPT_PTR_FORCE_TARGET_TO_SWITCH_OR_FLEE
    Call BATTLE_SUBSCRIPT_FORCE_TARGET_TO_SWITCH_OR_FLEE
    End
    