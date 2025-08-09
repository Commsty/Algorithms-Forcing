#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, k, m;
    cin >> n >> k >> m;

    int cnt = 0;
    int prepares, details;
    while (true){
        if (n < k)
            break;
        
        prepares = n / k;
        n %= k;

        if (prepares == 0)
            break;

        details = (k / m) * prepares;

        if (details == 0)
            break;

        cnt += details;
        n += (k % m) * prepares;
    }

    cout << cnt << "\n";

    return 0;
}