#include "info.h"
namespace ph
{
	void info::Init(const char* gameName)
	{
		while (ph::mem.get_process(gameName) == 0)
		{
			Sleep(100);
		}

		Base = ph::mem.get_module(gameName);

		while (World == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(Base + ph::Offsets::ptrWorld), &World, sizeof(DWORD64), NULL);
		}

		while (CrosshairId == NULL)
		{
			CrosshairId = Base + ph::Offsets::ptrCrosshair;
		}

		while (PlayerFreeze == NULL)
		{
			PlayerFreeze = Base + ph::Offsets::opFreeze;
		}

		while (WaypointX == NULL && WaypointY == NULL)
		{
			WaypointX = Base + ph::Offsets::ptrWaypointX;
			WaypointY = Base + ph::Offsets::ptrWaypointY;
		}

		while (Player == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(World + ph::Offsets::Player), &Player, sizeof(DWORD64), NULL);
		}

		while (Player_Info == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(Player + ph::Offsets::Player_Info), &Player_Info, sizeof(DWORD64), NULL);
		}

		while (Player_Position == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(Player + ph::Offsets::Player_Pos), &Player_Position, sizeof(DWORD64), NULL);
		}
	}

	info Info;
}
