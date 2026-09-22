#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCutEnough(vector<int64_t>& ropes, int64_t requiredPieces, int64_t pieceLength)
{
    for (int64_t rope : ropes)
        requiredPieces -= rope / pieceLength;

    return requiredPieces <= 0;
}

int64_t findMaxPieceLength(vector<int64_t>& ropes, int64_t requiredPieces)
{
    int64_t leftBorder = 0;
    int64_t rightBorder = *max_element(ropes.begin(), ropes.end()) + 1;

    while (rightBorder - leftBorder > 1)
    {
        int64_t middle = (leftBorder + rightBorder) / 2;

        if (canCutEnough(ropes, requiredPieces, middle))
            leftBorder = middle;
        else rightBorder = middle;
    }

    return leftBorder;
}

int main()
{
    int64_t n, k;
    cin >> n >> k;

    vector<int64_t> ropes(n);
    for (int64_t i = 0; i < n; i++)
        cin >> ropes[i];

    cout << findMaxPieceLength(ropes, k) << endl;
}