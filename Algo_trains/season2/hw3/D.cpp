#include<bits/stdc++.h>
using namespace std;


int main() {

    int num;
    cin >> num;

    set<int> possibleNums;

    for (int i = 1; i <= num; i++){
        possibleNums.emplace(i);
    }

    getchar();
    string s;
    getline(cin, s);
    

    set<int> guessedNums;

    while (strcmp(s.c_str(), "HELP") != 0) {

        istringstream iss = istringstream(s);
        int tmp;

        while (iss >> tmp){
            guessedNums.emplace(tmp);
        }

        string ans;
        cin >> ans;

        if (strcmp(ans.c_str(), "YES") == 0) {
            set<int> tmp;
            for (const auto guess: guessedNums){
                if (possibleNums.count(guess) != 0)
                    tmp.emplace(guess);
            }
            possibleNums = tmp;
        }
        else {
            for (int n: guessedNums) {
                possibleNums.erase(n);
            }
        }
        
        guessedNums.clear();
        getchar();
        getline(cin, s);
    }

    for (const auto& n: possibleNums) {
        cout << n << " ";
    }


    return 0;
}