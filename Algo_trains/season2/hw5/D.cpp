#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> brackets;

    char tmp;
    bool flag = true;
    while (cin >> tmp) {
        if (tmp == '(') {
            brackets.push(tmp);
        }
        else if (tmp == ')' && brackets.empty()) {
            flag = false;
            break;
        }
        else if (tmp == ')' && brackets.top() == '(') {
            brackets.pop();
        }
        else {
            brackets.push(tmp);
        }
    }

    if (!brackets.empty() || !flag) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }

    return 0;
}