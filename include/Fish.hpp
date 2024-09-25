#ifndef FISH_HPP
#define FISH_HPP

#include <raylib.h>
#include <vector>

struct Fish {
    Vector2 position;
    Vector2 velocity;
    float speed;
    float radius;
    Color color;
};

void spawnNpcFish(std::vector<Fish>& npcFish, int count);

#endif // FISH_HPP