// Test: Full Heal clears STATUS2_BRITTLE (condition2).

#ifndef GET_TEST_CASE_ONLY

#include "../../../../include/battle.h"
#include "../../../../include/constants/ability.h"
#include "../../../../include/constants/item.h"
#include "../../../../include/constants/moves.h"
#include "../../../../include/constants/species.h"
#include "../../../../include/test_battle.h"

const struct TestBattleScenario BattleTests[] = {

#endif

    {
        .battleType     = BATTLE_TYPE_SINGLE,
        .weather        = WEATHER_NONE,
        .fieldCondition = 0,
        .terrain        = TERRAIN_NONE,

        .playerParty = {
            {
                .species   = SPECIES_WOOPER,
                .level     = 50,
                .form      = 0,
                .ability   = ABILITY_WATER_ABSORB,
                .item      = ITEM_FULL_HEAL,
                .moves     = { MOVE_TACKLE, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = STATUS2_BRITTLE,
                .condition3 = 0,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .fatigue_turns   = 0,
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
                .moves     = { MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp        = FULL_HP,
                .status    = 0,
                .condition2 = 0,
                .condition3 = 0,
                .winded_turns    = 0,
                .awestruck_turns = 0,
                .migraine_turns  = 0,
                .idolize_turns   = 0,
                .fatigue_turns   = 0,
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

        // Proxy for STATUS2_BRITTLE cleared — no EXPECTATION_TYPE_CONDITION2_FLAG_CLEAR exists yet.
        .expectations = {
            {
                .expectationType = EXPECTATION_TYPE_MESSAGE_CONTAINS,
                .expectationValue.message = "is no longer Brittle!",
            },
        },

        .expectationPassCount = 0,
        .knownFailing = 0,
    },

#ifndef GET_TEST_CASE_ONLY
};
#endif
