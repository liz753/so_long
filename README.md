# so_long
Small 2D Game

<div align="center">
<img width="830" alt="Game" src="https://user-images.githubusercontent.com/114035440/213333013-8745d1f6-42f9-41f8-9192-8cc0cd2e8d19.png">
</div>

### Table of Contents

* [Project Overview](#projectoverview)
* [Divide and Conquer](#divide-and-conquer)
* [Bonus](#bonus)
* [Result](#result)
* [Tips for 42 students](#tips-for-42-students)
* [What I learned](#what-i-learned)

## Project Overview
This project is about coding a simple 2D game. The goal is to get familiar with textures, sprites, and some other very basic gameplay elements.
I was free to choose a theme and I decided to let a squirrel collect some nuts in a parc.

For the graphic part of the project I used the library provided by 42 codam: https://github.com/codam-coding-college/MLX42

The game can be played with different maps which are given as arguments to the program. The maps are difined in a ".ber"-file and have certain requirements to fulfill.  

# Map Requirements 
* The map has to be constructed with 3 components: walls, collectibles, and free space.
* The map can be composed of only these 5 characters: 
    0 for an empty space,
    1 for a wall,
    C for a collectible,
    E for a map exit,
    P for the player’s starting position.
* The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
+ The map must be rectangular.
+ The map must be closed/surrounded by walls. If it’s not, the program must return an error.
+ There must be a valid path in the map.
+ You must be able to parse any kind of map, as long as it respects the above rules.
+ If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error   message of your choice.

## Divde and Conquer 

## Bonus 

## Result 

## Tips for 42 students 

## What I learned 
