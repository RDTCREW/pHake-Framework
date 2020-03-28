#include <iostream>
#include "SDK/GameInfo.hpp"
 
int main()
{
	GameData game;
	game.init();
	
	game.player.health(game.player.healthMax()); // Settings Max Health 
	
	game.playerWeaponInfo.bulletDamage(99999.f); // Changing current Weaponstats
	game.playerWeaponInfo.reloadMP(99999.f);
	game.playerWeaponInfo.range(99999.f);
	
	game.playerVehicle.gravity(25.f); // Changing car gravity
	
	return 0;
}
