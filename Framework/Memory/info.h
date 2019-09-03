#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h> 
#include "../../Framework/Memory/mem.h"
#include "../../Framework/Game/game.h"
namespace ph
{
	struct info
	{
	public:
		DWORD64 Base;
		DWORD64 World;
		DWORD64 CrosshairId;
		DWORD64 WaypointX;
		DWORD64 WaypointY;

		DWORD64 Player;
		DWORD64 PlayerFreeze;
		DWORD64 Player_Position;
		DWORD64 Player_Info;
		DWORD64 Player_Info_NearestvVehicle;
		DWORD64 Player_Info_NearestVehicle_Handling;
		DWORD64 Player_Info_NearestVehicle_Position;
		DWORD64 Player_Vehicle;
		DWORD64 Player_Vehicle_Handling;
		DWORD64 Player_Vehicle_Position;
		DWORD64 Player_WeaponInfo;
		DWORD64 Player_WeaponInfo_Ammoinfo;

		void Init(const char* gameName);
	};
	extern info Info;
}
