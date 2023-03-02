Dragon Fly!
by Cooper Dean (cjdean@wpi.edu) and Christian Reynolds (cjreynolds1@wpi.edu)

Platform: Windows x64

To compile the game use the solution file in "Dragon Fly!/Dragon Fly!.sln"
Build and run in Visual Studio

We used Cooper's engine to make the game
--------------
File Structure:
/Dragon Fly! - Folder for the game itself
 - /sounds - sound and music files
 - /sprites - sprite files
 - game.cpp - the start point for the game
 - All .cpp and .h files are included directly in this folder
/dragonfly-engine - Folder for all engine files
 - /Include - all .h files for the engine
 - /Lib - the .lib file for the engine code
/SFML-2.5 - The SFML version that the engine was developed using
.gitignore
Readme.txt

--------------
Classes included in the game:

GameStart - start menu for the game, once play is pressed the game starts
GameOver - script that runs when the game ends due to player death
GameState - state machine for the game itself, controlls normal gameplay vs boss encounters
Hero - the dragonfly hero
PowerUp - powerup object on screen
PowerUpString - ViewObject that shows the time left of the powerup
Score - the score ViewObject
Boss - a boss using a finite state machine
Projectile - a projectile that the boss shoots at the player
Enemy - a base class for enemy types
Flower - a tall enemy that "stays still"
Bug - a smaller enemy that moves up and down
EventBossKill - Event triggered when the boss is killed
EventClear - Event triggered when needing to clear all enemies off the screen
EventPowerUpEnd - Event triggered when the powerup timer completes

