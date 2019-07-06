#include "game.h"

namespace ph
{
	namespace off
	{
		DWORD64 ptr_world = 0x024839C8;
		DWORD64 ptr_nearest_ped = 0x2488030;
		DWORD64 ptr_waypoint_x = 0x2080388;
		DWORD64 ptr_waypoint_y = 0x208038C;
		DWORD64 ptr_crosshair = 0x2080080;

		//OpCodes
		DWORD64 op_freeze_player = 0x1407F93;

		//player
		DWORD64 off_player = 0x8;
		DWORD64 off_player_health = 0x280;
		DWORD64 off_player_healthmax = 0x2A0;
		DWORD64 off_player_armor = 0x14B8;
		DWORD64 off_player_invisibility = 0x2C;
		DWORD64 off_player_godmode = 0x189;
		DWORD64 off_player_ragdoll = 0x10A8;
		DWORD64 off_player_in_vehicle = 0x146B;
		DWORD64 off_player_speed_x = 0x320;
		DWORD64 off_player_speed_y = 0x324;
		DWORD64 off_player_speed_z = 0x328;

		//playerposition
		DWORD64 off_player_pos = 0x30;
		DWORD64 off_player_pos_x = 0x50;
		DWORD64 off_player_pos_y = 0x54;
		DWORD64 off_player_pos_z = 0x58;

		//playerMisc
		DWORD64 off_player_info = 0x10B8;
		DWORD64 off_player_info_nearestvehicle = 0x458;
		DWORD64 off_player_info_wanted_level = 0x818;
		DWORD64 off_player_info_sprintmp = 0x14C;
		DWORD64 off_player_info_swimmp = 0x148;
		DWORD64 off_player_info_stamina = 0xC60;

		//vehicle 
		DWORD64 off_player_vehicle = 0xD28;
		DWORD64 off_player_vehicle_health_1 = 0x280;
		DWORD64 off_player_vehicle_health_2 = 0x8E8;
		DWORD64 off_player_vehicle_health_3 = 0x824;
		DWORD64 off_player_vehicle_invisibility = 0x2C;
		DWORD64 off_player_vehicle_godmode = 0x189;
		DWORD64 off_player_vehicle_gravity = 0xC1C;
		DWORD64 off_player_vehicle_speed_x = 0x7D0;
		DWORD64 off_player_vehicle_speed_y = 0x7D4;
		DWORD64 off_player_vehicle_speed_z = 0x7D8;

		//vehiclehandling
		DWORD64 off_player_vehicle_handling = 0x918;
		DWORD64 off_player_vehicle_handling_acceleration = 0x4C;
		DWORD64 off_player_vehicle_handling_tractioncurve_min = 0x90;
		DWORD64 off_player_vehicle_handling_tractioncurve_max = 0x88;


		//vehicleposition
		DWORD64 off_player_vehicle_pos = 0x30;
		DWORD64 off_player_vehicle_pos_x = 0x50;
		DWORD64 off_player_vehicle_pos_y = 0x54;
		DWORD64 off_player_vehicle_pos_z = 0x58;

		//weapon
		DWORD64 off_weapon_current_ammo = 0x18;
		DWORD64 off_weapon_damage = 0xB0;
		DWORD64 off_weapon_reload_multiplier = 0x12C;
	}

	namespace player
	{
		bool get_invehicle()
		{
			int State;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_in_vehicle), &State, sizeof(int), NULL);

			if (State == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void set_health(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_health), &value, sizeof(float), NULL);
		}

		void set_armor(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_armor), &value, sizeof(float), NULL);
		}

		void set_godmode(bool value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_godmode), &value, sizeof(bool), NULL);
		}

		void set_invisibility(bool value)
		{
			BYTE on = 1;
			BYTE off = 47;

			if (value == true)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_invisibility), &on, sizeof(BYTE), NULL);
			}
			else if (value == false)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_invisibility), &off, sizeof(BYTE), NULL);
			}
		}

		void set_ragdoll(bool value)
		{
			BYTE on = 1;
			BYTE off = 32;

			if (value == true)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_ragdoll), &off, sizeof(BYTE), NULL);

			}
			else if (value == false)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_ragdoll), &on, sizeof(BYTE), NULL);

			}
		}

		void set_wantedlvl(int value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_player_info_wanted_level), &value, sizeof(int), NULL);
		}

		void set_sprintspeed(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_player_info_sprintmp), &value, sizeof(float), NULL);
		}

		void set_swimspeed(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_player_info_swimmp), &value, sizeof(float), NULL);
		}

		void set_xyz(vector3 values)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_x), &values, sizeof(values), NULL);
		}

		void set_freeze(bool value) //stops writing to xyz coordinates
		{
			BYTE freeze_on[4] = { 0x90, 0x90, 0x90, 0x90 };
			BYTE freeze_off[4] = { 0x0F, 0x29, 0x48, 0x50 };

			if (value == true)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_freeze), &freeze_on, sizeof(freeze_on), NULL);
			}
			else if (value == false)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_freeze), &freeze_off, sizeof(freeze_off), NULL);
			}
		}

		void set_x(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_x), &value, sizeof(float), NULL);
		}

		void set_y(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_y), &value, sizeof(float), NULL);
		}

		void set_z(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_z), &value, sizeof(float), NULL);
		}

		float get_speed_x()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_speed_x), &value, sizeof(float), NULL);
			return value;
		}

		float get_speed_y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_speed_y), &value, sizeof(float), NULL);
			return value;
		}

		float get_speed_z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_speed_z), &value, sizeof(float), NULL);
			return value;
		}

		float get_health()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_health), &value, sizeof(float), NULL);
			return value;
		}

		float get_healthmax()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_healthmax), &value, sizeof(float), NULL);
			return value;
		}

		float get_armor()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_armor), &value, sizeof(float), NULL);
			return value;
		}

		bool get_godmode()
		{
			bool value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_godmode), &value, sizeof(bool), NULL);
			return value;
		}

		bool get_invisibility()
		{
			BYTE value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_invisibility), &value, sizeof(BYTE), NULL);

			if (value != 1)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		bool get_ragdoll()
		{
			BYTE value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_ragdoll), &value, sizeof(BYTE), NULL);

			if (value == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		int get_wantedlevel()
		{
			int value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_player_info_wanted_level), &value, sizeof(int), NULL);
			return value;
		}

		float get_sprintspeed()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_player_info_sprintmp), &value, sizeof(float), NULL);
			return value;
		}

		float get_swimspeed()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_player_info_swimmp), &value, sizeof(float), NULL);
			return value;
		}

		vector3 get_xyz()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_x), &values, sizeof(values), NULL);
			return values;
		}

		bool get_freeze()
		{
			BYTE value;

			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_freeze), &value, sizeof(BYTE), NULL);
			if (value != 144)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		float get_x()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_x), &value, sizeof(float), NULL);
			return value;
		}

		float get_y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_y), &value, sizeof(float), NULL);
			return value;
		}

		float get_z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_position + ph::off::off_player_pos_z), &value, sizeof(float), NULL);
			return value;
		}

		vector3 get_speed_xyz()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_speed_x), &values, sizeof(vector3), NULL);
			return values;
		}

		float get_waypoint_x()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_waypoint_x), &value, sizeof(float), NULL);
			return value;
		}

		float get_waypoint_y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_waypoint_y), &value, sizeof(float), NULL);
			return value;
		}

		int get_crosshair()
		{
			int value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_crosshairid), &value, sizeof(int), NULL);
			return value;
		}
	}

	// vehicle
	namespace vehicle
	{
		void update()
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + ph::off::off_player_vehicle), &ph::info.dw_player_vehicle, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_handling), &ph::info.dw_player_vehicle_handling, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_pos), &ph::info.dw_player_vehicle_position, sizeof(DWORD64), NULL);
		}

		void set_godmode(bool value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_godmode), &value, sizeof(bool), NULL);
		}

		void set_xyz(vector3 values)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_pos_x), &values, sizeof(values), NULL);
		}

		void set_x(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_pos_x), &value, sizeof(float), NULL);
		}

		void set_y(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_pos_y), &value, sizeof(float), NULL);
		}

		void set_z(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_pos_z), &value, sizeof(float), NULL);
		}

		void set_gravity(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_gravity), &value, sizeof(float), NULL);
		}

		void set_acceleration(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_handling + ph::off::off_player_vehicle_handling_acceleration), &value, sizeof(float), NULL);
		}

		void set_traction_min(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_min), &value, sizeof(float), NULL);
		}

		void set_traction_max(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_max), &value, sizeof(float), NULL);
		}

		void set_health1(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_health_1), &value, sizeof(float), NULL);
		}

		void set_health2(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_health_2), &value, sizeof(float), NULL);
		}

		void set_health3(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_health_3), &value, sizeof(float), NULL);
		}

		bool get_godmode()
		{
			bool value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_godmode), &value, sizeof(bool), NULL);
			return value;
		}

		vector3 get_xyz()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_vehicle_pos_x), &values, sizeof(values), NULL);
			return values;
		}

		float get_x()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_vehicle_pos_x), &value, sizeof(float), NULL);
			return value;
		}

		float get_y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_vehicle_pos_y), &value, sizeof(float), NULL);
			return value;
		}

		float get_z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_position + ph::off::off_player_vehicle_pos_z), &value, sizeof(float), NULL);
			return value;
		}

		vector3 get_speed_xyz()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_speed_x), &values, sizeof(values), NULL);
			return values;
		}

		float get_speed_x()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_speed_x), &value, sizeof(float), NULL);
			return value;
		}

		float get_speed_y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_speed_y), &value, sizeof(float), NULL);
			return value;
		}

		float get_speed_z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_speed_z), &value, sizeof(float), NULL);
			return value;
		}

		float get_acceleration()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_handling + ph::off::off_player_vehicle_handling_acceleration), &value, sizeof(float), NULL);
			return value;
		}

		float get_traction_min()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_min), &value, sizeof(float), NULL);
			return value;
		}

		float get_traction_max()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_max), &value, sizeof(float), NULL);
			return value;
		}

		float get_health1()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_health_1), &value, sizeof(float), NULL);
			return value;
		}

		float get_health2()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_health_2), &value, sizeof(float), NULL);
			return value;
		}

		float get_health3()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_health_3), &value, sizeof(float), NULL);
			return value;
		}

		float get_gravity()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_vehicle + ph::off::off_player_vehicle_gravity), &value, sizeof(float), NULL);
			return value;
		}
	}

	// vehiclenearest
	namespace vehiclenearest
	{
		void update()
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_player_info_nearestvehicle), &ph::info.dw_player_info_nearestvehicle, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_handling), &ph::info.dw_player_info_nearestvehicle_handling, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_pos), &ph::info.dw_player_info_nearestvehicle_position, sizeof(DWORD64), NULL);
		}

		void set_godmode(bool value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_godmode), &value, sizeof(bool), NULL);
		}

		void set_xyz(vector3 values)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_x), &values, sizeof(values), NULL);
		}

		void set_x(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_x), &value, sizeof(float), NULL);
		}

		void set_y(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_y), &value, sizeof(float), NULL);
		}

		void set_z(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_z), &value, sizeof(float), NULL);
		}

		void set_gravity(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_gravity), &value, sizeof(float), NULL);
		}

		void set_acceleration(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_handling + ph::off::off_player_vehicle_handling_acceleration), &value, sizeof(float), NULL);
		}

		void set_traction_min(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_min), &value, sizeof(float), NULL);
		}

		void set_traction_max(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_max), &value, sizeof(float), NULL);
		}

		void set_health1(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_health_1), &value, sizeof(float), NULL);
		}

		void set_health2(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_health_2), &value, sizeof(float), NULL);
		}

		void set_health3(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_health_3), &value, sizeof(float), NULL);
		}

		bool get_godmode()
		{
			bool value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_godmode), &value, sizeof(bool), NULL);
			return value;
		}

		vector3 get_xyz()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_x), &values, sizeof(values), NULL);
			return values;
		}

		float get_x()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_x), &value, sizeof(float), NULL);
			return value;
		}

		float get_y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_y), &value, sizeof(float), NULL);
			return value;
		}

		float get_z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_position + ph::off::off_player_vehicle_pos_z), &value, sizeof(float), NULL);
			return value;
		}

		vector3 get_speed_xyz()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_speed_x), &values, sizeof(values), NULL);
			return values;
		}

		float get_speed_x()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_speed_x), &value, sizeof(float), NULL);
			return value;
		}

		float get_speed_y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_speed_y), &value, sizeof(float), NULL);
			return value;
		}

		float get_speed_z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_speed_z), &value, sizeof(float), NULL);
			return value;
		}

		float get_acceleration()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_handling + ph::off::off_player_vehicle_handling_acceleration), &value, sizeof(float), NULL);
			return value;
		}

		float get_traction_min()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_min), &value, sizeof(float), NULL);
			return value;
		}

		float get_traction_max()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle_handling + ph::off::off_player_vehicle_handling_tractioncurve_max), &value, sizeof(float), NULL);
			return value;
		}

		float get_health1()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_health_1), &value, sizeof(float), NULL);
			return value;
		}

		float get_health2()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_health_2), &value, sizeof(float), NULL);
			return value;
		}

		float get_health3()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_health_3), &value, sizeof(float), NULL);
			return value;
		}

		float get_gravity()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info_nearestvehicle + ph::off::off_player_vehicle_gravity), &value, sizeof(float), NULL);
			return value;
		}
	}

	namespace weapon
	{
		void update()
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player + 0x10C8), &ph::info.dw_player_weapon, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon + 0x20), &ph::info.dw_player_weapon, sizeof(DWORD64), NULL);

			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon + 0x60), &ph::info.dw_player_weapon_ammo, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon_ammo + 0x8), &ph::info.dw_player_weapon_ammo, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon_ammo + 0x0), &ph::info.dw_player_weapon_ammo, sizeof(DWORD64), NULL);
		}

		void set_damage(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon + ph::off::off_weapon_damage), &value, sizeof(float), NULL);
		}

		void set_currentammo(int value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon_ammo + ph::off::off_weapon_current_ammo), &value, sizeof(int), NULL);
		}

		void set_reloadspeed(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon + ph::off::off_weapon_reload_multiplier), &value, sizeof(float), NULL);
		}

		float get_damage()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon + ph::off::off_weapon_damage), &value, sizeof(float), NULL);
			return value;
		}

		float get_reloadspeed()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_info + ph::off::off_weapon_reload_multiplier), &value, sizeof(float), NULL);
			return value;
		}

		int get_currentammo()
		{
			int value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::info.dw_player_weapon_ammo + ph::off::off_weapon_damage), &value, sizeof(float), NULL);
			return value;
		}
	}
}