#include "info.h"
namespace ph
{
	void Info::init(const char * gameName)
	{
		while (ph::mem.get_process(gameName) == 0)
		{
			Sleep(100);
		}

		dw_base = ph::mem.get_module(gameName);

		while (dw_world == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(dw_base + ph::off::ptr_world), &dw_world, sizeof(DWORD64), NULL);
		}

		while (dw_crosshairid == NULL)
		{
			dw_crosshairid = dw_base + ph::off::ptr_crosshair;
		}

		while (dw_player_freeze == NULL)
		{
			dw_player_freeze = dw_base + ph::off::op_freeze_player;
		}

		while (dw_waypoint_x == NULL && dw_waypoint_y == NULL)
		{
			dw_waypoint_x = dw_base + ph::off::ptr_waypoint_x;
			dw_waypoint_y = dw_base + ph::off::ptr_waypoint_y;
		}

		while (dw_player == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(dw_world + ph::off::off_player), &dw_player, sizeof(DWORD64), NULL);
		}

		while (dw_player_info == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(dw_player + ph::off::off_player_info), &dw_player_info, sizeof(DWORD64), NULL);
		}

		while (dw_player_position == NULL)
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(dw_player + ph::off::off_player_pos), &dw_player_position, sizeof(DWORD64), NULL);
		}
	}

	Info info;
}