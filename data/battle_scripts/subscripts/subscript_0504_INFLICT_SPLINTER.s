.include "asm/include/battle_commands.inc"

.data

// Inflict the Splinter volatile status on BATTLER_CATEGORY_SIDE_EFFECT_MON.
// Rock/Steel-type. Stored in condition2 (STATUS2_SPLINTER bit 13), not condition3.
// CompareMonDataToValue BMON_DATA_STATUS2 works here — ROM function handles it.
//
// Guard order:
//   a. Already has Splinter?  → silent End
//   b. Wonder Guard?          → "It doesn't affect X!" + MOVE_STATUS_NO_MORE_WORK → End
//   c. UpdateMonData to set STATUS2_SPLINTER
//   d. Print "{X} got Splinters!" (message 1731)

_000:
    CompareMonDataToValue OPCODE_FLAG_SET, BATTLER_CATEGORY_SIDE_EFFECT_MON, BMON_DATA_STATUS2, STATUS2_SPLINTER, _End
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_WONDER_GUARD, _WonderGuard
    UpdateMonData OPCODE_FLAG_ON, BATTLER_CATEGORY_SIDE_EFFECT_MON, BMON_DATA_STATUS2, STATUS2_SPLINTER
    // {0} got Splinters!
    PrintMessage 1731, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
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
