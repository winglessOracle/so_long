# so_long | CODAM Amsterdam (part of 42 network)

*And thanks for all the fish! 🐟*

### Table of Contents

* [Introduction](#introduction)
* [How it Works](#how-it-works)
* [Extras](#extras)
* [Gameplay](#gameplay)
* [Learnings](#learnings)

## Introduction
so_long is an assignment for CODAM in which we are tasked to create a simple 2D game to get familiar with a graphics library. At CODAM we have access to the the MLX42 library which can be found at [here: MLX42](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md). 

The goal is for the player to open and reach the exit by collecting all the collectibles in the least possible number of steps. Steps should be printed in the terminal or on the game screen (bonus).

### Requirements
The game must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only the `P` (player), `1` (wall), `0` (empty), `C` (collectible), and `E` (exit) are accepted as characters in the map. An exception is if you add enemy patrolls as part of the bonus assignment in which case you can use other characters (I added the emenies without introducing other characters). 
- The map must be rectangular.
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed by walls. (I took a liberal approach that the `P`, `E` and `C` characters need to be inclosed by walls).
- The map must have a valid sollution allowing the player to collect all collectible items and reach the exit afterwards.

Error handeling on all of these checks must exit the game in a clean manner and display `Error\n` followed by a custom message.

## How it Works

### Reading the map
After checking the parameters and extention (.ber) I allocate a struct t_g where I store all relevant game date. I initialize the underlying variables and allocate a few more structs for specific game data like player and emeny data. I then used the [get_next_line](https://github.com/winglessOracle/get_next_line) function (an earlier project) to read and store the map data into one string which I then split (`ft_split`) into a 2 dimensiona array giving me a x,y grid of the map. I then check the map on the abovementioned requirements. A final test is done to determine if the map has a valid sollution using a flood-fill function. 

### Starting the game
If all checks are passed the MLX window is initilized,the game textures are loaded en then drawn to images which are placed in the window.

### Playing the game
Keybinding:
-  Arrow keys and `W A S D` controle player movement.
- 'Space` resets the current level.
- `ESC` ends the game.

If there are no collectibles left, the exit will open and the player can now pass through to the next level. I only created three levels and after the last level a closing screen is displayed.

Enemies spawn on collectables and patrol in horizontal or vertical lines depending on their instance number being odd or even. Whenever the player touches an enemie a heart is lost. When all three hearts are lost the player looses the game and an end screen is displayed.


### Animations
Both the enemies and the player have three textures per walking direction that are alternated as they move (bonus). This is done using an image counter to draw different textures to the images instances.

The player and the enemies have a window location used to draw and move them and a grid coordinate x and y for checking valid moves and collisions.

## Extras
The small game has a few extras that were not part of the assignment but that I found intresting or fun to add.

- Ability to restart the game by pressing the `Space` key.
- A life counter.
- End screens after death of finishing the game.
- Compilation support for both `linux` and `MacOS`
-Added maps as levels that you progress through.

## Gameplay

Here are a few sample gameplays clips:
[test](/home/carlo/Desktop/link to Projects./so_long/example.gif

## Installing the MLX library and required recourses
Please read the documentation for this in the [MLX42 repository](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md). It is self explenatory.

Cone this repository and run the make command. This works on MacOs and Linux. 
For windows please check the right installation requirements and compilation flags in the abovementioned documentation for [MLX42](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md).

Then just use the `make` command to compile the so_long executable using the MLX42 lib.

## Learnings

Here is an overview of things I learned and ran into during this project.

- Timing: use the MLX_GET_TIME function for timing of animations and checks.
- Use the MLX42 library instead of minilibx. It is more stable, has less inhearent leaks better documented and easy to use.
- Leaks: in MacOs use the `atexit` commmand to set the leaks command. In Linux stick to Valgrind. In general MLX42 cleans itself but the textures still need to be cleaned using the `MLX_DELETE_TEXTURE` command.
- Feature creep. I had to set constraints on what I wanted to hand in as a prohject as there are so much fun and interesting things to add.

Jan 2023

For more information visit: [Codam.nl](https://codam.nl/) or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs).
