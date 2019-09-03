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
	namespace Offsets
	{
		extern DWORD64 ptrWorld;
		extern DWORD64 ptrWaypointX;
		extern DWORD64 ptrWaypointY;
		extern DWORD64 ptrCrosshair;

		//opcodes
		extern DWORD64 opFreeze;

		//player
		extern DWORD64 Player;
		extern DWORD64 PlayerHealth;
		extern DWORD64 PlayerHealthMax;
		extern DWORD64 PlayerArmor;
		extern DWORD64 PlayerInvisibility;
		extern DWORD64 PlayerGodmode;
		extern DWORD64 PlayerRagdoll;
		extern DWORD64 PlayerInVehicle;
		extern DWORD64 PlayerSpeedX;
		extern DWORD64 PlayerSpeedY;
		extern DWORD64 PlayerSpeedZ;

		//playerposition
		extern DWORD64 Player_Pos;
		extern DWORD64 Player_PosX;
		extern DWORD64 Player_PosY;
		extern DWORD64 Player_PosZ;

		//playerMisc
		extern DWORD64 Player_Info;
		extern DWORD64 Player_InfoNearestvehicle;
		extern DWORD64 Player_InfoWantedlvl;
		extern DWORD64 Player_InfoSprint;
		extern DWORD64 Player_InfoSwim;
		extern DWORD64 Player_InfoStamina;

		//vehicle 
		extern DWORD64 Player_Vehicle;
		extern DWORD64 Player_VehicleHealth1;
		extern DWORD64 Player_VehicleHealth2;
		extern DWORD64 Player_VehicleHealth3;
		extern DWORD64 Player_VehicleInvisibility;
		extern DWORD64 Player_VehicleRocketfuel;
		extern DWORD64 Player_VehicleRocketspeed;
		extern DWORD64 Player_VehicleRocketrecharge;
		extern DWORD64 Player_VehicleDirtamount;
		extern DWORD64 Player_VehicleBulletproof;
		extern DWORD64 Player_VehicleGodmode;
		extern DWORD64 Player_VehicleGravity;
		extern DWORD64 Player_VehicleSpeedX;
		extern DWORD64 Player_VehicleSpeedY;
		extern DWORD64 Player_VehicleSpeedZ;


		//vehiclehandling
		extern DWORD64 Player_Vehicle_Handling;
		extern DWORD64 Player_Vehicle_HandlingAccelerationMP;
		extern DWORD64 Player_Vehicle_HandlingTractionMin;
		extern DWORD64 Player_Vehicle_HandlingTractionMax;
		extern DWORD64 Player_Vehicle_HandlingBrakeforce;
		extern DWORD64 Player_Vehicle_HandlingHandbrakeforce;
		extern DWORD64 Player_Vehicle_HandlingMass;
		extern DWORD64 Player_Vehicle_HandlingPercentSubmerged;
		extern DWORD64 Player_Vehicle_HandlingCollissionDamage;
		extern DWORD64 Player_Vehicle_HandlingWeaponDamage;
		extern DWORD64 Player_Vehicle_HandlingDeformMP;
		extern DWORD64 Player_Vehicle_HandlingThrust;
		extern DWORD64 Player_Vehicle_HandlingThrustDeluxo;


		//vehicleposition
		extern DWORD64 Player_Vehicle_Pos;
		extern DWORD64 Player_Vehicle_PosX;
		extern DWORD64 Player_Vehicle_PosY;
		extern DWORD64 Player_Vehicle_PosZ;

		//weapon
		extern DWORD64 Player_WeaponInfo_AmmoInfoAmmo;
		extern DWORD64 Player_WeaponInfo_AmmoInfoRocketspeed;
		extern DWORD64 Player_WeaponInfo_AmmoInfoRocketlifetime;

		extern DWORD64 Player_WeaponInfoDamage;
		extern DWORD64 Player_WeaponInfoReload;
		extern DWORD64 Player_WeaponInfoMass;
		extern DWORD64 Player_WeaponInfoMuzzleVel;
		extern DWORD64 Player_WeaponInfoRange;
		extern DWORD64 Player_WeaponInfoRecoil;
		extern DWORD64 Player_WeaponInfoBatchSpread;
		extern DWORD64 Player_WeaponInfoPenetration;
		extern DWORD64 Player_WeaponInfoForceOnPed;
		extern DWORD64 Player_WeaponInfoForceOnVehicle;
		extern DWORD64 Player_WeaponInfoForceOnHeli;
	}

	//namespace

	namespace Player
	{
		float    Health();
		void     Health(float Value);
		float    Healthmax();
		void     Healthmax(float Value);
		float    Armor();
		void     Armor(float Value);
		int      Wantedlvl();
		void     Wantedlvl(int Value);
		float    SprintMP();
		void     SprintMP(float Value);
		float    SwimMP();
		void     SwimMP(float Value);
		vector3  XYZ();
		void     XYZ(vector3 Values);
		float    X();
		void     X(float Value);
		float    Y();
		void     Y(float Value);
		float    Z();
		void     Z(float Value);
		bool     Godmode();
		void     Godmode(bool Value);
		bool     Invisibility();
		void     Invisibility(bool Value);
		bool     Ragdoll();
		void     Ragdoll(bool Value);
		bool     Freeze();
		void     Freeze(bool Value);


		vector3  SpeedXYZ();
		float    SpeedX();
		float    SpeedY();
		float    SpeedZ();
		float    WaypointX();
		float    WaypointY();
		int      Crosshair();
		bool     Invehicle();
	}

	namespace Vehicle
	{
		void     Update();

		vector3  XYZ();
		void     XYZ(vector3 Values);
		float    X();
		void     X(float Value);
		float    Y();
		void     Y(float Value);
		float    Z();
		void     Z(float Value);
		bool     Godmode();
		void     Godmode(bool Value);
		float    Gravity();
		void     Gravity(float Value);
		float    Acceleration();
		void     Acceleration(float Value);
		float    TractionMin();
		void     TractionMin(float Value);
		float    TractionMax();
		void     TractionMax(float Value);
		float    Health();
		void     Health(float Value);
		float    Health2();
		void     Health2(float Value);
		float    Health3();
		void     Health3(float Value);
		float	 RocketFuel();
		void	 RocketFuel(float Value);
		float	 RocketSpeed();
		void	 RocketSpeed(float Value);
		float	 RocketRecharge();
		void	 RocketRecharge(float Value);
		float    DirtAmount();
		void     DirtAmount(float Value);
		float    BrakeForce();
		void     BrakeForce(float Value);
		float	 HandbrakeForce();
		void	 HandbrakeForce(float Value);
		float	 Mass();
		void	 Mass(float Value);
		float	 CollisionDamage();
		void	 CollisionDamage(float Value);
		float	 WeaponDamage();
		void	 WeaponDamage(float Value);
		float	 Deformmp();
		void	 Deformmp(float Value);
		float	 Thrust();
		void	 Thrust(float Value);
		float	 ThrustDeluxo();
		void	 ThrustDeluxo(float Value);


		vector3  SpeedXYZ();
		float    SpeedX();
		float    SpeedY();
		float    SpeedZ();
	}

	namespace Vehiclenearest
	{
		void     Update();

		vector3  XYZ();
		void     XYZ(vector3 Values);
		float    X();
		void     X(float Value);
		float    Y();
		void     Y(float Value);
		float    Z();
		void     Z(float Value);
		bool     Godmode();
		void     Godmode(bool Value);
		float    Gravity();
		void     Gravity(float Value);
		float    Acceleration();
		void     Acceleration(float Value);
		float    TractionMin();
		void     TractionMin(float Value);
		float    TractionMax();
		void     TractionMax(float Value);
		float    Health();
		void     Health(float Value);
		float    Health2();
		void     Health2(float Value);
		float    Health3();
		void     Health3(float Value);

		vector3  SpeedXYZ();
		float    SpeedX();
		float    SpeedY();
		float    SpeedZ();
	}

	namespace Weapon
	{
		void     Update();

		float    Damage();
		void     Damage(float Value);
		int      Ammo();
		void     Ammo(int Value);
		float    Reload();
		void     Reload(float Value);
		float	 Mass();
		void	 Mass(float Value);
		float	 Muzzlevel();
		void	 Muzzlevel(float Value);
		float	 Recoil();
		void	 Recoil(float Value);
		float	 Range();
		void	 Range(float Value);
		float	 BatchSpread();
		void	 BatchSpread(float Value);
		float	 Penetration();
		void	 Penetration(float Value);
		float	 ForcOnPed();
		void	 ForcOnPed(float Value);
		float	 ForceOnVehicle();
		void	 ForceOnVehicle(float Value);
		float	 ForceOnHeli();
		void	 ForceOnHeli(float Value);
		float	 RocketLifetime();
		void	 RocketLifetime(float Value);
		float	 RocketSpeed();
		void	 RocketSpeed(float Value);
	}
}
