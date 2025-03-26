#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        // optimal variant is bsearch closest elem and form array around it;
    }

    // sliding window
    //  vector<int> findClosestElements(vector<int> &arr, int k, int x)
    //  {
    //      int left = 0, right = k - 1;
    //      for (int j = k; j < arr.size(); j++)
    //      {
    //          if (abs(arr[j] - x) < abs(arr[left] - x))
    //          {
    //              right=j;
    //              left=right-k+1;
    //          }
    //      }

    //     vector<int> res;
    //     for (int i = left; i <= right; i++)
    //     {
    //         res.push_back(arr[i]);
    //     }
    //     return res;
    // }
};