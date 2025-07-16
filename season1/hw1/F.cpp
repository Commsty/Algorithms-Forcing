#include<bits/stdc++.h>
using namespace std;

int main(){
    int x1, y1, x2 ,y2;
    cin >> x1 >> y1 >> x2 >> y2;


    int ans1 = max(x1, x2) * (y1 + y2);
    int ans2 = max (x1, y2) * (y1 + x2);
    int ans3 = max(y1, y2) * (x1 + x2);
    int ans4 = max(y1, x2) * (x1 + y2);

    if (ans1 <= ans2 && ans1 <= ans3 && ans1 <= ans4) {
        cout << max(x1, x2) << " " << (y1 + y2) << "\n";
        return 0;
    }

    if (ans2 <= ans1 && ans2 <= ans3 && ans2 <= ans4) {
        cout << max(x1, y2) << " " << (y1 + x2) << "\n";
        return 0;
    }

    if (ans3 <= ans1 && ans3 <= ans2 && ans3 <= ans4) {
        cout << max(y1, y2) << " " << (x1 + x2) << "\n";
        return 0;
    }

    if (ans4 <= ans1 && ans4 <= ans2 && ans4 <= ans3) {
        cout << max(y1, x2) << " " << (x1 + y2) << "\n";
        return 0;
    }


    return 0;
}