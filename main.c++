#include <raylib.h>
// #include <raymath.h>

// standard libraries
#include <iostream>
#include <vector>

// own headers and files
#include "Fish.hpp"
#include "FishMovement.hpp"

// main character (me)
Fish playerFish = { { 400, 200 }, { 0, 0 }, 0.1, 20, GREEN };
// npc fish get handled in the Fish.cpp 
std::vector<Fish> npcFish;

class Flock {
public:
    void update() {
        FishMovement fishMovement;
        fishMovement.flock(npcFish);
    }

    void draw() {
        for (auto &fish : npcFish) {
            DrawCircleV(fish.position, fish.radius, fish.color);
        }
    }
};

void BoarderCheck();

class playerMovement {
public:
    void updateMovement(Fish &fish) {
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
};

void update() {
    FishMovement fishMovement;
    fishMovement.updateMovement(playerFish);
    playerFish.position.x += playerFish.velocity.x;
    playerFish.position.y += playerFish.velocity.y;

    fishMovement.flock(npcFish);

    DrawCircleV(playerFish.position, playerFish.radius, playerFish.color);

    BoarderCheck();
}

void BoarderCheck() {
    // boarder stops playerFish. makes velocity 0 if playerFish hits boarder
    if (playerFish.position.x > GetScreenWidth() - playerFish.radius) {
        playerFish.position.x = GetScreenWidth() - playerFish.radius;
        playerFish.velocity.x = 0;
    } else if (playerFish.position.x < 0 + playerFish.radius) {
        playerFish.position.x = 0 + playerFish.radius;
        playerFish.velocity.x = 0;
    } else if (playerFish.position.y > GetScreenHeight() - playerFish.radius) {
        playerFish.position.y = GetScreenHeight() - playerFish.radius;
        playerFish.velocity.y = 0;
    } else if (playerFish.position.y < 0 + playerFish.radius) {
        playerFish.position.y = 0 + playerFish.radius;
        playerFish.velocity.y = 0;
    }

    // boarder stops npcFish. makes velocity 0 if npcFish hits boarder
    for (auto &fish : npcFish) {
        if (fish.position.x > GetScreenWidth() - fish.radius) {
            fish.position.x = GetScreenWidth() - fish.radius;
            fish.velocity.x = 0;
        } else if (fish.position.x < 0 + fish.radius) {
            fish.position.x = 0 + fish.radius;
            fish.velocity.x = 0;
        } else if (fish.position.y > GetScreenHeight() - fish.radius) {
            fish.position.y = GetScreenHeight() - fish.radius;
            fish.velocity.y = 0;
        } else if (fish.position.y < 0 + fish.radius) {
            fish.position.y = 0 + fish.radius;
            fish.velocity.y = 0;
        }
    }
}

void start() {
    const int screenWidth = 1280;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Fiske Flok");

    SetTargetFPS(120);

    spawnNpcFish(npcFish, 100);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);

        update();

        for (auto &fish : npcFish) {
            DrawCircleV(fish.position, fish.radius, fish.color);
        }

        EndDrawing();
    }

    CloseWindow();
}

int main() { 
    start();
    return 0;
}