#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h> 
#include "../../Framework/Memory/mem.h"
#include "../../Framework/Game/game.h"
namespace ph
{
	struct Info
	{
	public:
		DWORD64 dw_base;
		DWORD64 dw_world;
		DWORD64 dw_crosshairid;
		DWORD64 dw_waypoint_x;
		DWORD64 dw_waypoint_y;

		DWORD64 dw_player;
		DWORD64 dw_player_freeze;
		DWORD64 dw_player_position;
		DWORD64 dw_player_info;
		DWORD64 dw_player_info_nearestvehicle;
		DWORD64 dw_player_info_nearestvehicle_handling;
		DWORD64 dw_player_info_nearestvehicle_position;
		DWORD64 dw_player_vehicle;
		DWORD64 dw_player_vehicle_handling;
		DWORD64 dw_player_vehicle_position;
		DWORD64 dw_player_weapon;
		DWORD64 dw_player_weapon_ammo;


		void init(const char* gameName);
	};
	extern Info info;
}