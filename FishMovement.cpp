#include "FishMovement.hpp"
#include <cmath>
#include <cstdlib> // For rand()

void FishMovement::updateMovement(Fish &fish) {
    if (IsKeyDown(KEY_RIGHT)) {
        fish.velocity.x += fish.speed;
    } else if (IsKeyDown(KEY_LEFT)) {
        fish.velocity.x -= fish.speed;
    } else if (IsKeyDown(KEY_UP)) {
        fish.velocity.y -= fish.speed;
    } else if (IsKeyDown(KEY_DOWN)) {
        fish.velocity.y += fish.speed;
    }
}

void FishMovement::flock(std::vector<Fish> &npcFish) {
    for (auto &fish : npcFish) {
        Vector2 separation = {0, 0};
        Vector2 alignment = {0, 0};
        Vector2 cohesion = {0, 0};
        int neighborCount = 0;

        for (auto &other : npcFish) {
            if (&fish != &other) {
                float distance = sqrt(pow(fish.position.x - other.position.x, 2) + pow(fish.position.y - other.position.y, 2));
                if (distance < 100) { // Neighbor distance threshold
                    if (distance < 40) { // Separation distance threshold
                        separation.x += (fish.position.x - other.position.x) / distance;
                        separation.y += (fish.position.y - other.position.y) / distance;
                    }
                    alignment.x += other.velocity.x;
                    alignment.y += other.velocity.y;
                    cohesion.x += other.position.x;
                    cohesion.y += other.position.y;
                    neighborCount++;
                }
            }
        }

        if (neighborCount > 0) {
            separation.x /= neighborCount;
            separation.y /= neighborCount;
            alignment.x /= neighborCount;
            alignment.y /= neighborCount;
            cohesion.x /= neighborCount;
            cohesion.y /= neighborCount;

            // Adjust separation force based on the number of neighbors
            separation.x *= 10 * neighborCount;
            separation.y *= 10 * neighborCount;

            cohesion.x = (cohesion.x - fish.position.x) / 100;
            cohesion.y = (cohesion.y - fish.position.y) / 100;

            fish.velocity.x += (separation.x * 2.0) + (alignment.x * 0.5) + (cohesion.x * 0.5);
            fish.velocity.y += (separation.y * 2.0) + (alignment.y * 0.5) + (cohesion.y * 0.5);
        }

        avoidBorders(fish);

        // Add some randomness to the movement
        fish.velocity.x += (rand() % 3 - 1) * 0.1;
        fish.velocity.y += (rand() % 3 - 1) * 0.1;

        // Normalize velocity to maintain consistent speed
        float speed = sqrt(fish.velocity.x * fish.velocity.x + fish.velocity.y * fish.velocity.y);
        if (speed > fish.speed) {
            fish.velocity.x = (fish.velocity.x / speed) * fish.speed;
            fish.velocity.y = (fish.velocity.y / speed) * fish.speed;
        }

        fish.position.x += fish.velocity.x;
        fish.position.y += fish.velocity.y;
    }
}

void FishMovement::avoidBorders(Fish &fish) {
    float borderThreshold = 50.0f;
    float lerpFactor = 0.1f;

    if (fish.position.x < borderThreshold) {
        fish.velocity = lerp(fish.velocity, {fish.speed, fish.velocity.y}, lerpFactor);
    } else if (fish.position.x > GetScreenWidth() - borderThreshold) {
        fish.velocity = lerp(fish.velocity, {-fish.speed, fish.velocity.y}, lerpFactor);
    }

    if (fish.position.y < borderThreshold) {
        fish.velocity = lerp(fish.velocity, {fish.velocity.x, fish.speed}, lerpFactor);
    } else if (fish.position.y > GetScreenHeight() - borderThreshold) {
        fish.velocity = lerp(fish.velocity, {fish.velocity.x, -fish.speed}, lerpFactor);
    }
}

Vector2 FishMovement::lerp(Vector2 start, Vector2 end, float t) {
    return { start.x + t * (end.x - start.x), start.y + t * (end.y - start.y) };
}