.include "asm/include/battle_commands.inc"

.data

// Inflict the Migraine condition3 status on BATTLER_CATEGORY_SIDE_EFFECT_MON.
// Psychic-type, exclusive, 4 turns (migraine_turns stored as 1-4 direct value).
//
// Guard order:
//   a. Already has Migraine?  → silent End
//   b. Wonder Guard?          → "It doesn't affect X!" + MOVE_STATUS_NO_MORE_WORK → End
//   c. InflictCondition3 + SetCondition3Counter (4 turns)
//   d. Print "{X} developed a Migraine!" (message 1719)

_000:
    GotoIfHasCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_MIGRAINE, _End
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_WONDER_GUARD, _WonderGuard
    InflictCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_MIGRAINE
    SetCondition3Counter BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_CTR_MIGRAINE, 4
    // {0} developed a Migraine!
    PrintMessage 1719, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
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
