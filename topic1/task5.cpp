#include <iostream>
#include <vector>

using namespace std;

int main() {
    int elementCount;
    cin >> elementCount;

    vector<int> values(elementCount), buffer(elementCount);
    for (int index = 0; index < elementCount; ++index)
        cin >> values[index];

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
                if (values[leftIndex] <= values[rightIndex])
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

    for (int index = 0; index < elementCount; ++index) {
        cout << values[index];
        cout << ' ';
    }
}