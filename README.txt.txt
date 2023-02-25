Dragon Fly!
by Cooper Dean (cjdean@wpi.edu) and Christian Reynolds (cjreynolds1@wpi.edu)

Platform: Windows x64

To compile the game use the solution file in "Dragon Fly!/Dragon Fly!.sln"
Build and run in Visual Studio

We used Cooper's engine to make the game
--------------
File Structure:
/Dragon Fly! - Folder for the game itself
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
Hero - the dragonfly hero
PowerUp - a base class for powerups
Score - the score ViewObject
Enemy - a base class for enemy types
 - Flower - a tall enemy that "stays still"
 - Bug - a smaller enemy that moves up and down

