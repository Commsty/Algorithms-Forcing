#include <bits/stdc++.h>
using namespace std;

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        return 31;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    if (month == 2) {
        return is_leap(year) ? 29 : 28;
    }
    return 0;
}

bool is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    int dim = days_in_month(month, year);
    return day <= dim;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    bool valid_dmy = is_valid_date(x, y, z);
    bool valid_mdy = is_valid_date(y, x, z);

    if (valid_dmy && valid_mdy) {
        if (x == y) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    } else {

        cout << "1\n";
    }

    return 0;
}