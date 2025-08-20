#include <bits/stdc++.h>
using namespace std;

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year)
{
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return daysInMonth[month - 1];
}

long long dateToDays(int day, int month, int year)
{
    long long totalDays = 0;

    for (int y = 1; y < year; y++)
    {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++)
    {
        totalDays += getDaysInMonth(m, year);
    }

    totalDays += day;

    return totalDays;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<long long>> days;
    for (int i = 1; i <= n; i++)
    {
        int d1, m1, y1, d2, m2, y2;
        cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

        long long dateBirth = dateToDays(d1, m1, y1), dateDeath = dateToDays(d2, m2, y2);
        long long date18 = dateToDays(d1, m1, y1 + 18), date80 = dateToDays(d1, m1, y1 + 80);

        if (date18 < dateDeath)
        {
            days.push_back({date18, 1, i});
            days.push_back({min(dateDeath, date80), -1, i});
        }
    }

    if (days.size() == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        sort(days.begin(), days.end());

        unordered_set<int> commandNow;
        bool full = false;

        for (int i = 0; i < days.size(); i++)
        {
            if (days[i][1] == -1)
            {
                if (full)
                {
                    for (const auto &p : commandNow)
                    {
                        cout << p << " ";
                    }
                    cout << "\n";

                    commandNow.erase(days[i][2]);
                    full = false;
                }
                else
                {
                    commandNow.erase(days[i][2]);
                }
            }
            else
            {
                commandNow.emplace(days[i][2]);
                full = true;
            }
        }
    }

    return 0;
}