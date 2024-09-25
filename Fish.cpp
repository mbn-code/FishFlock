#include "Fish.hpp"

void spawnNpcFish(std::vector<Fish> &npcFish, int count) {
    for (int i = 0; i < count; ++i) {
        float offsetX = static_cast<float>(GetRandomValue(0, 100)); // Random offset for X
        float offsetY = static_cast<float>(GetRandomValue(0, 100)); // Random offset for Y

        Fish fish = { 
            { static_cast<float>(GetRandomValue(0, GetScreenWidth() - 100)) + offsetX, 
              static_cast<float>(GetRandomValue(0, GetScreenHeight() - 100)) + offsetY }, 
            { 0, 0 }, 
            2.0f, 
            15.0f, 
            ORANGE 
        };
        npcFish.push_back(fish);
    }
}