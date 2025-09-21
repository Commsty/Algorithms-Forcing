#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> q;
    
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    stack<int> deadEnd;
    int nowNum = 1;
    
    while (!q.empty() || !deadEnd.empty())
    {
        if (!deadEnd.empty() && deadEnd.top() == nowNum)
        {
            deadEnd.pop();
            nowNum++;
            continue;
        }
        
        if (!q.empty() && q.front() == nowNum)
        {
            q.pop();
            nowNum++;
            continue;
        }
        
        if (!q.empty())
        {
            deadEnd.push(q.front());
            q.pop();
            continue;
        }
        
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    return 0;
}