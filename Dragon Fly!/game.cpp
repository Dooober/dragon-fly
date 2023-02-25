#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Hero.h"
#include "Enemy.h"
#include "GameStart.h"

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
    RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");
    //RM.loadSprite("sprites/gamestart-spr1.txt", "gamestart"); 
    // somethings wrong with this sprite (going to fix it later so just using the saucer shoot one to test code)
}

void populateWorld(void) {
    new GameStart();
}
