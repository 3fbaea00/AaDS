#include <iostream>
#include <vector>

using namespace std;

bool contains(vector<int>& values, int target) 
{
    int leftIndex = 0;
    int rightIndex = (int)values.size() - 1;

    while (leftIndex <= rightIndex) 
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        int middleValue = values[middleIndex];
        if (middleValue < target)
            leftIndex = middleIndex + 1;
        else if (middleValue > target)
            rightIndex = middleIndex - 1;
        else return true;
    }

    return false;
}

int main()
{
    int elementCount, queryCount;
    cin >> elementCount >> queryCount;

    vector<int> values(elementCount);
    for (int index = 0; index < elementCount; ++index)
        cin >> values[index];

    for (int queryIndex = 0; queryIndex < queryCount; ++queryIndex)
    {
        int target;
        cin >> target;
        cout << (contains(values, target) ? "YES" : "NO") << endl;
    }
}