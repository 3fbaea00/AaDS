#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double findRoot(double targetValue)
{
    double leftBorder = 0.0;
    double rightBorder = targetValue;
    double value;

    for (int iteration = 0; iteration < 100; iteration++)
    {
        value = (leftBorder + rightBorder) / 2.0;
        if (value * value + sqrt(value) < targetValue)
            leftBorder = value;
        else rightBorder = value;
    }

    return value;
}

int main()
{
    double targetValue;
    cin >> targetValue;
    cout << fixed << setprecision(9) << findRoot(targetValue) << endl;
}