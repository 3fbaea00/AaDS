#include <iostream>
#include <stack>
#include <string>

using namespace std;

int64_t applyOperation(int64_t leftOperand, int64_t rightOperand, char operation)
{
    if (operation == '+')
        return leftOperand + rightOperand;
    if (operation == '-')
        return leftOperand - rightOperand;
    return leftOperand * rightOperand;
}

int main()
{
    stack<int64_t> operands;
    string token;

    while (cin >> token)
    {
        if (token == "+" || token == "-" || token == "*")
        {
            int64_t rightOperand = operands.top();
            operands.pop();

            int64_t leftOperand = operands.top();
            operands.pop();

            operands.push(applyOperation(leftOperand, rightOperand, token[0]));
            continue;
        }

        operands.push(stoll(token));
    }

    cout << operands.top() << endl;
}