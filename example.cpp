#include <iostream>
#include "Memory/Process.h"
#include "SDK/World.hpp"

int main()
{
	Process mem;

	if (!mem.getProcess("GTA5.exe"))
		std::cout << "Failed to handle Game";

	World world = World(mem.handle);
	world.updateSub(mem.read<uint64_t>(mem.base + 0x024B0C50)); // Steam World Pointer

	world.localPlayer.god(true);
	world.localPlayer.position.xyz(vec3(1000, 1000, 50));
	world.localPlayer.weaponManager.currentWeapon.bulletDamage(1000);

	return 0;
}
