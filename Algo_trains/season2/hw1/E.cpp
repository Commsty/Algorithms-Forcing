#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, x, y;
    cin >> d >> x >> y;

    if (x >= min(0, d) && x <= max(0, d) && y <= max(0, d) && y >= min(0, d) && d-x >= y) {
        cout << 0 << "\n";
    }
    else {
        int distA = x*x + y*y;
        int distB = y*y + abs(x - d)*abs(x-d);
        int distC = x*x + abs(y-d)*abs(y-d);

        if (distA <= distB && distA <= distC){
            cout << 1 << "\n";
        }
        else if (distB <= distA && distB <= distC) {
            cout << 2 << "\n";
        }
        else {
            cout << 3 << "\n";
        }
    }

    return 0;
}