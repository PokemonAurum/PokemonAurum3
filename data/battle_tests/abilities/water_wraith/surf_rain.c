// Test: Water Wraith boosts Water/Electric/Poison moves 1.3x in rain (stacks with rain 1.5x)
// Porygon-Z lv100 SpAtk=306 (Normal, no STAB), Surf 90->117 (1.3x) then rain 1.5x, vs Blissey lv100 SpDef=306
// base_damage = floor(floor(42*117*306/306)/50)+2 = 100; rain 1.5x = 150; neutral type => range 127-150
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
        .weather = WEATHER_RAIN,
        .fieldCondition = 0,
        .terrain = TERRAIN_NONE,
        .playerParty = {
            {
                .species = SPECIES_PORYGON_Z,
                .level = 100,
                .form = 0,
                .ability = ABILITY_WATER_WRAITH,
                .item = ITEM_NONE,
                .moves = { MOVE_SURF, MOVE_NONE, MOVE_NONE, MOVE_NONE },
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
                            .species = SPECIES_BLISSEY,
                            .level = 100,
                            .form = 0,
                            .ability = ABILITY_NATURAL_CURE,
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
            { .expectationType = EXPECTATION_TYPE_HP_BAR, .battlerIDOrPartySlot = BATTLER_ENEMY_FIRST, .expectationValue.hpTaken = { 127, 129, 130, 132, 133, 135, 136, 138, 139, 141, 142, 144, 145, 147, 148, 150 } },
        }
    },
#ifndef GET_TEST_CASE_ONLY
};
#endif
