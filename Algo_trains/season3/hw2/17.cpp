#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q1, q2;

    for (int i = 0; i < 5; i++)
    {
        int tmp;
        cin >> tmp;
        q1.push(tmp);
    }
    for (int i = 0; i < 5; i++)
    {
        int tmp;
        cin >> tmp;
        q2.push(tmp);
    }

    int cnt = 0;
    while (cnt < 1000000 && !q1.empty() && !q2.empty())
    {
        int card1 = q1.front(), card2 = q2.front();
        q1.pop(), q2.pop();

        if (card1 == 0 && card2 == 9)
        {
            q1.push(card1), q1.push(card2);
        }
        else if (card2 == 0 && card1 == 9) {
            q2.push(card1), q2.push(card2);
        }
        else if (card2 > card1)
        {
            q2.push(card1), q2.push(card2);
        }
        else {
            q1.push(card1), q1.push(card2);
        }

        cnt++;
    }

    if (q1.empty())
    {
        cout << "second " << cnt << endl;
    }
    else if (q2.empty())
    {
        cout << "first " << cnt << endl;
    }
    else if (cnt == 1000000)
    {
        cout << "botva\n";
    }

    return 0;
}