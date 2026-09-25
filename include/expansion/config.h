#ifndef POKEPLATINUM_EXPANSION_CONFIG_H
#define POKEPLATINUM_EXPANSION_CONFIG_H

/*
 * pokeplatinum-expansion configuration
 *
 * Keep expansion behavior opt-in while the framework is being built.
 * Defaults should preserve vanilla Platinum semantics unless a feature
 * explicitly documents otherwise.
 */

#define PEX_GENERATION_PLATINUM 4
#define PEX_GENERATION_LATEST   9

#ifndef PEX_TARGET_GENERATION
#define PEX_TARGET_GENERATION PEX_GENERATION_PLATINUM
#endif

#ifndef PEX_FEATURE_FAIRY_TYPE
#define PEX_FEATURE_FAIRY_TYPE 0
#endif

#ifndef PEX_FEATURE_MODERN_TYPE_CHART
#define PEX_FEATURE_MODERN_TYPE_CHART 0
#endif

#ifndef PEX_FEATURE_MODERN_BATTLE_MECHANICS
#define PEX_FEATURE_MODERN_BATTLE_MECHANICS 0
#endif

#ifndef PEX_FEATURE_HIDDEN_ABILITIES
#define PEX_FEATURE_HIDDEN_ABILITIES 0
#endif

#ifndef PEX_FEATURE_REUSABLE_TMS
#define PEX_FEATURE_REUSABLE_TMS 0
#endif

#ifndef PEX_FEATURE_MODERN_EXP_SHARE
#define PEX_FEATURE_MODERN_EXP_SHARE 0
#endif

/*
 * These are intentionally disabled and should remain independent switches.
 * A downstream hack may want modern species/moves without every battle gimmick.
 */
#ifndef PEX_FEATURE_MEGA_EVOLUTION
#define PEX_FEATURE_MEGA_EVOLUTION 0
#endif

#ifndef PEX_FEATURE_Z_MOVES
#define PEX_FEATURE_Z_MOVES 0
#endif

#ifndef PEX_FEATURE_DYNAMAX
#define PEX_FEATURE_DYNAMAX 0
#endif

#ifndef PEX_FEATURE_TERASTALLIZATION
#define PEX_FEATURE_TERASTALLIZATION 0
#endif

#endif // POKEPLATINUM_EXPANSION_CONFIG_H
