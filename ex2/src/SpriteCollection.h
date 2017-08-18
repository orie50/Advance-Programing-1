#ifndef ASS2_SPRITECOLLECTION_H
#define ASS2_SPRITECOLLECTION_H

#include "Sprite.h"
#include <vector>

using namespace std;

class SpriteCollection {
private:
    vector <Sprite*> collection;
public:
    SpriteCollection(){};
    void addSprite(Sprite* sprite);
    void removeSprite(Sprite* sprite);
    void notifyAllTimePassed();
};

#endif //ASS2_SPRITECOLLECTION_H
