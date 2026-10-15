#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOpeningBracket(char symbol)
{
    return symbol == '(' || symbol == '[' || symbol == '{';
}

char matchingOpeningBracket(char closingBracket)
{
    if (closingBracket == ')')
        return '(';
    if (closingBracket == ']')
        return '[';
    return '{';
}

bool isCorrectBracketSequence(const string& sequence)
{
    vector<char> stack;

    for (char symbol : sequence)
    {
        if (isOpeningBracket(symbol))
        {
            stack.push_back(symbol);
            continue;
        }

        if (stack.empty() || stack.back() != matchingOpeningBracket(symbol))
            return false;

        stack.pop_back();
    }

    return stack.empty();
}

int main()
{
    string sequence;
    cin >> sequence;

    cout << (isCorrectBracketSequence(sequence) ? "yes" : "no") << endl;
}