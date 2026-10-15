#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StackWithProtection
{
private:
    vector<int64_t> elements;

public:
    void push(int64_t value)
    {
        elements.push_back(value);
    }

    bool pop(int64_t& value)
    {
        if (elements.empty())
            return false;

        value = elements.back();
        elements.pop_back();
        return true;
    }

    bool back(int64_t& value)
    {
        if (elements.empty())
            return false;

        value = elements.back();
        return true;
    }

    size_t size()
    {
        return elements.size();
    }

    void clear()
    {
        elements.clear();
    }
};

int main()
{
    StackWithProtection stack;
    string command;

    while (cin >> command)
    {
        if (command == "push")
        {
            int64_t value;
            cin >> value;

            stack.push(value);
            cout << "ok" << endl;
        }
        else if (command == "pop")
        {
            int64_t value;

            if (stack.pop(value))
            {
                cout << value << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else if (command == "back")
        {
            int64_t value;

            if (stack.back(value))
            {
                cout << value << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else if (command == "size")
        {
            cout << stack.size() << endl;
        }
        else if (command == "clear")
        {
            stack.clear();
            cout << "ok" << endl;
        }
        else if (command == "exit")
        {
            cout << "bye" << endl;
            break;
        }
    }
}