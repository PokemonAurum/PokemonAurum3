.include "asm/include/battle_commands.inc"

.data

// Inflict the Fatigue condition3 status on BATTLER_CATEGORY_SIDE_EFFECT_MON.
//
// Order of checks:
//   a. Already Fatigued?  → silent End (exclusive status, can't stack)
//   b. Wonder Guard?      → "It doesn't affect X!" + MOVE_STATUS_NO_MORE_WORK → End
//   c. Apply flag + counter (3 turns via CONDITION3_CTR_FATIGUE)
//   d. Print "{X} became Fatigued!" (message 1716)
//
// Note: GotoIfHasCondition3 (opcode 290) is used instead of
// CompareMonDataToValue BMON_DATA_CONDITION3 because BattlePokemonParamGet is a
// ROM function that cannot access the new condition3 field.

_000:
    // a. Already Fatigued — silent exit, exclusive status can't stack.
    GotoIfHasCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_FATIGUE, _End
    // b. Wonder Guard blocks all condition3 infliction.
    CheckIgnorableAbility CHECK_OPCODE_HAVE, BATTLER_CATEGORY_SIDE_EFFECT_MON, ABILITY_WONDER_GUARD, _WonderGuard
    // c. Apply the Fatigue flag and 3-turn counter.
    InflictCondition3 BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_FATIGUE
    SetCondition3Counter BATTLER_CATEGORY_SIDE_EFFECT_MON, CONDITION3_CTR_FATIGUE, 3
    // d. {0} became Fatigued!
    PrintMessage 1716, TAG_NICKNAME, BATTLER_CATEGORY_SIDE_EFFECT_MON
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
