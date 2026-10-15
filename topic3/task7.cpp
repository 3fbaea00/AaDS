#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num, wagon, expected = 1;
    stack<int> deadend;

    cin >> num;
    for (int index = 0; index < num; index++)
    {
        cin >> wagon;
        if (wagon == expected)
        {
            expected++;
            while (!deadend.empty() && deadend.top() == expected)
            {
                deadend.pop();
                expected++;
            }
        }
        else
        {
            deadend.push(wagon);
        }
    }

    while (!deadend.empty() && deadend.top() == expected)
    {
        deadend.pop();
        expected++;
    }

    cout << (expected == num + 1 ? "YES" : "NO") << endl;
}