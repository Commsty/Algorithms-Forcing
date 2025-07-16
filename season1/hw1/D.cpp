#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && c*c - b == 0 && b >= 0){
        cout << "MANY SOLUTIONS";
        return 0;
    }

    else if (c < 0 || (a == 0 && c*c - b != 0) || (a == 0 && b < 0)){
        cout << "NO SOLUTION";
        return 0;
    }

    else{
        double x = (double)(c*c - b) / a;
        double int_part;
        if ((a*x+b >= 0 && modf(x, &int_part) == 0.0f) || fabs(x - 0.0f) < 0.0001f){
            cout << x;
        }
        else
            cout << "NO SOLUTION";
    }

    return 0;
}