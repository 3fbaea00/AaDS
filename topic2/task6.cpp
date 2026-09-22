#include <iostream>
#include <algorithm>

using namespace std;

int64_t findMinAdditionalTime(int64_t copiesNeeded, int64_t x, int64_t y)
{
    int64_t leftBorder = 0;
    int64_t rightBorder = copiesNeeded * max(x, y);

    while (rightBorder - leftBorder > 1)
    {
        int64_t middleTime = (leftBorder + rightBorder) / 2;
        if (middleTime / x + middleTime / y >= copiesNeeded)
            rightBorder = middleTime;
        else leftBorder = middleTime;
    }

    return rightBorder;
}

int main()
{
    int64_t n, x, y;
    cin >> n >> x >> y;

    int64_t fastest = min(x, y);
    int64_t additionalTime = findMinAdditionalTime(n - 1, x, y);
    int64_t totalTime = fastest + additionalTime;

    cout << totalTime << endl;
}