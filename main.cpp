#include <iostream>
#include "vector"
#include <limits.h>
#include "queue"
#include <tuple>
#include <string.h>

using namespace std;

char checkGuard(const char c)
{
    if(c == '<' || c == '>' || c == 'v' || c == '^') {
        return c;
    }

    return ' ';
}

void fillFields(vector<vector<char>>& grid,const int& x, const int& y, const char& c)
{
    if(x<0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
        return;
    }

    grid[x][y] = 'X';

    if(c == '^') {
        fillFields(grid, x-1, y, c);
    } else if(c == 'v') {
        fillFields(grid, x+1, y, c);
    } else if(c == '>') {
        fillFields(grid, x , y+1, c);
    } else if(c == '<') {
        fillFields(grid, x , y-1, c);
    }

    return;
}

void ammendXInGrid(vector<vector<char>>& grid)
{
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            const char nextChar = checkGuard(grid[i][j]);
            if(' ' != nextChar) {
                fillFields(grid, i,j,nextChar);
            }
        }
    }
}

int main()
{
    vector<vector<char>> grid = {
       {' ', ' ', ' ', ' ', '<'},
       {' ', 'X', ' ', ' ', ' '},
       {'A', 'X', ' ', 'X', ' '},
       {' ', 'X', ' ', 'X', ' '},
       {' ', ' ', ' ', 'X', ' '},
       {' ', ' ', ' ', 'X', ' '},
       {' ', ' ', ' ', ' ', ' '},
       {' ', 'X', ' ', ' ', ' '},
       {' ', 'X', ' ', 'X', ' '},
       {' ', 'X', ' ', 'X', ' '},
       {' ', ' ', ' ', 'X', ' '},
       {' ', ' ', ' ', 'X', ' '},
       {' ', ' ', ' ', ' ', ' '},
       {' ', 'X', ' ', ' ', ' '},
       {' ', 'X', ' ', 'X', ' '},
       {' ', 'X', ' ', 'X', ' '},
       {' ', ' ', ' ', 'X', ' '},
       {' ', ' ', ' ', 'X', ' '},
       {' ', ' ', ' ', ' ', ' '},
       {' ', 'X', ' ', ' ', ' '},
       {' ', 'X', ' ', 'X', ' '},
       {' ', 'X', ' ', 'X', ' '},
       {' ', ' ', ' ', 'X', 'F'},
       {' ', ' ', ' ', 'X', ' '}
    };

    ammendXInGrid(grid);

    /*Path is signalled with dots if exists*/

    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}