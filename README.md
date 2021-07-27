README FOR CW2

URL of git repo: https://gitlab.com/comp1921_2021/sc20jdpn/-/tree/master/CW2

Screenshot of commit history:
<img src="/CW2/commitHistory.png">

Please note all testing was hard-coded into source code.

How to use the program:

The game is loaded from a txt file ("game_store.txt") that includes the information to create a game. This is structures like so;

- All numbers are placed on a single line and are seperated by a single space " ".
- The first number ( n ) is the size of the grid (the grid is always a square so this determins height and width).
- The next ( n * n ) numbers are the starting state of each of the cells in the grid ( 1 = alive / white, 0 = dead / black ). These are loaded in left-to-right.
- The final number corresponds to the number of generations you want to calculate.

The program can be compiled using the usual "gcc main.c logic.c graphics.c -o GOL -lSDL2" and then run with ./GOL

Or alternatively use the CMakeLists.txt to build the program (also called GOL)
This requires;
- making a new directory called build ( mkdir build )
- moving into this directory ( cd build )
- running cmake on the prev directory ( cmake .. )
- then finally ( make )

- This should create a build called GOL which can be run using ( ./GOL )
- However beforehand you need to create a "game_store.txt" according to the instructions above and move this into the build directory.
- OR you can simply move the one i have saved in my repo which is for a simple glider on an 8x8 grid for 10 generations.

Finally after the execution is finished the final state will be saved in "save_store.txt" in the same format as the "game_store" that was loaded into the program to start with,.




