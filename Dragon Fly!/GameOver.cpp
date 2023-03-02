#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "GameOver.h"
#include "GameStart.h"
#include "Score.h"

GameOver::GameOver() {
    setType("GameOver");
    setSprite("gameover");
    setLocation(df::CENTER_CENTER);

    df::ObjectList score_list = WM.objectsOfType("ViewObject");
    df::ObjectListIterator sli(&score_list);
    Object* p_o = sli.currentObject();
    const Score* p_score = dynamic_cast <Score const*> (p_o);
    int value = p_score->getValue();

    df::ObjectList object_list = WM.getAllObjects();
    df::ObjectListIterator li(&object_list);
    for (li.first(); !li.isDone(); li.next()) {
        if (li.currentObject()->getId() != p_o->getId()) {   
            WM.markForDelete(li.currentObject());
        }
    }


    RM.getMusic("boss")->stop();
    RM.getMusic("normal")->stop();
    RM.getSound("attack")->stop();

    new GameStart();
}

GameOver::~GameOver() {}

int GameOver::draw() {
    return df::Object::draw();
}
