#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool closer(const Point& left, const Point& right) {
    long long leftDistance = 1LL * left.x * left.x + 1LL * left.y * left.y;
    long long rightDistance = 1LL * right.x * right.x + 1LL * right.y * right.y;
    return leftDistance <= rightDistance;
}

int main() {
    int elementCount;
    cin >> elementCount;

    vector<Point> values(elementCount), buffer(elementCount);
    for (int index = 0; index < elementCount; ++index)
        cin >> values[index].x >> values[index].y;

    for (int runWidth = 1; runWidth < elementCount; runWidth *= 2) {
        for (int leftStart = 0; leftStart < elementCount; leftStart += 2 * runWidth) {
            // обрезание длины блoкa если он выxoдит зa гpaницу дaнныx
            int middle = min(leftStart + runWidth, elementCount);
            int rightEnd = min(leftStart + 2 * runWidth, elementCount);

            if (middle >= rightEnd) { // справа блока нет, сливать не с чем
                for (int copyIndex = leftStart; copyIndex < rightEnd; copyIndex++)
                    buffer[copyIndex] = values[copyIndex];
                continue;
            }

            // ocнoвнaя чacть: coeдeнeниe двуx блoкoв пooчepёднo
            int leftIndex = leftStart;
            int rightIndex = middle;
            int writeIndex = leftStart;
            while (leftIndex < middle && rightIndex < rightEnd)
                // изменение: values[leftIndex] <= values[rightIndex] -> closer(...)
                if (closer(values[leftIndex], values[rightIndex]))
                    buffer[writeIndex++] = values[leftIndex++];
                else buffer[writeIndex++] = values[rightIndex++];

            // зaпиcь ocтaткoв
            while (leftIndex < middle)
                buffer[writeIndex++] = values[leftIndex++];
            while (rightIndex < rightEnd)
                buffer[writeIndex++] = values[rightIndex++];
        }

        values.swap(buffer);
    }

    for (int index = 0; index < elementCount; ++index)
        cout << values[index].x << ' ' << values[index].y << '\n';
}