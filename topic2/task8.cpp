#include <iostream>
#include <algorithm>

using namespace std;

bool canPlaceAll(int64_t side, int64_t width, int64_t height, int64_t n) 
{
    int64_t byWidth = side / width, byHeight = side / height;
    if (byWidth == 0 || byHeight == 0)
        return false;

    int64_t neededWidth = (n + byHeight - 1) / byHeight;
    return byWidth >= neededWidth;
}

int64_t findMinBoardSide(int64_t width, int64_t height, int64_t count) 
{
    int64_t leftBorder = 0, rightBorder = max(width, height) * count;

    while (rightBorder - leftBorder > 1)
    {
        int64_t middle = leftBorder + (rightBorder - leftBorder) / 2;
        if (canPlaceAll(middle, width, height, count))
            rightBorder = middle;
        else leftBorder = middle;
    }

    return rightBorder;
}

int main() 
{
    int64_t width, height, count;
    cin >> width >> height >> count;
    cout << findMinBoardSide(width, height, count) << endl;
}
