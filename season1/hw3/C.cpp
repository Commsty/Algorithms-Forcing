#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    unordered_set<int> anya, borya;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        anya.emplace(tmp);
    }

    for (int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        borya.emplace(tmp);
    }

    set<int> common, only_ann, only_borya;
    for (int x: anya){
        if (borya.count(x) != 0){
            common.emplace(x);
        }
    }

    for (int x: anya){
        if (borya.count(x) == 0){
            only_ann.emplace(x);
        }
    }

    for (int x: borya){
        if (anya.count(x) == 0){
            only_borya.emplace(x);
        }
    }

    cout << common.size() << "\n";
    for (int x: common)
        cout << x << " ";
    cout << "\n";

    cout << only_ann.size() << "\n";
    for (int x: only_ann)
        cout << x << " ";
    cout << "\n";

    cout << only_borya.size() << "\n";
    for (int x: only_borya)
        cout << x << " ";

    return 0;
}