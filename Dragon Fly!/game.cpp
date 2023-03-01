#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Hero.h"
#include "Enemy.h"
#include "GameState.h"

void loadResources(void);
void populateWorld(void);

int main(int argc, char* argv[]) {
    srand(time(NULL)); // Initialize our random seed
    if (GM.startUp()) {
        LM.writeLog("Error starting game manager!");
        GM.shutDown();
        return 1;
    }

    LM.setFlush(true);
    
    loadResources();
    populateWorld();

    GM.run();

    GM.shutDown();
    return 0;
}

void loadResources(void) {

    // both commented sprites have issues and I an not sure what is wrong with them

    RM.loadSprite("sprites/dragonfly-spr.txt", "dragonfly");
    RM.loadSprite("sprites/dragonflyinvincible-spr.txt", "dragonflyinvincible"); 
    RM.loadSprite("sprites/flower-spr.txt", "flower");
    RM.loadSprite("sprites/bug-spr.txt", "bug");
    RM.loadSprite("sprites/gamestart-spr.txt", "gamestart"); 
    RM.loadSprite("sprites/powerup-spr.txt", "powerup");
    RM.loadSprite("sprites/projectile-spr.txt", "projectile");
}

void populateWorld(void) {
    new GameState();
}
