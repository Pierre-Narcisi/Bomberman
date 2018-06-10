/*
** EPITECH PROJECT, 2017
** Client
** File description:
** Settings.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

#include <string>
#include <unordered_map>
#include <array>

#include "ECS/Entity/Entity.hpp"
#include "Json/Entity.hpp"

/* implemented by benjamin */
json::Entity getSettings();
json::Entity saveSettings();

namespace ecs {

	namespace system {

		class InitInputs {
		public:
			void CreateInputsForPlayer(entity::Id id, std::string const &player);
		};

	}

	struct KeyRef {
		std::string str;
		irr::EKEY_CODE code;
	};

	static const std::array<std::pair<std::string, irr::EKEY_CODE>, 152> keyRef_g = {
		std::make_pair("MOUSE:LEFT", irr::KEY_LBUTTON),
		std::make_pair("MOUSE:RIGHT", irr::KEY_RBUTTON),
		std::make_pair("MOUSE:MIDDLE", irr::KEY_MBUTTON),
		std::make_pair("MOUSE:X1", irr::KEY_XBUTTON1),
		std::make_pair("MOUSE:X2", irr::KEY_XBUTTON2),
		std::make_pair("BACKSPACE", irr::KEY_BACK),
		std::make_pair("TAB", irr::KEY_TAB),
		std::make_pair("CLEAR", irr::KEY_CLEAR),
		std::make_pair("ENTER", irr::KEY_RETURN),
		std::make_pair("SHIFT", irr::KEY_SHIFT),
		std::make_pair("CTRL", irr::KEY_CONTROL),
		std::make_pair("ALT", irr::KEY_MENU),
		std::make_pair("PAUSE", irr::KEY_PAUSE),
		std::make_pair("CAPS", irr::KEY_CAPITAL),
		std::make_pair("", irr::KEY_KANA),  // IME Kana mode
		std::make_pair("", irr::KEY_HANGUEL),  // IME Hanguel mode (maintained for compatibility use KEY_HANGUL)
		std::make_pair("", irr::KEY_HANGUL),  // IME Hangul mode
		std::make_pair("", irr::KEY_JUNJA),  // IME Junja mode
		std::make_pair("", irr::KEY_FINAL),  // IME final mode
		std::make_pair("", irr::KEY_HANJA),  // IME Hanja mode
		std::make_pair("", irr::KEY_KANJI),  // IME Kanji mode
		std::make_pair("ESCAPE", irr::KEY_ESCAPE),
		std::make_pair("", irr::KEY_CONVERT),  // IME convert
		std::make_pair("", irr::KEY_NONCONVERT),  // IME nonconvert
		std::make_pair("", irr::KEY_ACCEPT),  // IME accept
		std::make_pair("", irr::KEY_MODECHANGE),  // IME mode change request
		std::make_pair("SPACE", irr::KEY_SPACE),
		std::make_pair("PAGE_UP", irr::KEY_PRIOR),
		std::make_pair("PAGE_DOWN", irr::KEY_NEXT),
		std::make_pair("END", irr::KEY_END),
		std::make_pair("HOME", irr::KEY_HOME),
		std::make_pair("LEFT", irr::KEY_LEFT),
		std::make_pair("UP", irr::KEY_UP),
		std::make_pair("RIGHT", irr::KEY_RIGHT),
		std::make_pair("DOWN", irr::KEY_DOWN),
		std::make_pair("SELECT", irr::KEY_SELECT),
		std::make_pair("PRINT", irr::KEY_PRINT),
		std::make_pair("EXECUTE", irr::KEY_EXECUT),
		std::make_pair("PRINT_SCREEN", irr::KEY_SNAPSHOT),
		std::make_pair("INS", irr::KEY_INSERT),
		std::make_pair("DEL", irr::KEY_DELETE),
		std::make_pair("HELP", irr::KEY_HELP),
		std::make_pair("0", irr::KEY_KEY_0),
		std::make_pair("1", irr::KEY_KEY_1),
		std::make_pair("2", irr::KEY_KEY_2),
		std::make_pair("3", irr::KEY_KEY_3),
		std::make_pair("4", irr::KEY_KEY_4),
		std::make_pair("5", irr::KEY_KEY_5),
		std::make_pair("6", irr::KEY_KEY_6),
		std::make_pair("7", irr::KEY_KEY_7),
		std::make_pair("8", irr::KEY_KEY_8),
		std::make_pair("9", irr::KEY_KEY_9),
		std::make_pair("A", irr::KEY_KEY_A),
		std::make_pair("B", irr::KEY_KEY_B),
		std::make_pair("C", irr::KEY_KEY_C),
		std::make_pair("D", irr::KEY_KEY_D),
		std::make_pair("E", irr::KEY_KEY_E),
		std::make_pair("F", irr::KEY_KEY_F),
		std::make_pair("G", irr::KEY_KEY_G),
		std::make_pair("H", irr::KEY_KEY_H),
		std::make_pair("I", irr::KEY_KEY_I),
		std::make_pair("J", irr::KEY_KEY_J),
		std::make_pair("K", irr::KEY_KEY_K),
		std::make_pair("L", irr::KEY_KEY_L),
		std::make_pair("M", irr::KEY_KEY_M),
		std::make_pair("N", irr::KEY_KEY_N),
		std::make_pair("O", irr::KEY_KEY_O),
		std::make_pair("P", irr::KEY_KEY_P),
		std::make_pair("Q", irr::KEY_KEY_Q),
		std::make_pair("R", irr::KEY_KEY_R),
		std::make_pair("S", irr::KEY_KEY_S),
		std::make_pair("T", irr::KEY_KEY_T),
		std::make_pair("U", irr::KEY_KEY_U),
		std::make_pair("V", irr::KEY_KEY_V),
		std::make_pair("W", irr::KEY_KEY_W),
		std::make_pair("X", irr::KEY_KEY_X),
		std::make_pair("Y", irr::KEY_KEY_Y),
		std::make_pair("Z", irr::KEY_KEY_Z),
		std::make_pair("", irr::KEY_LWIN),  // Left Windows key (Microsoft Natural keyboard)
		std::make_pair("", irr::KEY_RWIN),  // Right Windows key (Natural keyboard)
		std::make_pair("", irr::KEY_APPS),  // Applications key (Natural keyboard)
		std::make_pair("", irr::KEY_SLEEP),  // Computer Sleep key
		std::make_pair("NUMPAD:0", irr::KEY_NUMPAD0),
		std::make_pair("NUMPAD:1", irr::KEY_NUMPAD1),
		std::make_pair("NUMPAD:2", irr::KEY_NUMPAD2),
		std::make_pair("NUMPAD:3", irr::KEY_NUMPAD3),
		std::make_pair("NUMPAD:4", irr::KEY_NUMPAD4),
		std::make_pair("NUMPAD:5", irr::KEY_NUMPAD5),
		std::make_pair("NUMPAD:6", irr::KEY_NUMPAD6),
		std::make_pair("NUMPAD:7", irr::KEY_NUMPAD7),
		std::make_pair("NUMPAD:8", irr::KEY_NUMPAD8),
		std::make_pair("NUMPAD:9", irr::KEY_NUMPAD9),
		std::make_pair("", irr::KEY_MULTIPLY),  // Multiply key
		std::make_pair("", irr::KEY_ADD),  // Add key
		std::make_pair("", irr::KEY_SEPARATOR),  // Separator key
		std::make_pair("", irr::KEY_SUBTRACT),  // Subtract key
		std::make_pair("", irr::KEY_DECIMAL),  // Decimal key
		std::make_pair("", irr::KEY_DIVIDE),  // Divide key
		std::make_pair("F1", irr::KEY_F1),
		std::make_pair("F2", irr::KEY_F2),
		std::make_pair("F3", irr::KEY_F3),
		std::make_pair("F4", irr::KEY_F4),
		std::make_pair("F5", irr::KEY_F5),
		std::make_pair("F6", irr::KEY_F6),
		std::make_pair("F7", irr::KEY_F7),
		std::make_pair("F8", irr::KEY_F8),
		std::make_pair("F9", irr::KEY_F9),
		std::make_pair("F10", irr::KEY_F10),
		std::make_pair("F11", irr::KEY_F11),
		std::make_pair("F12", irr::KEY_F12),
		std::make_pair("F13", irr::KEY_F13),
		std::make_pair("F14", irr::KEY_F14),
		std::make_pair("F15", irr::KEY_F15),
		std::make_pair("F16", irr::KEY_F16),
		std::make_pair("F17", irr::KEY_F17),
		std::make_pair("F18", irr::KEY_F18),
		std::make_pair("F19", irr::KEY_F19),
		std::make_pair("F20", irr::KEY_F20),
		std::make_pair("F21", irr::KEY_F21),
		std::make_pair("F22", irr::KEY_F22),
		std::make_pair("F23", irr::KEY_F23),
		std::make_pair("F24", irr::KEY_F24),
		std::make_pair("NUM_LOCK", irr::KEY_NUMLOCK),
		std::make_pair("SCROLL_LOCK", irr::KEY_SCROLL),
		std::make_pair("LSHIFT", irr::KEY_LSHIFT),
		std::make_pair("RSHIFT", irr::KEY_RSHIFT),
		std::make_pair("LCONTROL", irr::KEY_LCONTROL),
		std::make_pair("RCONTROL", irr::KEY_RCONTROL),
		std::make_pair("LMENU", irr::KEY_LMENU),
		std::make_pair("RMENU", irr::KEY_RMENU),
		std::make_pair("", irr::KEY_OEM_1),  // for US    ";:"
		std::make_pair("+", irr::KEY_PLUS),
		std::make_pair(",", irr::KEY_COMMA),
		std::make_pair("-", irr::KEY_MINUS),
		std::make_pair(".", irr::KEY_PERIOD),
		std::make_pair("", irr::KEY_OEM_2),  // for US    "/?"
		std::make_pair("", irr::KEY_OEM_3),  // for US    "`~"
		std::make_pair("", irr::KEY_OEM_4),  // for US    "[{"
		std::make_pair("", irr::KEY_OEM_5),  // for US    "\|"
		std::make_pair("", irr::KEY_OEM_6),  // for US    "]}"
		std::make_pair("", irr::KEY_OEM_7),  // for US    "'""
		std::make_pair("", irr::KEY_OEM_8),  // None
		std::make_pair("", irr::KEY_OEM_AX),  // for Japan "AX"
		std::make_pair("", irr::KEY_OEM_102),  // "<>" or "\|"
		std::make_pair("", irr::KEY_ATTN),  // Attn key
		std::make_pair("", irr::KEY_CRSEL),  // CrSel key
		std::make_pair("", irr::KEY_EXSEL),  // ExSel key
		std::make_pair("", irr::KEY_EREOF),  // Erase EOF key
		std::make_pair("PLAY", irr::KEY_PLAY),
		std::make_pair("ZOOM", irr::KEY_ZOOM),
		std::make_pair("", irr::KEY_PA1),  // PA1 key
		std::make_pair("", irr::KEY_OEM_CLEAR)
	};

}

/*
settings file :

{
	"settings": {
		"inputs": {
			"player1": {
				"up": "Z",
				"down": "S",
				"right": "D",
				"left": "Q",
				"fire": "SPACE",
				"event": "E"
			},
			"player2": {
				"up": "UP",
				"down": "DOWN",
				"right": "RIGHT",
				"left": "LEFT",
				"fire": "M",
				"event": "L"
			}
		}
	}
}
*/