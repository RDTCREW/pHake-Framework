#include "game.h"

namespace ph
{
	namespace Offsets
	{
		DWORD64 ptrWorld = 0x0249C050;
		DWORD64 ptrWaypointX = 0x1F49CC0;
		DWORD64 ptrWaypointY = 0x1F49CC4;
		DWORD64 ptrCrosshair = 0x1F326B0;

		//OpwCodes
		DWORD64 opFreeze = 0x141A11F;

		//player
		DWORD64 Player = 0x8;
		DWORD64 PlayerHealth = 0x280;
		DWORD64 PlayerHealthMax = 0x2A0;
		DWORD64 PlayerArmor = 0x14B8;
		DWORD64 PlayerInvisibility = 0x2C;
		DWORD64 PlayerGodmode = 0x189;
		DWORD64 PlayerRagdoll = 0x10A8;
		DWORD64 PlayerInVehicle = 0x146B;
		DWORD64 PlayerSpeedX = 0x320;
		DWORD64 PlayerSpeedY = 0x324;
		DWORD64 PlayerSpeedZ = 0x328;

		//playerposition
		DWORD64 Player_Pos = 0x30;
		DWORD64 Player_PosX = 0x50;
		DWORD64 Player_PosY = 0x54;
		DWORD64 Player_PosZ = 0x58;

		//playerMisc
		DWORD64 Player_Info = 0x10B8;
		DWORD64 Player_InfoNearestvehicle = 0x458;
		DWORD64 Player_InfoWantedlvl = 0x818;
		DWORD64 Player_InfoSprint = 0x14C;
		DWORD64 Player_InfoSwim = 0x148;
		DWORD64 Player_InfoStamina = 0xC60;

		//vehicle 
		DWORD64 Player_Vehicle = 0xD28;
		DWORD64 Player_VehicleHealth1 = 0x280;
		DWORD64 Player_VehicleHealth2 = 0x8E8;
		DWORD64 Player_VehicleHealth3 = 0x824;
		DWORD64 Player_VehicleInvisibility = 0x2C;
		DWORD64 Player_VehicleGodmode = 0x189;
		DWORD64 Player_VehicleGravity = 0xC1C;
		DWORD64 Player_VehicleSpeedX = 0x7D0;
		DWORD64 Player_VehicleSpeedY = 0x7D4;
		DWORD64 Player_VehicleSpeedZ = 0x7D8;
		DWORD64 Player_VehicleRocketfuel = 0x322;
		DWORD64 Player_VehicleRocketspeed = 0x120;
		DWORD64 Player_VehicleRocketrecharge = 0x324;
		DWORD64 Player_VehicleDirtamount = 0x988;
		DWORD64 Player_VehicleBulletproof = 0x923;

		//vehiclehandling
		DWORD64 Player_Vehicle_Handling = 0x918;
		DWORD64 Player_Vehicle_HandlingAccelerationMP = 0x4C;
		DWORD64 Player_Vehicle_HandlingTractionMin = 0x90;
		DWORD64 Player_Vehicle_HandlingTractionMax = 0x88;
		DWORD64 Player_Vehicle_HandlingBrakeforce = 0x6C;
		DWORD64 Player_Vehicle_HandlingHandbrakeforce = 0x7C;
		DWORD64 Player_Vehicle_HandlingMass = 0xC;
		DWORD64 Player_Vehicle_HandlingPercentSubmerged = 0x40;
		DWORD64 Player_Vehicle_HandlingCollissionDamage = 0xF0;
		DWORD64 Player_Vehicle_HandlingWeaponDamage = 0xF4;
		DWORD64 Player_Vehicle_HandlingDeformMP = 0xF8;
		DWORD64 Player_Vehicle_HandlingThrust = 0x338;
		DWORD64 Player_Vehicle_HandlingThrustDeluxo = 0x3C8;


		//vehicleposition
		DWORD64 Player_Vehicle_Pos = 0x30;
		DWORD64 Player_Vehicle_PosX = 0x50;
		DWORD64 Player_Vehicle_PosY = 0x54;
		DWORD64 Player_Vehicle_PosZ = 0x58;

		//weapon
		DWORD64 Player_WeaponInfo_AmmoInfoAmmo = 0x18;
		DWORD64 Player_WeaponInfo_AmmoInfoRocketspeed = 0x58;
		DWORD64 Player_WeaponInfo_AmmoInfoRocketlifetime = 0x48;

		DWORD64 Player_WeaponInfoDamage = 0xB0;
		DWORD64 Player_WeaponInfoReload = 0x12C;
		DWORD64 Player_WeaponInfoMass = 0xD8;
		DWORD64 Player_WeaponInfoMuzzleVel = 0x144;
		DWORD64 Player_WeaponInfoRange = 0x28C;
		DWORD64 Player_WeaponInfoRecoil = 0x2E8;
		DWORD64 Player_WeaponInfoBatchSpread = 0x74;
		DWORD64 Player_WeaponInfoPenetration = 0x108;
		DWORD64 Player_WeaponInfoForceOnPed = 0xD4;
		DWORD64 Player_WeaponInfoForceOnVehicle = 0xD8;
		DWORD64 Player_WeaponInfoForceOnHeli = 0xDC;
	}

	namespace Player
	{
		bool Invehicle()
		{
			int State;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Base + 0x1C4C6B0), &State, sizeof(int), NULL);

			if (State == 0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		void Health(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerHealth), &value, sizeof(float), NULL);
		}

		void Armor(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerArmor), &value, sizeof(float), NULL);
		}

		void Godmode(bool value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerGodmode), &value, sizeof(bool), NULL);
		}

		void Invisibility(bool value)
		{
			BYTE on = 1;
			BYTE off = 47;

			if (value == true)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerInvisibility), &on, sizeof(BYTE), NULL);
			}
			else if (value == false)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerInvisibility), &off, sizeof(BYTE), NULL);
			}
		}

		void Ragdoll(bool value)
		{
			BYTE on = 1;
			BYTE off = 32;

			if (value == true)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerRagdoll), &off, sizeof(BYTE), NULL);

			}
			else if (value == false)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerRagdoll), &on, sizeof(BYTE), NULL);

			}
		}

		void Wantedlvl(int value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info + ph::Offsets::Player_InfoWantedlvl), &value, sizeof(int), NULL);
		}

		void SprintMP(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info + ph::Offsets::Player_InfoSprint), &value, sizeof(float), NULL);
		}

		void SwimMP(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info + ph::Offsets::Player_InfoSwim), &value, sizeof(float), NULL);
		}

		void XYZ(vector3 values)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosX), &values, sizeof(values), NULL);
		}

		void Freeze(bool value) //stops writing to xyz coordinates
		{
			BYTE freeze_on[4] = { 0x90, 0x90, 0x90, 0x90 };
			BYTE freeze_off[4] = { 0x0F, 0x29, 0x48, 0x50 };

			if (value == true)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.PlayerFreeze), &freeze_on, sizeof(freeze_on), NULL);
			}
			else if (value == false)
			{
				WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.PlayerFreeze), &freeze_off, sizeof(freeze_off), NULL);
			}
		}

		void X(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosX), &value, sizeof(float), NULL);
		}

		void Y(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosY), &value, sizeof(float), NULL);
		}

		void Z(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosZ), &value, sizeof(float), NULL);
		}

		float SpeedX()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerSpeedX), &value, sizeof(float), NULL);
			return value;
		}

		float SpeedY()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerSpeedY), &value, sizeof(float), NULL);
			return value;
		}

		float SpeedZ()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerSpeedZ), &value, sizeof(float), NULL);
			return value;
		}

		float Health()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerHealth), &value, sizeof(float), NULL);
			return value;
		}

		float Healthmax()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerHealthMax), &value, sizeof(float), NULL);
			return value;
		}

		void Healthmax(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerHealthMax), &Value, sizeof(float), NULL);
		}

		float Armor()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerArmor), &value, sizeof(float), NULL);
			return value;
		}

		bool Godmode()
		{
			bool value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerGodmode), &value, sizeof(bool), NULL);
			return value;
		}

		bool Invisibility()
		{
			BYTE value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerInvisibility), &value, sizeof(BYTE), NULL);

			if (value != 1)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		bool Ragdoll()
		{
			BYTE value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerRagdoll), &value, sizeof(BYTE), NULL);

			if (value == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		int Wantedlvl()
		{
			int value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info + ph::Offsets::Player_InfoWantedlvl), &value, sizeof(int), NULL);
			return value;
		}

		float SprintMP()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info + ph::Offsets::Player_InfoSprint), &value, sizeof(float), NULL);
			return value;
		}

		float SwimMP()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info + ph::Offsets::Player_InfoSwim), &value, sizeof(float), NULL);
			return value;
		}

		vector3 XYZ()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosX), &values, sizeof(values), NULL);
			return values;
		}

		bool Freeze()
		{
			BYTE value;

			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.PlayerFreeze), &value, sizeof(BYTE), NULL);
			if (value != 144)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		float X()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosX), &value, sizeof(float), NULL);
			return value;
		}

		float Y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosY), &value, sizeof(float), NULL);
			return value;
		}

		float Z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Position + ph::Offsets::Player_PosZ), &value, sizeof(float), NULL);
			return value;
		}

		vector3 SpeedXYZ()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::PlayerSpeedX), &values, sizeof(vector3), NULL);
			return values;
		}

		float WaypointX()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.WaypointX), &value, sizeof(float), NULL);
			return value;
		}

		float WaypointY()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.WaypointY), &value, sizeof(float), NULL);
			return value;
		}

		int Crosshair()
		{
			int value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.CrosshairId), &value, sizeof(int), NULL);
			return value;
		}
	}

	// vehicle
	namespace Vehicle
	{
		void Update()
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + ph::Offsets::Player_Vehicle), &ph::Info.Player_Vehicle, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_Vehicle_Handling), &ph::Info.Player_Vehicle_Handling, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_Vehicle_Pos), &ph::Info.Player_Vehicle_Position, sizeof(DWORD64), NULL);
		}

		void Godmode(bool value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleGodmode), &value, sizeof(bool), NULL);
		}

		void XYZ(vector3 values)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_PosX), &values, sizeof(values), NULL);
		}

		void X(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_PosX), &value, sizeof(float), NULL);
		}

		void Y(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_PosY), &value, sizeof(float), NULL);
		}

		void Z(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_PosZ), &value, sizeof(float), NULL);
		}

		void Gravity(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleGravity), &value, sizeof(float), NULL);
		}

		void Acceleration(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingAccelerationMP), &value, sizeof(float), NULL);
		}

		void TractionMin(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMin), &value, sizeof(float), NULL);
		}

		void TractionMax(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMax), &value, sizeof(float), NULL);
		}

		void Health(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleHealth1), &value, sizeof(float), NULL);
		}

		void Health2(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleHealth2), &value, sizeof(float), NULL);
		}

		void Health3(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleHealth3), &value, sizeof(float), NULL);
		}

		float RocketFuel()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleRocketfuel), &value, sizeof(float), NULL);
			return value;
		}

		void RocketFuel(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleRocketfuel), &Value, sizeof(float), NULL);
		}

		float RocketSpeed()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleRocketspeed), &value, sizeof(float), NULL);
			return value;
		}

		void RocketSpeed(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleRocketspeed), &Value, sizeof(float), NULL);
		}

		float RocketRecharge()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleRocketrecharge), &value, sizeof(float), NULL);
			return value;
		}

		void RocketRecharge(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleRocketrecharge), &Value, sizeof(float), NULL);
		}

		float DirtAmount()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleDirtamount), &value, sizeof(float), NULL);
			return value;
		}

		void DirtAmount(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleDirtamount), &Value, sizeof(float), NULL);
		}

		float BrakeForce()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingBrakeforce), &value, sizeof(float), NULL);
			return value;
		}

		void BrakeForce(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingBrakeforce), &Value, sizeof(float), NULL);
		}

		float HandbrakeForce()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingHandbrakeforce), &value, sizeof(float), NULL);
			return value;
		}

		void HandbrakeForce(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingHandbrakeforce), &Value, sizeof(float), NULL);
		}

		float Mass()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingMass), &value, sizeof(float), NULL);
			return value;
		}

		void Mass(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingMass), &Value, sizeof(float), NULL);
		}

		float CollisionDamage()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingCollissionDamage), &value, sizeof(float), NULL);
			return value;
		}

		void CollisionDamage(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingCollissionDamage), &Value, sizeof(float), NULL);
		}

		float WeaponDamage()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingWeaponDamage), &value, sizeof(float), NULL);
			return value;
		}

		void WeaponDamage(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingWeaponDamage), &Value, sizeof(float), NULL);
		}

		float Deformmp()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingDeformMP), &value, sizeof(float), NULL);
			return value;
		}

		void Deformmp(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingDeformMP), &Value, sizeof(float), NULL);
		}

		float Thrust()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingThrust), &value, sizeof(float), NULL);
			return value;
		}

		void Thrust(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingThrust), &Value, sizeof(float), NULL);
		}

		float ThrustDeluxo()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingThrustDeluxo), &value, sizeof(float), NULL);
			return value;
		}

		void ThrustDeluxo(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingThrustDeluxo), &Value, sizeof(float), NULL);
		}

		bool Godmode()
		{
			bool value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleGodmode), &value, sizeof(bool), NULL);
			return value;
		}

		vector3 XYZ()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_Vehicle_PosX), &values, sizeof(values), NULL);
			return values;
		}

		float X()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_Vehicle_PosX), &value, sizeof(float), NULL);
			return value;
		}

		float Y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_Vehicle_PosY), &value, sizeof(float), NULL);
			return value;
		}

		float Z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Position + ph::Offsets::Player_Vehicle_PosZ), &value, sizeof(float), NULL);
			return value;
		}

		vector3 SpeedXYZ()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleSpeedX), &values, sizeof(values), NULL);
			return values;
		}

		float SpeedX()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleSpeedX), &value, sizeof(float), NULL);
			return value;
		}

		float SpeedY()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleSpeedY), &value, sizeof(float), NULL);
			return value;
		}

		float SpeedZ()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleSpeedZ), &value, sizeof(float), NULL);
			return value;
		}

		float Acceleration()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingAccelerationMP), &value, sizeof(float), NULL);
			return value;
		}

		float TractionMin()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMin), &value, sizeof(float), NULL);
			return value;
		}

		float TractionMax()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMax), &value, sizeof(float), NULL);
			return value;
		}

		float Health()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleHealth1), &value, sizeof(float), NULL);
			return value;
		}

		float Health2()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleHealth2), &value, sizeof(float), NULL);
			return value;
		}

		float Health3()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleHealth3), &value, sizeof(float), NULL);
			return value;
		}

		float Gravity()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Vehicle + ph::Offsets::Player_VehicleGravity), &value, sizeof(float), NULL);
			return value;
		}
	}

	// vehiclenearest
	namespace Vehiclenearest
	{
		void Update()
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info + ph::Offsets::Player_InfoNearestvehicle), &ph::Info.Player_Info_NearestvVehicle, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_Vehicle_Handling), &ph::Info.Player_Info_NearestVehicle_Handling, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_Vehicle_Pos), &ph::Info.Player_Info_NearestVehicle_Position, sizeof(DWORD64), NULL);
		}

		void Godmode(bool value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleGodmode), &value, sizeof(bool), NULL);
		}

		void XYZ(vector3 values)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosX), &values, sizeof(values), NULL);
		}

		void X(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosX), &value, sizeof(float), NULL);
		}

		void Y(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosY), &value, sizeof(float), NULL);
		}

		void Z(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosZ), &value, sizeof(float), NULL);
		}

		void Gravity(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleGravity), &value, sizeof(float), NULL);
		}

		void Acceleration(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Handling + ph::Offsets::Player_Vehicle_HandlingAccelerationMP), &value, sizeof(float), NULL);
		}

		void TractionMin(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMin), &value, sizeof(float), NULL);
		}

		void TractionMax(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMax), &value, sizeof(float), NULL);
		}

		void Health(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleHealth1), &value, sizeof(float), NULL);
		}

		void Health2(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleHealth2), &value, sizeof(float), NULL);
		}

		void Health3(float value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleHealth3), &value, sizeof(float), NULL);
		}

		bool Godmode()
		{
			bool value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleGodmode), &value, sizeof(bool), NULL);
			return value;
		}

		vector3 XYZ()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosX), &values, sizeof(values), NULL);
			return values;
		}

		float X()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosX), &value, sizeof(float), NULL);
			return value;
		}

		float Y()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosY), &value, sizeof(float), NULL);
			return value;
		}

		float Z()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Position + ph::Offsets::Player_Vehicle_PosZ), &value, sizeof(float), NULL);
			return value;
		}

		vector3 SpeedXYZ()
		{
			vector3 values;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleSpeedX), &values, sizeof(values), NULL);
			return values;
		}

		float SpeedX()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleSpeedX), &value, sizeof(float), NULL);
			return value;
		}

		float SpeedY()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleSpeedY), &value, sizeof(float), NULL);
			return value;
		}

		float SpeedZ()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleSpeedZ), &value, sizeof(float), NULL);
			return value;
		}

		float Acceleration()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Handling + ph::Offsets::Player_Vehicle_HandlingAccelerationMP), &value, sizeof(float), NULL);
			return value;
		}

		float TractionMin()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMin), &value, sizeof(float), NULL);
			return value;
		}

		float TractionMax()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestVehicle_Handling + ph::Offsets::Player_Vehicle_HandlingTractionMax), &value, sizeof(float), NULL);
			return value;
		}

		float Health()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleHealth1), &value, sizeof(float), NULL);
			return value;
		}

		float Health2()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleHealth2), &value, sizeof(float), NULL);
			return value;
		}

		float Health3()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleHealth3), &value, sizeof(float), NULL);
			return value;
		}

		float Gravity()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_Info_NearestvVehicle + ph::Offsets::Player_VehicleGravity), &value, sizeof(float), NULL);
			return value;
		}
	}

	namespace Weapon
	{
		void Update()
		{
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player + 0x10C8), &ph::Info.Player_WeaponInfo, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + 0x20), &ph::Info.Player_WeaponInfo, sizeof(DWORD64), NULL);

			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + 0x60), &ph::Info.Player_WeaponInfo_Ammoinfo, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + 0x8), &ph::Info.Player_WeaponInfo_Ammoinfo, sizeof(DWORD64), NULL);
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + 0x0), &ph::Info.Player_WeaponInfo_Ammoinfo, sizeof(DWORD64), NULL);
		}

		void Damage(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoDamage), &Value, sizeof(float), NULL);
		}

		void Ammo(int value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + ph::Offsets::Player_WeaponInfo_AmmoInfoAmmo), &value, sizeof(int), NULL);
		}

		void Reload(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoReload), &Value, sizeof(float), NULL);
		}

		float Mass()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoMass), &value, sizeof(float), NULL);
			return value;
		}

		void Mass(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoMass), &Value, sizeof(float), NULL);
		}

		float Muzzlevel()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoMuzzleVel), &value, sizeof(float), NULL);
			return value;
		}

		void Muzzlevel(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoMuzzleVel), &Value, sizeof(float), NULL);
		}

		float Recoil()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoRecoil), &value, sizeof(float), NULL);
			return value;
		}

		void Recoil(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoRecoil), &Value, sizeof(float), NULL);
		}

		float Range()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoRange), &value, sizeof(float), NULL);
			return value;
		}

		void Range(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoRange), &Value, sizeof(float), NULL);
		}

		float BatchSpread()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoBatchSpread), &value, sizeof(float), NULL);
			return value;
		}

		void BatchSpread(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoBatchSpread), &Value, sizeof(float), NULL);
		}

		float Penetration()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoPenetration), &value, sizeof(float), NULL);
			return value;
		}

		void Penetration(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoPenetration), &Value, sizeof(float), NULL);
		}

		float ForcOnPed()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoForceOnPed), &value, sizeof(float), NULL);
			return value;
		}

		void ForcOnPed(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoForceOnPed), &Value, sizeof(float), NULL);
		}

		float ForceOnVehicle()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoForceOnVehicle), &value, sizeof(float), NULL);
			return value;
		}

		void ForceOnVehicle(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoForceOnVehicle), &Value, sizeof(float), NULL);
		}

		float ForceOnHeli()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoForceOnHeli), &value, sizeof(float), NULL);
			return value;
		}

		void ForceOnHeli(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoForceOnHeli), &Value, sizeof(float), NULL);
		}

		float RocketLifetime()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + ph::Offsets::Player_WeaponInfo_AmmoInfoRocketlifetime), &value, sizeof(float), NULL);
			return value;
		}

		void RocketLifetime(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + ph::Offsets::Player_WeaponInfo_AmmoInfoRocketlifetime), &Value, sizeof(float), NULL);
		}

		float RocketSpeed()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + ph::Offsets::Player_WeaponInfo_AmmoInfoRocketspeed), &value, sizeof(float), NULL);
			return value;
		}

		void RocketSpeed(float Value)
		{
			WriteProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + ph::Offsets::Player_WeaponInfo_AmmoInfoRocketspeed), &Value, sizeof(float), NULL);
		}

		float Damage()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoDamage), &value, sizeof(float), NULL);
			return value;
		}

		float Reload()
		{
			float value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo + ph::Offsets::Player_WeaponInfoReload), &value, sizeof(float), NULL);
			return value;
		}

		int Ammo()
		{
			int value;
			ReadProcessMemory(mem.hProcess, (PBYTE*)(ph::Info.Player_WeaponInfo_Ammoinfo + ph::Offsets::Player_WeaponInfo_AmmoInfoAmmo), &value, sizeof(float), NULL);
			return value;
		}
	}
}
