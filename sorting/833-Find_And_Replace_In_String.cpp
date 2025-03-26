#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        unordered_map<string, int> sourcesReduct, targetsReduct;
        for (int i = 0; i < sources.size(); i++)
        {
            sourcesReduct[sources[i]] = indices[i];
            targetsReduct[targets[i]] = indices[i];
        }

        sort(sources.begin(), sources.end(), [&sourcesReduct](string a, string b)
             { return sourcesReduct[a] > sourcesReduct[b]; });
        sort(targets.begin(), targets.end(), [&targetsReduct](string a, string b)
             { return targetsReduct[a] > targetsReduct[b]; });
        sort(indices.begin(), indices.end(),greater<int>());

        for (int i = 0; i < indices.size(); i++)
        {
            string sample = sources[i];
            if (s.substr(indices[i], sample.size()) == sample)
            {
                s.replace(indices[i], sample.size(), targets[i]);
            }
        }
        return s;
    }
};