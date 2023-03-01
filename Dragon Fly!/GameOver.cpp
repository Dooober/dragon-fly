#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameOver.h"
#include "GameStart.h"

GameOver::GameOver() {
    setType("GameOver");
    setSprite("gameover");
    setLocation(df::CENTER_CENTER);

    df::ObjectList object_list = WM.getAllObjects();
    df::ObjectListIterator li(&object_list);
    for (li.first(); !li.isDone(); li.next()) {
        if (li.currentObject()->getType() != "GameOver") {   
            WM.markForDelete(li.currentObject());
        }
    }
    WM.markForDelete(this);
    new GameStart();
}

GameOver::~GameOver() {}

int GameOver::draw() {
    return df::Object::draw();
}
