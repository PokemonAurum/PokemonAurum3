.include "asm/include/battle_commands.inc"

.data

// Inflict the Brittle volatile status on BATTLER_CATEGORY_SIDE_EFFECT_MON.
// Stored in condition2 (STATUS2_BRITTLE bit 14), not condition3.
// CompareMonDataToValue BMON_DATA_STATUS2 works here — ROM function handles it.
//
// Guard order:
//   a. Already Brittle?  → silent End
//   b. Wonder Guard?     → "It doesn't affect X!" + MOVE_STATUS_NO_MORE_WORK → End
//   c. UpdateMonData to set STATUS2_BRITTLE
//   d. Print "{X} became Brittle!" (message 1734)

_000:
    CompareMonDataToValue OPCODE_FLAG_SET, BATTLER_CATEGORY_SIDE_EFFECT_MON, BMON_DATA_STATUS2, STATUS2_BRITTLE, _End
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_WONDER_GUARD, _WonderGuard
    UpdateMonData OPCODE_FLAG_ON, BATTLER_CATEGORY_SIDE_EFFECT_MON, BMON_DATA_STATUS2, STATUS2_BRITTLE
    // {0} became Brittle!
    PrintMessage 1734, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
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
