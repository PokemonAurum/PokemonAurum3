// Test: Solar Power drains 1/16 HP in sun each end-of-turn
#ifndef GET_TEST_CASE_ONLY

#include "../../../../include/battle.h"
#include "../../../../include/constants/ability.h"
#include "../../../../include/constants/battle_message_constants.h"
#include "../../../../include/constants/item.h"
#include "../../../../include/constants/moves.h"
#include "../../../../include/constants/species.h"
#include "../../../../include/test_battle.h"

const struct TestBattleScenario BattleTests[] = {

#endif

    {
        .battleType = BATTLE_TYPE_SINGLE,
        .weather = WEATHER_SUNNY,
        .fieldCondition = 0,
        .terrain = TERRAIN_NONE,
        .playerParty = {
            {
                .species = SPECIES_CHARIZARD,
                .level = 50,
                .form = 0,
                .ability = ABILITY_SOLAR_POWER,
                .item = ITEM_NONE,
                .moves = { MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                .hp = FULL_HP,
                .status = 0,
                .condition2 = 0,
                .moveEffectFlags = 0,
            },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE } },
        .enemyParty = { {
                            .species = SPECIES_CATERPIE,
                            .level = 50,
                            .form = 0,
                            .ability = ABILITY_SHIELD_DUST,
                            .item = ITEM_NONE,
                            .moves = { MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE },
                            .hp = FULL_HP,
                            .status = 0,
                            .condition2 = 0,
                            .moveEffectFlags = 0,
                        },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE },
            { .species = SPECIES_NONE } },
        .playerScript = { {
                              { ACTION_MOVE_SLOT_1, BATTLER_ENEMY_FIRST },
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
            } },
        .enemyScript = { {
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
            } },
        .expectations = {
            // 1097: "{STRVAR_1 1, 0, 0} lost some HP because of its {STRVAR_1 5, 1, 0}!" (player pokemon)
            { .expectationType = EXPECTATION_TYPE_MESSAGE, .expectationValue.messageID = 1097 },
        }
    },
#ifndef GET_TEST_CASE_ONLY
};
#endif
