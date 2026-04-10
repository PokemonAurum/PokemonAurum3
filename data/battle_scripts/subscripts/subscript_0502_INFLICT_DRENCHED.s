.include "asm/include/battle_commands.inc"

.data

// Inflict the Drenched condition3 status on BATTLER_CATEGORY_SIDE_EFFECT_MON.
// Water-type, exclusive, permanent (no turn counter — flag only).
//
// Guard order:
//   a. Already Drenched?  → silent End
//   b. Wonder Guard?      → "It doesn't affect X!" + MOVE_STATUS_NO_MORE_WORK → End
//   c. InflictCondition3
//   d. Print "{X} became Drenched!" (message 1725)

_000:
    GotoIfHasCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_DRENCHED, _End
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_WONDER_GUARD, _WonderGuard
    InflictCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_DRENCHED
    // {0} became Drenched!
    PrintMessage 1725, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
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
