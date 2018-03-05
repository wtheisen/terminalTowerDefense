### Terminal Tower Defense

# Collaborators: Alex Brizius, William Theisen, Michael Burke, Jose Badilla


This video game is our own version of _Tower Defense_, the popular subgenre of strategy video game.

The instructions for playing and deploying this videogame are the following:

1.) Compile the videogame by typing **make** inside the root directory of the project.

2.) Run the executable **game** in order to start the video game.

3.) You will then arrive at the title screen, which includes the names of the collaborators and developer. Press the enter key to continue.

4.) The randomly-generated map will now be displayed, and the terminal will prompt you to place 3 towers. Place each tower by clicking on one of the hashes and then clicking anywhere on the terminal screen to rotate it. When you are satisfied with your selection, press the enter key; this will prompt you to place the remaining towers.

5.) Once you place the final tower and press the enter key, the simulation will begin and the enemies will spawn. Each tower will shoot within a range of exactly three spots in front of it on every 3rd iteration.

6.) For each enemy that your tower kills, you will obtain an _energy point_. Upon obtaining 5 energy points, you will have the chance at the end of the current wave of enemies to place the number of towers corresponding to the number of energy points you have. Upon placing your last tower, the simulation will continue.

7.) The game ends when 10 enemies have reached the base.


####TODO:
1.) Create a window/menu heirarchy
2.) Draw a grid on the screen
3.) Draw the path based on the level gen
4.) Framework for waves and rest periods
5.) Architecture for objects (enemies, towers, bullets)
