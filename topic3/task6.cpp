#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, k, value;
    deque<pair<int, int>> window;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> value;

        while (!window.empty() && window.back().second >= value)
            window.pop_back();

        window.push_back({ i, value });
        while (window.front().first <= i - k)
            window.pop_front();

        if (i >= k - 1)
            cout << window.front().second << endl;
    }
}