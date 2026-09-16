#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void CountSort(vector<int>& A) {
    // по условию задачи значения от 0 до 100 (включительно? не знаю)
    vector<int> frequencies(101, 0);

    for (int index = 0; index < (int)A.size(); ++index)
        ++frequencies[A[index]];

    int index = 0;
    for (int value = 0; value <= 100; ++value)
        for (int repeat = 0; repeat < frequencies[value]; ++repeat)
            A[index++] = value;
}

int main() {
    string line;
    getline(cin, line);
    stringstream input(line);

    vector<int> values;
    int value;
    while (input >> value)
        values.push_back(value);

    CountSort(values);

    for (int index = 0; index < (int)values.size(); ++index) {
        cout << values[index];
        cout << ' ';
    }
}