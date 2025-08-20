#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int last = 0;
    vector<vector<int>> people;
    for (int i = 0; i < 2 * n; i += 2)
    {
        int in, out;
        cin >> in >> out;

        if (out - in >= 5)
        {

            people.push_back({in});
            people[last].push_back(-1);
            people[last].push_back(i);

            people.push_back({out - 5});
            people[last + 1].push_back(1);
            people[last + 1].push_back(i);

            last += 2;
        }
    } 

    sort(people.begin(), people.end());

    if (people.size() == 0)
    {
        cout << 0 << " " << 10 << " " << 20;
    }
    else if (people.size() == 2)
    {
        cout << 1 << " " << people[0][0] << " " << people[0][0] + 10;
    }
    else
    {
        int bestSummary = 0;
        int firstTime = 0, secondTime = 0;
        unordered_set<int> checker;

        for (int i = 0; i < people.size(); i++)
        {
            if (people[i][1] == -1)
            {
                checker.emplace(people[i][2]);

                if (checker.size() > bestSummary)
                {
                    bestSummary = checker.size();
                    firstTime = people[i][0];
                    secondTime = people[i][0] + 10;
                }
            }

            int secondCount = 0;
            for (int j = i + 1; j < people.size(); j++)
            {
                if (people[j][1] == -1)
                {
                    secondCount++;
                }
                if (people[j][0] - people[i][0] >= 5 && checker.size() + secondCount > bestSummary)
                {
                    bestSummary = checker.size() + secondCount;
                    firstTime = people[i][0];
                    secondTime = people[j][0];
                }
                if (people[j][1] == 1 && checker.count(people[j][2]) == 0)
                {
                    secondCount--;
                }
            }

            if (people[i][1] == 1)
            {
                checker.erase(people[i][2]);
            }
        }

        cout << bestSummary << " " << firstTime << " " << secondTime;
    }

    return 0;
}