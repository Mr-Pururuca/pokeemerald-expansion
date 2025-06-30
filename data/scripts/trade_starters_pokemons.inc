Torchic_Starter_Trade::
	goto_if_set FLAG_TORCHIC_NPC_TRADE_COMPLETED, Starter_Trade_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_TORCHIC
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Starter_Trade_Text_WannaTradeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Starter_Trade_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Starter_Trade_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Starter_Trade_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Starter_Trade_Text_TakeMon, MSGBOX_DEFAULT
	setflag FLAG_TORCHIC_NPC_TRADE_COMPLETED
	release
	end

Treecko_Starter_Trade::
	goto_if_set FLAG_TREECKO_NPC_TRADE_COMPLETED, Starter_Trade_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_TREECKO
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Starter_Trade_Text_WannaTradeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Starter_Trade_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Starter_Trade_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Starter_Trade_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Starter_Trade_Text_TakeMon, MSGBOX_DEFAULT
	setflag FLAG_TREECKO_NPC_TRADE_COMPLETED
	release
	end

Mudkip_Starter_Trade::
	goto_if_set FLAG_MUDKIP_NPC_TRADE_COMPLETED, Starter_Trade_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MUDKIP
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Starter_Trade_Text_WannaTradeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Starter_Trade_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Starter_Trade_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Starter_Trade_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Starter_Trade_Text_TakeMon, MSGBOX_DEFAULT
	setflag FLAG_MUDKIP_NPC_TRADE_COMPLETED
	release
	end

Starter_Trade_EventScript_DeclineTrade::
	msgbox Starter_Trade_Text_WontTradeMon, MSGBOX_DEFAULT
	release
	end

Starter_Trade_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Starter_Trade_Text_NotTheMon, MSGBOX_DEFAULT
	release
	end

Starter_Trade_EventScript_TradeCompleted::
	msgbox Starter_Trade_Text_TradedMon, MSGBOX_DEFAULT
	release
	end

Starter_Trade_Text_WannaTradeMon:
	.string "Oh, hello little fella!\n"
	.string "I got my hands on this super rare\p"
	.string "{STR_VAR_2}. But if you really want,\n"
	.string "I'm willing to trade it to you.\p"
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

Starter_Trade_Text_TakeMon:
	.string "Oh, yeah, right on!\p"
	.string "{STR_VAR_1}, you take care!$"

Starter_Trade_Text_NotTheMon:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

Starter_Trade_Text_WontTradeMon:
	.string "Oh, if you don't want to, that's okay.\n"
	.string "But my POKéMON is cute, you know…$"

Starter_Trade_Text_TradedMon:
	.string "I know I could go looking for one\n"
	.string "on my own, but…\p"
	.string "But I wanted to get a {STR_VAR_1}\n"
	.string "that another TRAINER caught…$"
