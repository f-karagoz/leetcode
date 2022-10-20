#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
An image is represented by an m x n integer grid image where
image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color.
You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus
any pixels connected 4-directionally to the starting pixel of
the same color as the starting pixel, plus any pixels connected
4-directionally to those pixels (also with the same color), and so on.
Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
*/

typedef struct
{
    int y;
    int x;
}Coordinates;

class Solution {
public:
    /*
    1 1 1   2 2 2
    1 1 0   2 2 0
    1 0 1   2 0 1
    */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int targetColor)
    {

        // sr: y, sc: x, [y][x], [sr][sc]

        if (image[sr][sc] == targetColor)
            return (image); // No changes done

        int sourceColor = image[sr][sc];

        int sizeOfColumn = image.size();
        //cout << "row size is: " << rowSize << endl;
        int sizeOfRow = image[0].size();
        //cout << "Column size is: " << columnSize << endl;

        vector<vector<int>> result = image;
        queue<Coordinates> itemsToCheck;
        itemsToCheck.push({ sr,sc });

        while (itemsToCheck.size() != 0)
        {
            Coordinates currentCoordinate = itemsToCheck.front();
            itemsToCheck.pop();
            if (result[currentCoordinate.y][currentCoordinate.x] == sourceColor)
            {
                result[currentCoordinate.y][currentCoordinate.x] = targetColor;

                if (currentCoordinate.y > 0)   // UP
                {
                    itemsToCheck.push({ currentCoordinate.y - 1, currentCoordinate.x });
                }
                if (currentCoordinate.x > 0)   // LEFT
                {
                    itemsToCheck.push({ currentCoordinate.y, currentCoordinate.x - 1 });
                }
                if (currentCoordinate.y < sizeOfColumn - 1)   // DOWN
                {
                    itemsToCheck.push({ currentCoordinate.y + 1, currentCoordinate.x });
                }
                if (currentCoordinate.x < sizeOfRow - 1)   // RIGHT
                {
                    itemsToCheck.push({ currentCoordinate.y, currentCoordinate.x + 1 });
                }

            }
        }

        return result;
    }
};

Solution sol;

int main(void)
{
    /*
    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    */

    vector<vector<int>> vTest = { {1,1,1} ,{1,1,0},{1,0,1} };

    for (auto y: vTest)
    {
        for (auto x : y)
            cout << x << " ";
        cout << endl;
    }
       

    vector<vector<int>> vResult = sol.floodFill(vTest, 1, 1, 2);

    cout << endl;
    for (auto y : vResult)
    {
        for (auto x : y)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;


    return 0;
}