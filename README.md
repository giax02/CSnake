# CSnake
An implementation of the classic snake game in plain C

The entire program is made in C using only standard libraries such as stlib.h, time.h, windows.h and so on.
The shell is used as a GUI and so the UX isn't that great but its very vintage looking.

Since default terminal font character in windows are not square you need to go to the terminal properties by clicking on the little icon
on the upper left corner and selecting RASTER FONT as the font type and 8x8 as the font size.

### Installing 
1. Compiling:
    You can easily compile the entire program with any C compiler without the need of any external lib.
    All the project files are provided in the repository.
    You can compile using:
    
    ```sh
   gcc main.c functions.c -o CSnake -Wall
   ```
2. Pre compiled release:
    You can just execute the CSnake.exe release that you can find under "releases"

### How to play
1. Controls:
    "WASD" are used to control the direction of the snake.
2. Game mechanics:
    Eat all the apples to increase the score.
    Every time you eat an apple the lenght of the snake will increase.
    If you touch the edge of the map or you "eat" yourself you die.
    
WARNING! IT ONLY WORKS OF WINDOWS!

Authors: @GiacomoL02 and @Gabry-xdvr 
Link to his version: https://github.com/Gabry-xdvr/Snake
