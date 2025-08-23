#include<bits/stdc++.h>
using namespace std;


int main() {

    int num, fst, scnd;
    cin >> num >> fst >> scnd;

    cout << min( abs(scnd-fst)-1, num - max(scnd, fst) + min(scnd, fst) - 1);


    return 0;
}