#include <bits/stdc++.h>
using namespace std;

int main()
{

    int l, k;
    cin >> l >> k;

    int lastLeft, firstRight;

    if (l % 2 == 0)
    {
        lastLeft = l / 2 - 1;
        firstRight = lastLeft + 1;
    }
    else
    {
        lastLeft = firstRight = l / 2;
    }

    int cntLeft = 0, cntRight = 0;
    int leftIndex, rightIndex = -1;

    vector<int> blocks(k, 0), ans;
    for (int i = 0; i < k; i++)
    {
        cin >> blocks[i];

        if (blocks[i] <= lastLeft)
        {
            cntLeft++;
            leftIndex = i;
        }
        if (blocks[i] >= firstRight)
        {
            cntRight++;
            if (rightIndex == -1)
                rightIndex = i;
        }
    }

    for (int i = 0; i <= leftIndex; i++)
    {
        if (blocks[i] <= lastLeft && cntLeft > 1)
        {
            cntLeft--;
            continue;
        }

        ans.push_back(blocks[i]);
    }

    for (int i = k - 1; i >= rightIndex; i--)
    {
        if (blocks[i] >= firstRight && cntRight > 1){
            cntRight--;
            continue;
        }

        if (ans[0] != blocks[i]){
            ans.push_back(blocks[i]);
        }
    }

    for (int block : ans)
    {
        cout << block << " ";
    }

    return 0;
}