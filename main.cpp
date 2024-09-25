#include <raylib.h>
// #include <raymath.h>

// standard libraries
#include <iostream>
#include <vector>

// own headers and files
#include "include/Fish.hpp"
#include "include/FishMovement.hpp"

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

void PlayerCollision(Fish &playerFish, std::vector<Fish> &npcFish) {
    // collision between playerFish and npcFish. if true. push npcFish away from playerFish
    for (auto &fish : npcFish) {
        float distance = sqrt(pow(playerFish.position.x - fish.position.x, 2) + pow(playerFish.position.y - fish.position.y, 2));
        if (distance < playerFish.radius + fish.radius) {
            Vector2 direction = { playerFish.position.x - fish.position.x, playerFish.position.y - fish.position.y };
            float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
            direction.x /= length;
            direction.y /= length;
            fish.position.x -= direction.x * 2;
            fish.position.y -= direction.y * 2;
        }
    }
}

void update() {
    FishMovement fishMovement;
    fishMovement.updateMovement(playerFish);
    playerFish.position.x += playerFish.velocity.x;
    playerFish.position.y += playerFish.velocity.y;

    fishMovement.flock(npcFish);

    DrawCircleV(playerFish.position, playerFish.radius, playerFish.color);

    PlayerCollision(playerFish, npcFish);

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

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Fiske Flok");

    SetTargetFPS(120);

    spawnNpcFish(npcFish, 30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);

        update();

        for (auto &fish : npcFish) {
            DrawCircleV(fish.position, fish.radius, fish.color);
        }

        EndDrawing();

        // keybindings for spawning npcFish
        if (IsKeyPressed(KEY_SPACE)) {
            spawnNpcFish(npcFish, 1);
        } else if (IsKeyPressed(KEY_BACKSPACE)) {
            npcFish.pop_back();
        } else if (IsKeyPressed(KEY_R)) {
            npcFish.clear();
            spawnNpcFish(npcFish, 5);
        }

        // keybindings for UI
        if (IsKeyPressed(KEY_F)){
            ToggleFullscreen();
        } 

        // keybindings for help menu 
        if (IsKeyPressed(KEY_H)) {
            const char* helpText[] = {
                "Press SPACE to spawn a fish",
                "Press BACKSPACE to remove a fish",
                "Press R to reset the fish",
                "Press F to toggle fullscreen",
                "Press H to show this help menu"
            };

            const int numLines = sizeof(helpText) / sizeof(helpText[0]);
            const int fontSize = 20;
            const int padding = 10;
            const int boxWidth = 400;
            const int boxHeight = (fontSize + padding) * numLines + padding;
            const int boxX = (GetScreenWidth() - boxWidth) / 2;
            const int boxY = (GetScreenHeight() - boxHeight) / 2;

            DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.7f));
            for (int i = 0; i < numLines; ++i) {
                DrawText(helpText[i], boxX + padding, boxY + padding + i * (fontSize + padding), fontSize, WHITE);
            }

            // Wait for a couple of seconds
            float startTime = GetTime();
            while (GetTime() - startTime < 3.0f) {
                BeginDrawing();
                ClearBackground(BLUE);

                // Redraw the help menu
                DrawRectangle(boxX, boxY, boxWidth, boxHeight, Fade(BLACK, 0.7f));
                for (int i = 0; i < numLines; ++i) {
                    DrawText(helpText[i], boxX + padding, boxY + padding + i * (fontSize + padding), fontSize, WHITE);
                }

                EndDrawing();
            }
        }


    }

    CloseWindow();
}

int main() { 
    start();
    return 0;
}