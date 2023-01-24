# so_long
Small 2D Game

<div align="center">
<img width="830" alt="Game" src="https://user-images.githubusercontent.com/114035440/213333013-8745d1f6-42f9-41f8-9192-8cc0cd2e8d19.png">
</div>

## Table of Contents

* [Project Overview](#project-overview)
* [Divide and Conquer](#divide-and-conquer)
* [Bonus](#bonus)
* [Result](#result)
* [Tips for 42 students](#tips-for-42-students)
* [What I learned](#what-i-learned)

## Project Overview
This project is about coding a simple 2D game à la Pac-Man. The player’s goal is to collect every collectible present on the map, then escape choosing the shortest possible route.

My goals in coding the game is to get familiar with textures, sprites, and some other very basic gameplay elements (and get my nieces and nephews amused).
I was free to choose a theme and I decided to let a squirrel collect some nuts in a parc.

For the graphic part of the project I used the library provided by 42 codam: https://github.com/codam-coding-college/MLX42

The game can be played with different maps which are given as arguments to the program. The maps are difined in a ``.ber``-file and have certain requirements to fulfill.  

### Map Requirements 
* The map has to be constructed with 3 components: walls, collectibles, and free space.
* The map can be composed of only these 5 characters: 
    ``0`` for an empty space,
    ``1`` for a wall,
    ``C`` for a collectible,
    ``E`` for a map exit,
    ``P`` for the player’s starting position.
* The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
* The map must be rectangular.
* The map must be closed/surrounded by walls. If it’s not, the program must return an error.
* There must be a valid path in the map.
* You must be able to parse any kind of map, as long as it respects the above rules.
* If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return ``Error\`` followed by an explicit error   message of your choice.

## Divide and Conquer 
I got started with a to-do-list that I then worked off bit by bit:

<ins>1. Theme and Graphics</ins>
*   choice of theme 
*   image research 
*   image manipulation using GIMP (transparency and resizing)

<ins>2. Code Structure</ins>
*   create a Makefile that doesn't relink
*   create a header file 

<ins>3. Parsing</ins>
*   read the map file with the C-functions ``open`` and ``read`` and store its content in a string
*   store the map in a 2D-array
*   check that the map is valid (see requirements above)
*   check that the path is valid (all collectibles and exit reachable) using floodfill
*   implement error messages

<ins>4. Game Coding</ins>
*   keyboard input (``W`` ``A`` ``S`` ``D`` + arrow keys for moving and ``ESC`` for closing the game)
*   image conversion to ``.xpm42`` using ``xpm3_conv.py``-file of the MLX42
*   initialization of assets (in this case only images)
*   rendering 
*   implement the hooks
*   display the movement count in the shell
*   display messages in the shell (a)when player wants to go on exit before collecting all the collectibles, b) when the player collected them all, c) when     the player quit the game before finishing and d)when the player won the game)
*   add more maps

<ins>5. Bonus</ins>
*   add an enemy patrol as a character (X)
*   implement enemys random movements 
*   collision detection
*   add some sprite animation (enemy will get agitated when player collected 3 collectibles)
*   display movement count + collectible count + messages in window 
*   design "You won"-image und "Game Over"-image and display them accordingly in the window 

## Bonus 
<div align="center">
<img width="575" alt="Game_bonus" src="https://user-images.githubusercontent.com/114035440/213343266-3b0d36bd-a0f5-4362-b8f2-b6bb08316dbc.png">
</div>

## Result 

Here is a sample gameplay of the original game (without the bonus part):
![Game](https://user-images.githubusercontent.com/114035440/213477897-520b5c5a-4d84-469c-b686-23b607d1ed83.gif)

Here are some sample gameplays with the bonus part:

![fw7hl-vaxu1](https://user-images.githubusercontent.com/114035440/213476899-ec70c44e-fdd8-4d48-a855-b67acf33e335.gif)


![pz2lz-22ycj](https://user-images.githubusercontent.com/114035440/213475698-e9776bae-260d-4613-8ef6-eefebbea8858.gif)


![uh8ub-d2vw5](https://user-images.githubusercontent.com/114035440/213786640-c86e3474-1e1f-4b62-ba87-57c3fd4034f2.gif)



## Tips for 42 students 
*   if you haven't worked with structs before, take the opportunity to do so at the beginning of the project, you will need them
*   before coding a new function, think of the functions you already have in libft and see if you can use them (obviously you can also use ft_printf und       get_next_line for this project), HOWEVER: every problem can be solved in different ways, so don't feel obligated to use code from previous projects if     you think of a better solution (for example, I preferred to read the file character by character and put it in one string first before converting it       to a 2D-array instead of using gnl)
*   concerning the images, my first reflex was to allocate memory on the heap every loophook but it's more convenient and less risky for leaks to simply       put them in a struct as pointer to ``mlx_image_t``
*   at the beginning, the players movement lagged a bit because of the rendering queue that kept growing, so I decided to delete and rerender the images       at every hook (however a better approach would be to delete and rerender only when something moves)
*   for the enemy movement I used the C-function ``rand()`` to decide in which direction the enemy would move. The enemy can move one tile at a time in       any direction. To achieve this, I needed a random number between -1 and 1, which I obtained using this formula: ``(rand() % 3) - 1``. I then added         the randomly generated number to the x and y coordinates of the enemy to make it move accordingly. This means it can also move diagonally.
*   for the sprite animation, I alternate between two images at a given frequency. This frequency is determined using a gameloop-count and a speed             variable. Every loop, I check if the result of ``gameloop-count % speed`` is over or under half the speed. One image or the other is shown                 respectively
*   make sure you clean your old assets and messages/strings that you put in the window, you can use the MLX42-function ``mlx_delete_image`` to do so
*   for leaks detection I used ``leaks -atExit -- ./so_long [a map-file]`` instead of valgrind. Xcode’s leaks function is a very handy tool and is already     preinstalled on the school computers

## What I learned 
I learned how to manipulate images using GIMP.
I digged into the cross-platform graphics interface MLX42. I learned how to deal with textures, images and pixels. Plus, I learned how to use hooks, structs and random numbers. I learned how to implement error management and think about the edge cases. I improved my understanding of the Makefile and adopted the habit of testing my code after every change the hard way. Finally, I deepened my understanding of the heap and the stack. I learned to avoid heap allocation when possible. 
All in all, I really enjoyed this project because of its concrete output and liked it the most of all the 42 projects so far.
