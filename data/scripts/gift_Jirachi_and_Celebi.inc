MysteryGift_EventScript_Celebi::
	bufferspeciesname STR_VAR_1, SPECIES_CELEBI
	msgbox MysteryGift_Text_GiftMonForYou, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CELEBI
	givemon SPECIES_CELEBI, 10, ,ITEM_CHERISH_BALL
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MysteryGift_EventScript_NicknamePartyMon
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MysteryGift_EventScript_NicknamePCMon
	goto Common_EventScript_NoMoreRoomForPokemon
	call MysteryGift_EventScript_ReceivedMon
	setflag FLAG_MYSTERY_GIFT_CELEBI
	releaseall
	end

MysteryGift_EventScript_Jirachi::
	bufferspeciesname STR_VAR_1, SPECIES_JIRACHI
	msgbox MysteryGift_Text_GiftMonForYou, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_JIRACHI
	givemon SPECIES_JIRACHI, 5, ITEM_SALAC_BERRY, ITEM_CHERISH_BALL, , 0, MON_GENDERLESS, 0, , , , , , , , , , , , MOVE_WISH, MOVE_CONFUSION, MOVE_REST
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MysteryGift_EventScript_NicknamePartyMon
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MysteryGift_EventScript_NicknamePCMon
	goto Common_EventScript_NoMoreRoomForPokemon
	setflag FLAG_MYSTERY_GIFT_JIRACHI
	call MysteryGift_EventScript_ReceivedMon
	releaseall
	end

MysteryGift_EventScript_ReceivedMon::
	playfanfare MUS_OBTAIN_ITEM
	message MysteryGift_Text_ReceivedGiftMon
	waitfanfare
	end

MysteryGift_EventScript_NicknamePartyMon::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MysteryGift_EventScript_Exit
	call Common_EventScript_GetGiftMonPartySlot 
	call Common_EventScript_NameReceivedPartyMon 
	goto MysteryGift_EventScript_Exit
	end

MysteryGift_EventScript_NicknamePCMon::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO 
	goto_if_eq VAR_RESULT, NO, MysteryGift_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	call Common_EventScript_TransferredToPC
	releaseall
	end

MysteryGift_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	releaseall
	end
MysteryGift_EventScript_Exit:
	msgbox MysteryGift_Text_ThankYou, MSGBOX_DEFAULT
	release
	end

MysteryGift_Text_GiftMonForYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.\p"
	.string "Let me confirm, are you {PLAYER}?\p"
	.string "We received this {STR_VAR_1}\n"
	.string "addressed to you.$"

MysteryGift_Text_ReceivedGiftMon:
	.string "{PLAYER} received a {STR_VAR_1}!$"

MysteryGift_Text_ThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"
