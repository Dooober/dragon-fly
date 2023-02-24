#include "GameManager.h"
<<<<<<< HEAD
#include "LogManager.h"
#include "ResourceManager.h"
#include "Hero.h"

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
}

void populateWorld(void) {
    new Hero();
=======
#include "WorldManager.h"
#include "LogManager.h"
#include "DisplayManager.h"

int main() {
	GM.startUp();
	LM.writeLog("%d", WM.getBoundary().getHorizontal());
	GM.shutDown();
>>>>>>> 457494518b428d8cad639214a2e7531218126f7d
}