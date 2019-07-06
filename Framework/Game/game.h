#pragma once
#include <Windows.h>
#include "game.h"
#include "../../Framework/Memory/info.h"

struct vector3
{
	float x, y, z;
};
struct vector2
{
	float x, y;
};

namespace ph
{
	namespace off
	{
		extern DWORD64 ptr_world;
		extern DWORD64 ptr_nearest_ped;
		extern DWORD64 ptr_waypoint_x;
		extern DWORD64 ptr_waypoint_y;
		extern DWORD64 ptr_crosshair;

		//opcodes
		extern DWORD64 op_freeze_player;

		//player
		extern DWORD64 off_player;
		extern DWORD64 off_player_health;
		extern DWORD64 off_player_healthmax;
		extern DWORD64 off_player_armor;
		extern DWORD64 off_player_invisibility;
		extern DWORD64 off_player_godmode;
		extern DWORD64 off_player_ragdoll;
		extern DWORD64 off_player_in_vehicle;
		extern DWORD64 off_player_speed_x;
		extern DWORD64 off_player_speed_y;
		extern DWORD64 off_player_speed_z;

		//playerposition
		extern DWORD64 off_player_pos;
		extern DWORD64 off_player_pos_x;
		extern DWORD64 off_player_pos_y;
		extern DWORD64 off_player_pos_z;

		//playerMisc
		extern DWORD64 off_player_info;
		extern DWORD64 off_player_info_nearestvehicle;
		extern DWORD64 off_player_info_wanted_level;
		extern DWORD64 off_player_info_sprintmp;
		extern DWORD64 off_player_info_swimmp;
		extern DWORD64 off_player_info_stamina;

		//vehicle 
		extern DWORD64 off_player_vehicle;
		extern DWORD64 off_player_vehicle_health_1;
		extern DWORD64 off_player_vehicle_health_2;
		extern DWORD64 off_player_vehicle_health_3;
		extern DWORD64 off_player_vehicle_invisibility;
		extern DWORD64 off_player_vehicle_godmode;
		extern DWORD64 off_player_vehicle_gravity;
		extern DWORD64 off_player_vehicle_speed_x;
		extern DWORD64 off_player_vehicle_speed_y;
		extern DWORD64 off_player_vehicle_speed_z;

		//vehiclehandling
		extern DWORD64 off_player_vehicle_handling;
		extern DWORD64 off_player_vehicle_handling_acceleration;
		extern DWORD64 off_player_vehicle_handling_tractioncurve_min;
		extern DWORD64 off_player_vehicle_handling_tractioncurve_max;


		//vehicleposition
		extern DWORD64 off_player_vehicle_pos;
		extern DWORD64 off_player_vehicle_pos_x;
		extern DWORD64 off_player_vehicle_pos_y;
		extern DWORD64 off_player_vehicle_pos_z;

		//weapon
		extern DWORD64 off_weapon_current_ammo;
		extern DWORD64 off_weapon_damage;
		extern DWORD64 off_weapon_reload_multiplier;
	}

	//namespace

	namespace player
	{
		void     set_health(float Value);
		void     set_armor(float Value);
		void     set_wantedlvl(int Value);
		void     set_sprintspeed(float Value);
		void     set_swimspeed(float Value);
		void     set_xyz(vector3 Values);
		void     set_x(float Value);
		void     set_y(float Value);
		void     set_z(float Value);
		void     set_godmode(bool Value);
		void     set_invisibility(bool Value);
		void     set_ragdoll(bool Value);
		void     set_freeze(bool Value);


		float    get_health();
		float    get_healthmax();
		float    get_armor();
		float    get_sprintspeed();
		float    get_swimspeed();
		vector3  get_xyz();
		float    get_x();
		float    get_y();
		float    get_z();
		vector3  get_speed_xyz();
		float    get_speed_x();
		float    get_speed_y();
		float    get_speed_z();
		float    get_waypoint_x();
		float    get_waypoint_y();
		int      get_wantedlevel();
		int      get_crosshair();
		bool     get_freeze();
		bool     get_invehicle();
		bool     get_godmode();
		bool     get_invisibility();
		bool     get_ragdoll();
	}

	namespace vehicle
	{
		void     update();

		void     set_xyz(vector3 Values);
		void     set_x(float Value);
		void     set_y(float Value);
		void     set_z(float Value);
		void     set_godmode(bool Value);
		void     set_gravity(float Value);
		void     set_acceleration(float Value);
		void     set_traction_min(float Value);
		void     set_traction_max(float Value);
		void     set_health1(float Value);
		void     set_health2(float Value);
		void     set_health3(float Value);

		vector3  get_xyz();
		float    get_x();
		float    get_y();
		float    get_z();
		vector3  get_speed_xyz();
		float    get_speed_x();
		float    get_speed_y();
		float    get_speed_z();
		bool     get_godmode();
		float    get_acceleration();
		float    get_traction_min();
		float    get_traction_max();
		float    get_health1();
		float    get_health2();
		float    get_health3();
		float    get_gravity();
	}

	namespace vehiclenearest
	{
		void     update();

		void     set_xyz(vector3 Values);
		void     set_x(float Value);
		void     set_y(float Value);
		void     set_z(float Value);
		void     set_godmode(bool Value);
		void     set_gravity(float Value);
		void     set_acceleration(float Value);
		void     set_traction_min(float Value);
		void     set_traction_max(float Value);
		void     set_health1(float Value);
		void     set_health2(float Value);
		void     set_health3(float Value);

		vector3  get_xyz();
		float    get_x();
		float    get_y();
		float    get_z();
		vector3  get_speed_xyz();
		float    get_speed_x();
		float    get_speed_y();
		float    get_speed_z();
		bool     get_godmode();
		float    get_acceleration();
		float    get_traction_min();
		float    get_traction_max();
		float    get_health1();
		float    get_health2();
		float    get_health3();
		float    get_gravity();
	}

	namespace weapon
	{
		void     update();

		void     set_damage(float Value);
		void     set_currentammo(int Value);
		void     set_reloadspeed(float Value);

		float    get_damage();
		float    get_reloadspeed();
		int      get_currentammo();
	}
}