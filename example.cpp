#include "Framework/Memory/info.h"
#include "Framework/Game/game.h"
 
int main()
{
	ph::Info.Init("GTA5.exe");
 
	ph::Player::Health(ph::Player::Health() + 50.f);
 
    	ph::Weapon:.Update();
   	ph::Weapon::Ammo(9999);
 
	ph::Vehicle::Update();
	ph::Vehicle::Gravity(-5.f);
       
 
	return 0;
}
