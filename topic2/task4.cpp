#include <iostream>
#include <iomanip>

using namespace std;

double equationValue(double x, double a, double b, double c, double d)
{
    return a * x * x * x + b * x * x + c * x + d;
}

double findRoot(double a, double b, double c, double d)
{
    double leftBorder = -1001.0;
    double rightBorder = 1001.0;
    double leftValue = equationValue(leftBorder, a, b, c, d);
    double value;

    for (int iteration = 0; iteration < 100; iteration++)
    {
        value = (leftBorder + rightBorder) / 2.0;
        double root = equationValue(value, a, b, c, d);

        if (root == 0.0)
            break;

        if (leftValue * root <= 0.0)
        {
            rightBorder = value;
        }
        else
        {
            leftBorder = value;
            leftValue = root;
        }
    }

    return value;
}

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << fixed << setprecision(9) << findRoot(a, b, c, d) << endl;
}