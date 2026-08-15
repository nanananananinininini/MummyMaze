#include<bits/stdc++.h>
using namespace std;

//*-------------------------------------------------------*//
char maze[30][50] =
{
    "####################",
    "#..................#",
    "#..e..m............#",
    "#.......#...#......#",
    "#..#......##...#...#",
    "#..................#",
    "#...###.....#......#",
    "#.p................#",
    "#.....###...#......#",
    "####################",
};

int prow = 7, pcol = 2;  // Player initial position
int mrow = 2, mcol = 6;  // Mummy initial position
int erow = 2, ecol = 3;  // Exit/treasure position
int MAZER = 10, MAZEC = 20;  // Maze dimensions
//*---------------------CONFIG AREA ENDING-----------------*//

bool gameover();
void showmap();
void pmove(char direction); // w = up, s = down, a = left, d = right
void mmove();

int main()
{
    char dire;

    while(!gameover())
    {
        system("cls");
        showmap();
        cout << "Enter [w|a|s|d] to move: ";
        cin >> dire;
        pmove(dire);

        // The mummy moves twice per turn
        for(int i = 0; i < 2; i++) {
            if(gameover()) break; // Stop moving if game has already ended
            mmove();
        }
    }
    system("cls");
    showmap();

    // Determine win or lose
    if(prow == erow && pcol == ecol) {
        cout << "Congratulations!" << endl;
    } else if(prow == mrow && pcol == mcol) {
        cout << "You were caught by the mummy! Game Over!" << endl;
    }
    return 0;
}

void showmap()
{
    for(int i = 0; i < MAZER; i++)
    {
        for(int j = 0; j < MAZEC; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool gameover()
{
    if((prow == mrow && pcol == mcol) || (prow == erow && pcol == ecol))
    {
        return true;
    }
    return false;
}

void pmove(char direction)
{
    int nrow = prow, ncol = pcol;
    if(direction == 'w') nrow--;
    if(direction == 's') nrow++;
    if(direction == 'a') ncol--;
    if(direction == 'd') ncol++;
    
    // Check wall and boundary
    if(maze[nrow][ncol] != '#')
    {
        maze[prow][pcol] = '.';
        prow = nrow;
        pcol = ncol;
        // Don't overwrite the exit 'e' if player is on it
        if(!(prow == erow && pcol == ecol))
            maze[prow][pcol] = 'p';
    }
}


void mmove()
{
    // Clear the mummy's previous position
    if(!(mrow == prow && mcol == pcol))
        maze[mrow][mcol] = '.';

    if(mrow != prow) // Different rows, horizontal movement has priority
    {
        if(mcol > pcol && maze[mrow][mcol-1] != '#' && !(mrow == prow && mcol-1 == pcol))
            mcol--;
        else if(mcol < pcol && maze[mrow][mcol+1] != '#' && !(mrow == prow && mcol+1 == pcol))
            mcol++;
        else if(mrow > prow && maze[mrow-1][mcol] != '#' && !(mrow-1 == prow && mcol == pcol))
            mrow--;
        else if(mrow < prow && maze[mrow+1][mcol] != '#' && !(mrow+1 == prow && mcol == pcol))
            mrow++;
    }
    else // Same row, vertical movement
    {
        if(mcol > pcol && maze[mrow][mcol-1] != '#' && !(mrow == prow && mcol-1 == pcol))
            mcol--;
        else if(mcol < pcol && maze[mrow][mcol+1] != '#' && !(mrow == prow && mcol+1 == pcol))
            mcol++;
    }
    
    // Don't draw the mummy if it overlaps with player or exit
    if(!(mrow == prow && mcol == pcol) && !(mrow == erow && mcol == ecol))
        maze[mrow][mcol] = 'm';
}
