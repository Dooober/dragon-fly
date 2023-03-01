#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Hero.h"
#include "Enemy.h"
#include "GameStart.h"

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
    RM.loadSprite("sprites/dragonfly-spr.txt", "dragonfly");
    RM.loadSprite("sprites/dragonflyinvincible-spr.txt", "dragonflyinvincible"); 
    RM.loadSprite("sprites/flower-spr.txt", "flower");
    RM.loadSprite("sprites/bug-spr.txt", "bug");
    RM.loadSprite("sprites/gamestart-spr.txt", "gamestart"); 
    RM.loadSprite("sprites/powerup-spr.txt", "powerup");
    RM.loadSprite("sprites/projectile-spr.txt", "projectile");
    RM.loadSprite("sprites/gameover-spr.txt", "gameover");
}

void populateWorld(void) {
    new GameStart();
}
