#include <iostream>
#include "vector"
#include <limits.h>
#include "queue"
#include <tuple>
#include <string.h>

using namespace std;

char checkGuard(const char c)
{
    if (c == '<' || c == '>' || c == 'v' || c == '^')
    {
        return c;
    }

    return ' ';
}

void fillFields(vector<vector<char>>& grid,const int& x, const int& y, const char& c)
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
    {
        return;
    }

    grid[x][y] = 'X';

    if (c == '^')
    {
        fillFields(grid, x - 1, y, c);
    }
    else if (c == 'v')
    {
        fillFields(grid, x + 1, y, c);
    }
    else if (c == '>')
    {
        fillFields(grid, x, y + 1, c);
    }
    else if (c == '<')
    {
        fillFields(grid, x, y - 1, c);
    }

    return;
}

void ammendXInGrid(vector<vector<char>>& grid)
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            const char nextChar = checkGuard(grid[i][j]);
            if (' ' != nextChar)
            {
                fillFields(grid, i, j, nextChar);
            }
        }
    }
}

std::pair<int, int> findStartingPoint(const vector<vector<char>>& grid)
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if ('A' == grid[i][j])
            {
                return std::make_pair(i, j);
            }
        }
    }
}

void findShortestPath(vector<vector<char>>& grid)
{
    queue<std::pair<int,int>> q;
    bool found = false;
    int n = grid.size();
    int m = grid[0].size();

    //Determining the starting point where the assasin stands momentarily 
    std::pair<int,int> whereIsMyAssasin = findStartingPoint(grid);
    q.push(make_pair(whereIsMyAssasin.first, whereIsMyAssasin.second));

    //Set initial conditions for get-go
    bool visited[n][m];
    memset(visited, false, sizeof visited);
    visited[whereIsMyAssasin.first][whereIsMyAssasin.second] = true;

    //Holding the value of parents for backing
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m, make_pair(-1, -1)));

    //Utility variables to store temp values for coordinates
    int x,y;

    while(q.empty() != true) 
    {
        tie(x, y) = q.front();
        q.pop();

        // Check if we have reached the finish point
        if (grid[x][y] == 'F')
        {
            found = true;
            break;
        }

        // Explore all neighbors
        if(x > 0 && visited[x-1][y] == false && grid[x-1][y] != 'X') 
        {
            visited[x-1][y] = true;
            q.push(make_pair(x-1,y));
            parents[x-1][y] = make_pair(x,y);

        }
        if(y < m-1 && visited[x][y+1] == false && grid[x][y+1] != 'X') 
        {
            visited[x][y+1] = true;
            q.push(make_pair(x,y+1));
            parents[x][y+1] = make_pair(x,y);

        }
        if(x < n-1 && visited[x+1][y] == false && grid[x+1][y] != 'X') 
        {
            visited[x+1][y] = true;
            q.push(make_pair(x+1,y));
            parents[x+1][y] = make_pair(x,y);

        }
        if(y > 0 && visited[x][y-1] == false && grid[x][y-1] != 'X') 
        {
            visited[x][y-1] = true;
            q.push(make_pair(x,y-1));
            parents[x][y-1] = make_pair(x,y);
        }
    }

    if(!found)
    {
        cout << "No path found!" << endl;

        return;
    }

    // //Printing parents vector. Comment out if needed when debugging
    // for(int i = 0; i < parents.size(); ++i) 
    // {
    //     for(int j = 0; j < parents[0].size(); ++j) 
    //     {
    //         cout << "(" << parents[i][j].first << " " << parents[i][j].second << ") ";
    //     }
    //     cout << endl;
    // }

    //Doing the backing till we reach the assasin
    while(x != whereIsMyAssasin.first || y != whereIsMyAssasin.second) 
    {
        int temp_x = x;
        x = parents[x][y].first;
        y = parents[temp_x][y].second;

        grid[x][y] = '.';
    }

    return;
}

int main()
{
    vector<vector<char>> grid = {
       {' ', ' ', 'v', ' ', '<'},
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
    
    /*Algo to find the shortest possible path to the finish line*/
    findShortestPath(grid);

    /*Path is signalled with dots if exists*/
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}