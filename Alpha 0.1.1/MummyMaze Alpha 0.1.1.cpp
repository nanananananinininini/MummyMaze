#include<bits/stdc++.h>
using namespace std;

//*-------------------------------------------------------*//
// The maze map only contains static walls '#' and paths '.'
// fix bug #1
char maze[30][50] =
{
    "####################",
    "#..................#",
    "#..................#",
    "#.......#...#......#",
    "#..#......##...#...#",
    "#..................#",
    "#...###.....#......#",
    "#..................#",
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
        system("cls"); // Clear screen for CLI animation
        showmap();
        cout << "Enter [w|a|s|d] to move: ";
        cin >> dire;
        pmove(dire);

        // The mummy moves twice per turn
        for(int i = 0; i < 2; i++)
		{
            if(gameover()) break; // Stop moving if game has already ended
            mmove();
        }
    }
    system("cls");
    showmap();

    // Determine win or lose
    if(prow == erow && pcol == ecol)
	{
        cout << "Congratulations! You escaped!" << endl;
    } else if(prow == mrow && pcol == mcol)
	{
        cout << "You were caught by the mummy! Game Over!" << endl;
    }
    return 0;
}

// Dynamically render the map based on current coordinates
void showmap()
{
    for(int i = 0; i < MAZER; i++)
    {
        for(int j = 0; j < MAZEC; j++)
        {
            // Priority: Draw player, then mummy, then exit, finally the map structure
            if (i == prow && j == pcol)
			{
                cout << 'p';
            }
			else if (i == mrow && j == mcol)
			{
                cout << 'm';
            }
			else if (i == erow && j == ecol)
			{
                cout << 'e';
            }
			else
			{
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Check if player reached the exit or was caught by the mummy
bool gameover()
{
    if((prow == mrow && pcol == mcol) || (prow == erow && pcol == ecol))
    {
        return true;
    }
    return false;
}

// Update player coordinates, wall collision checked
void pmove(char direction)
{
    int nrow = prow, ncol = pcol;
    if(direction == 'w') nrow--;
    if(direction == 's') nrow++;
    if(direction == 'a') ncol--;
    if(direction == 'd') ncol++;
    
    // Check if the target position is not a wall
    if(maze[nrow][ncol] != '#')
    {
        prow = nrow;
        pcol = ncol;
    }
}

// Update mummy coordinates based on rules
void mmove()
{
    int next_row = mrow;
    int next_col = mcol;

    if(mrow != prow) 
    {
        if(mcol > pcol && maze[mrow][mcol-1] != '#')
            next_col--;
        else if(mcol < pcol && maze[mrow][mcol+1] != '#')
            next_col++;
        // If horizontal move is blocked or unnecessary, attempt vertical movement
        else if(mrow > prow && maze[mrow-1][mcol] != '#')
            next_row--;
        else if(mrow < prow && maze[mrow+1][mcol] != '#')
            next_row++;
    }
    else // If in the same row, only vertical movement allowed
    {
        if(mcol > pcol && maze[mrow][mcol-1] != '#')
            next_col--;
        else if(mcol < pcol && maze[mrow][mcol+1] != '#')
            next_col++;
    }
    
    mrow = next_row;
    mcol = next_col;
}
