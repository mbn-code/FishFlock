#ifndef FISHMOVEMENT_HPP
#define FISHMOVEMENT_HPP

#include "Fish.hpp"
#include <vector>

class FishMovement {
public:
    void updateMovement(Fish &fish);
    void flock(std::vector<Fish> &npcFish);
    void avoidBorders(Fish &fish);
    Vector2 lerp(Vector2 start, Vector2 end, float t);
};

#endif // FISHMOVEMENT_HPP