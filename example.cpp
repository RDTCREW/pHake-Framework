#include <iostream>
#include "SDK/GameInfo.hpp"
 
int main()
{
	GameData game;
	game.init();
	game.update();
	
	game.player.health(game.player.healthMax()); // Setting maximum health 
	
	game.playerWeaponInfo.bulletDamage(99999.f); // Changing stats of current weapon
	game.playerWeaponInfo.reloadMP(99999.f);
	game.playerWeaponInfo.range(99999.f);
	
	game.playerVehicle.gravity(25.f); // Changing car gravity
	
	return 0;
}
