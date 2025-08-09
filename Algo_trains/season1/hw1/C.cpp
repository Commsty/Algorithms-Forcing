#include<bits/stdc++.h>
using namespace std;


void redux(string &s){
    string ans = "";
    for (const char& x: s){
        if (0 <= (x-'0') && (x-'0') <= 9){
            ans.push_back(x);
        }
    }

    if (ans.length() == 11 && (ans[0]=='7' || ans[0]=='8')){
        ans = ans.substr(1);
    }
    if (ans.length() == 7){
        ans.insert(0, "495");
    }

    s = ans;
}

int main(){
    string s, s1, s2, s3;
    cin >> s >> s1 >> s2 >> s3;

    redux(s);
    redux(s1);
    redux(s2);
    redux(s3);

    if (strcmp(s.c_str(), s1.c_str()) == 0){
        cout << "YES" << "\n";
    }
    else
        cout << "NO" << "\n";

    if (strcmp(s.c_str(), s2.c_str()) == 0){
        cout << "YES" << "\n";
    }
    else
        cout << "NO" << "\n";

    if (strcmp(s.c_str(), s3.c_str()) == 0){
        cout << "YES" << "\n";
    }
    else
        cout << "NO" << "\n";

    return 0;
}