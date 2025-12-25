#include "global.h"
#include "palette.h"
#include "field_control_avatar.h"
#include "event_scripts.h"
#include "field_screen_effect.h"
#include "field_player_avatar.h"
#include "fldeff_misc.h"
#include "item.h"
#include "field_control_avatar.h"
#include "map_name_popup.h"
#include "constants/items.h"
#include "fldeff.h"
#include "overworld.h"
#include "region_map.h"
#include "item_use.h"
#include "item.h"
#include "constants/items.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "party_menu.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "event_data.h"
#include "qol_field_moves.h"
#include "constants/songs.h"
#include "sound.h"
#include "script.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "field_weather.h"
#include "constants/field_effects.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "item_menu.h"
#include "constants/map_types.h"
#include "constants/party_menu.h"

//static void LockPlayerAndLoadMon(void);

//static void SetUpFieldMove_UseFlash(u32);
//static void UseFlash(u32 fieldMoveStatus);
//static void FieldCallback_UseFlashMove(void);

//static bool8 IsPlayerFacingWaterfall(void);

//static bool32 PartyCanLearnMoveLevelUp(u16, u16);
//static bool32 SetMonResultVariables(u32 partyIndex, u32 species);

#define tState      data[0]
#define tFallOffset data[1]
#define tTotalFall  data[2]

static bool32 PartyCanLearnMoveLevelUp(u16 species, u16 moveId)
{
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    for (u32 i = 0; learnset[i].move != LEVEL_UP_MOVE_END;i++)
    {
        if ((learnset[i].move & LEVEL_UP_MOVE_ID) == moveId)
            return TRUE;
    }
    return FALSE;
}

bool32 PartyHasMonCanLearnFieldMove(u16 moveId)
{
    u32 species, i;
    gSpecialVar_Result = PARTY_SIZE;
    gSpecialVar_0x8004 = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&gPlayerParty[i],MON_DATA_SPECIES,NULL);

        if (species == SPECIES_NONE)
            break;

        if (PartyCanLearnMoveLevelUp(species, moveId)|| CanLearnTeachableMove(species,moveId)){
            gSpecialVar_Result = i;
            gSpecialVar_0x8004 = species;
            return TRUE;
        }
    }
    return FALSE;
}

/*static bool32 SetMonResultVariables(u32 partyIndex, u32 species)
{
    gSpecialVar_Result = partyIndex;
    gSpecialVar_0x8004 = species;
    return TRUE;
}*/
