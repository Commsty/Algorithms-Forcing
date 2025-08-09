#include<bits/stdc++.h>
using namespace std;

int main(){
    int start_temp, need_temp;
    cin >> start_temp >> need_temp;
    string mode;
    cin >> mode;

    if (strcmp(mode.c_str(), "fan") == 0){
        cout << start_temp;
    }
    else if (strcmp(mode.c_str(), "auto") == 0){
        cout << need_temp;
    }
    else if (strcmp(mode.c_str(), "heat") == 0){
        if (need_temp >= start_temp)
            cout << need_temp;
        else
            cout << start_temp;
    }
    else if (strcmp(mode.c_str(), "freeze") == 0){
        if (need_temp <= start_temp)
            cout << need_temp;
        else
            cout << start_temp;
    }
    return 0;
}