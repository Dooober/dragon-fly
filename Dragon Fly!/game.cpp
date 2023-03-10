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
    RM.loadSprite("sprites/flower-spr.txt", "flower");
    RM.loadSprite("sprites/bug-spr.txt", "bug");
    RM.loadSprite("sprites/gamestart-spr.txt", "gamestart"); 
    RM.loadSprite("sprites/powerup-spr.txt", "powerup");
    RM.loadSprite("sprites/projectile-spr.txt", "projectile");
    RM.loadSprite("sprites/boss-spr.txt", "boss");

    RM.loadSound("sounds/boss-attack-sound.wav", "attack");
    RM.loadSound("sounds/projectile-sound.wav", "shoot");
    RM.loadSound("sounds/powerup-sound.wav", "powerup");
    RM.loadMusic("sounds/boss-music.wav", "boss");
    RM.loadMusic("sounds/main-menu-music.flac", "menu");
    RM.loadMusic("sounds/normal-music.flac", "normal");
}

void populateWorld(void) {
    new GameStart();
}
