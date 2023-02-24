#include "GameManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "DisplayManager.h"

int main() {
	GM.startUp();
	LM.writeLog("%d", WM.getBoundary().getHorizontal());
	GM.shutDown();
}