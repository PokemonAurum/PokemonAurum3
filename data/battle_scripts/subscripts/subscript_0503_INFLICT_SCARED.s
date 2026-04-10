.include "asm/include/battle_commands.inc"

.data

// Inflict the Scared condition3 status on BATTLER_CATEGORY_SIDE_EFFECT_MON.
// Ghost-type, exclusive, permanent (no turn counter — flag only).
//
// Guard order:
//   a. Already Scared?  → silent End
//   b. Wonder Guard?    → "It doesn't affect X!" + MOVE_STATUS_NO_MORE_WORK → End
//   c. InflictCondition3
//   d. Print "{X} became Scared!" (message 1728)

_000:
    GotoIfHasCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_SCARED, _End
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_WONDER_GUARD, _WonderGuard
    InflictCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_SCARED
    // {0} became Scared!
    PrintMessage 1728, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    WaitButtonABTime 30
    End

_WonderGuard:
    // It doesn't affect {0}...
    PrintMessage 27, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
    Wait
    WaitButtonABTime 30
    UpdateVar OPCODE_FLAG_ON, BSCRIPT_VAR_MOVE_STATUS_FLAGS, MOVE_STATUS_NO_MORE_WORK

_End:
    End
