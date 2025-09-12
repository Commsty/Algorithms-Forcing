#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long S;
    cin >> S;

    
    int na;
    cin >> na;
    vector<long long> A(na);
    for (int i = 0; i < na; ++i)
    {
        cin >> A[i];
    }

    
    int nb;
    cin >> nb;
    vector<long long> B(nb);
    for (int i = 0; i < nb; ++i)
    {
        cin >> B[i];
    }

    int nc;
    cin >> nc;
    vector<long long> C(nc);
    unordered_map<long long, int> cMinIndex;
    for (int k = 0; k < nc; ++k)
    {
        cin >> C[k];
        if (cMinIndex.find(C[k]) == cMinIndex.end())
        {
            cMinIndex[C[k]] = k;
        }
    }

    for (int i = 0; i < na; ++i)
    {
        for (int j = 0; j < nb; ++j)
        {
            long long needed = S - A[i] - B[j];
            if (cMinIndex.find(needed) != cMinIndex.end())
            {
                int k = cMinIndex[needed];
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}