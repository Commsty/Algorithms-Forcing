#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> buildings(10, 0);
    for (int i = 0; i < 10; i++)
    {
        cin >> buildings[i];
    }

    vector<int> shortest(10, INT_MAX);

    int magCoordinate = -1;
    for (int i = 0; i < 10; i++) {
        if (buildings[i] == 2){
            magCoordinate = i;
            continue;
        }

        if (buildings[i] == 1 && magCoordinate != -1) {
            shortest[i] = i - magCoordinate;
        }
    }

    magCoordinate = -1;
    for (int i = 9; i >= 0; i--) {
        if (buildings[i] == 2){
            magCoordinate = i;
            continue;
        }

        if (buildings[i] == 1 && magCoordinate != -1) {
            shortest[i] = min(shortest[i], magCoordinate - i);
        }
    }

    int maxDist = INT_MIN;
    for (int i = 0; i < 10; i++) {
        if (buildings[i] == 1){
            maxDist = max(maxDist, shortest[i]);
        }
    }

    cout << maxDist << "\n";

    return 0;
}