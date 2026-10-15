#include <iostream>
#include <deque>

using namespace std;

int main()
{
    char command;
    int numOfRequests, value;
    deque<int> leftHalf, rightHalf;

    cin >> numOfRequests;
    while (numOfRequests--)
    {
        cin >> command;
        if (command == '+')
        {
            cin >> value;
            rightHalf.push_back(value);
            if (leftHalf.size() < rightHalf.size())
            {
                leftHalf.push_back(rightHalf.front());
                rightHalf.pop_front();
            }
        }
        else if (command == '*')
        {
            cin >> value;
            if ((leftHalf.size() + rightHalf.size()) % 2 == 0)
                leftHalf.push_back(value);
            else rightHalf.push_front(value);
        }
        else
        {
            cout << leftHalf.front() << endl;
            leftHalf.pop_front();
            if (leftHalf.size() < rightHalf.size())
            {
                leftHalf.push_back(rightHalf.front());
                rightHalf.pop_front();
            }
        }
    }
}