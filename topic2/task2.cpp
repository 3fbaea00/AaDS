#include <iostream>
#include <vector>

using namespace std;

int findClosest(vector<int64_t>& values, int64_t target)
{
    int leftIndex = 0;
    int rightIndex = values.size();
    while (leftIndex < rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        if (values[middleIndex] < target)
            leftIndex = middleIndex + 1;
        else rightIndex = middleIndex;
    }

    int closestIndex = leftIndex;
    if (leftIndex == values.size())
    {
        closestIndex = leftIndex - 1;
    }
    else if (leftIndex > 0)
    {
        int previousIndex = leftIndex - 1;
        if (abs(values[previousIndex] - target) <= abs(values[leftIndex] - target))
            closestIndex = previousIndex;
    }

    return values[closestIndex];
}

int main()
{
    int elementCount, queryCount;
    cin >> elementCount >> queryCount;

    vector<int64_t> values(elementCount);
    for (int index = 0; index < elementCount; ++index)
        cin >> values[index];

    for (int queryIndex = 0; queryIndex < queryCount; ++queryIndex)
    {
        int target;
        cin >> target;
        cout << findClosest(values, target) << endl;
    }
}