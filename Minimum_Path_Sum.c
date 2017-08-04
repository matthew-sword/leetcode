#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int minPathSum(int** grid, int gridRowSize, int gridColSize);

int main() {
    printf("Hello, World!\n");
    return 0;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    int path[gridRowSize][gridColSize];

    path[0][0] = grid[0][0];

    for (int i = 0; i < gridRowSize; i++)
    {
        for (int j = 0; j < gridColSize; j++)
        {
            if (i == 0 && j != 0)
                path[i][j] = grid[i][j] + path[i][j-1];

            else if (j == 0 && i != 0)
                path[i][j] = grid[i][j] + path[i-1][j];

            else if (i != 0 && j != 0)
            {
                if (path[i-1][j] <= path[i][j-1])
                    path[i][j] = path[i-1][j] + grid[i][j];

                else
                    path[i][j] = path[i][j-1] + grid[i][j];
            }

        }
    }

    return path[gridRowSize-1][gridColSize-1];
}