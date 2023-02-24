#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Hero.h"
#include "Enemy.h"

void loadResources(void);
void populateWorld(void);

int main(int argc, char* argv[]) {
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
    RM.loadSprite("sprites/testbox-spr.txt", "testbox");
}

void populateWorld(void) {
    new Hero();
    new Enemy();
}
