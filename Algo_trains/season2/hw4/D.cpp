#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    unordered_map<string, ll> counter;
    vector<string> toSort, noSort;

    string tmp;
    ll summ = 0;

    while (cin.peek() != EOF)
    {
        getline(cin, tmp);
        cin >> ws;

        stringstream ss(tmp);
        string tmpInside;

        ll num;
        string name = "";

        while (ss >> tmpInside)
        {
            if (ss.peek() == EOF)
            {
                num = stol(tmpInside);
            }
            else
            {
                if (name.empty())
                    name += tmpInside;
                else
                    name += " " + tmpInside;
            }
        }

        counter[name] += num;
        summ += num;

        toSort.push_back(name);
        noSort.push_back(name);
    }

    double firstRoundNum = summ / 450.0l;

    ll summRound1 = 0;
    unordered_map<string, ll> afterRoundCounter;

    for (const auto &[key, val] : counter)
    {
        summRound1 += (val / firstRoundNum);
        afterRoundCounter[key] = (val / firstRoundNum);
    }

    if (summRound1 != 450l)
    {

        ll restPlaces = 450 - summRound1;

        sort(toSort.begin(), toSort.end(), [&counter, firstRoundNum](const string &a, const string &b)
             {
                   double val_a = counter[a] / firstRoundNum;
                   double val_b = counter[b] / firstRoundNum;

                   double frac_a = val_a - floor(val_a);
                   double frac_b = val_b - floor(val_b);

                   if (frac_a != frac_b)
                   {
                       return frac_a > frac_b;
                   }
                   else
                   {
                       return counter[a] > counter[b];
                   } });

        for (int i = 0; i < toSort.size() && restPlaces > 0; i++)
        {
            afterRoundCounter[toSort[i]]++;
            restPlaces--;
        }
    }

    for (const auto &s : noSort)
    {
        cout << s << " " << afterRoundCounter[s] << "\n";
    }
    return 0;
}