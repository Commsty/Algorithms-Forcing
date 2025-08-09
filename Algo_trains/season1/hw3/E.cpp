#include<bits/stdc++.h>
using namespace std;


int main(){
    unordered_set<int> buttons, extra;
    for (int i = 0; i < 3; i++){
        int tmp;
        cin >> tmp;
        buttons.emplace(tmp);
    }

    int num;
    cin >> num;

    while (num != 0){
        int c = num % 10;
        if (buttons.count(c) == 0)
            extra.emplace(c);

        num /= 10;
    }

    cout << extra.size();

    return 0;
}
