#include <iostream>
#include <vector>

using namespace std;

bool canPlaceCows(const vector<int64_t>& stalls, int cowsCount, int64_t minDistance)
{
    int placedCows = 1;
    int64_t lastStall = stalls[0];

    for (int i = 1; i < (int)stalls.size(); i++)
    {
        if (stalls[i] - lastStall >= minDistance)
        {
            placedCows++;
            lastStall = stalls[i];
        }
    }

    return placedCows >= cowsCount;
}

int64_t findMaxMinDistance(const vector<int64_t>& stalls, int cowsCount)
{
    int64_t leftBorder = 0;
    int64_t rightBorder = stalls.back() - stalls.front() + 1;

    while (rightBorder - leftBorder > 1)
    {
        int64_t middle = (leftBorder + rightBorder) / 2;

        if (canPlaceCows(stalls, cowsCount, middle))
            leftBorder = middle;
        else rightBorder = middle;
    }

    return leftBorder;
}

int main()
{
    int stallCount, cowCount;
    cin >> stallCount >> cowCount;

    vector<int64_t> stalls(stallCount);
    for (int i = 0; i < stallCount; i++)
        cin >> stalls[i];

    cout << findMaxMinDistance(stalls, cowCount) << endl;
}