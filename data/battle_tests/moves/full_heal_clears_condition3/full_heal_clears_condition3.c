// Test: Full Heal item clears condition3 (custom volatile status) on the target battler
//
// Validates that using a Full Heal (or Full Restore) during battle correctly clears
// condition3 flags and associated turn counters via ClearCondition3 (opcode 0x116),
// which was wired into subscript_0268_USE_STATUS_RECOVERY and
// subscript_0289_USE_FULL_RESTORE.
//
// This test now uses ACTION_USE_ITEM and EXPECTATION_TYPE_CONDITION3_CLEAR directly.
// It should fail if Full Heal/Full Restore ever stop clearing condition3.

#ifndef GET_TEST_CASE_ONLY

#include "../../../../include/battle.h"
#include "../../../../include/constants/ability.h"
#include "../../../../include/constants/item.h"
#include "../../../../include/constants/moves.h"
#include "../../../../include/constants/species.h"
#include "../../../../include/test_battle.h"
#include "../../../../include/constants/battle_message_constants.h"

const struct TestBattleScenario BattleTests[] = {

#endif

    {
        .battleType    = BATTLE_TYPE_SINGLE,
        .weather       = WEATHER_NONE,
        .fieldCondition = 0,
        .terrain       = TERRAIN_NONE,

        .playerParty = {
            {
                .species   = SPECIES_WOOPER,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_WATER_ABSORB,
                .item      = ITEM_FULL_HEAL,    // item the trainer will use
                .moves     = { MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = 0,
                // Pre-seed condition3 so the test starts with the status active.
                .condition3 = CONDITION3_DRENCHED,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
        },

        .enemyParty = {
            {
                .species   = SPECIES_WOOPER,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_WATER_ABSORB,
                .item      = ITEM_NONE,
                .moves     = { MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = 0,
                .condition3 = 0,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
        },
        .playerScript = {
            {
                { ACTION_USE_ITEM, BATTLER_PLAYER_FIRST },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
            {
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
        },

        .enemyScript = {
            {
                { ACTION_MOVE_SLOT_1, BATTLER_PLAYER_FIRST },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
            {
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
                { ACTION_NONE, 0 },
            },
        },

        .expectations = {
            {
                .expectationType = EXPECTATION_TYPE_CONDITION3_CLEAR,
                .battlerIDOrPartySlot = BATTLER_PLAYER_FIRST,
            },
        },

        .expectationPassCount = 0,
        .knownFailing = 0,
    },

#ifndef GET_TEST_CASE_ONLY
};
#endif
