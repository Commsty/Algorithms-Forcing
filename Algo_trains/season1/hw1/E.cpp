#include<bits/stdc++.h>
using namespace std;

int main(){
    int k1, m, k2, p2, n2;
    cin >> k1 >> m >> k2 >> p2 >> n2;

    int tmp_left = m * (p2 - 1) + n2;
    int tmp_right = k2;

    // tmp_left * x >= tmp_right

    int x = (tmp_right + tmp_left - 1) / tmp_left; // start flats per lvl
    // int y = m * x; //flats per group

    // int p1 = (k1 + y - 1) / y;
    // int n1 = (k1 - y * (p1 - 1) + x - 1) / x;

    int px = -1, px_prev;
    int cnt_px = 0;

    int nx = -1, nx_prev;
    int cnt_nx = 0;

    while (true){
        int fpg = m * x;

        if (fpg * (p2 - 1) >= k2)
            break;

        px_prev = px;
        px = (k1 + fpg - 1) / fpg;

        if (fpg * (px - 1) >= k1)
            break;

        if (px_prev != px || px_prev == -1)
            cnt_px++;

        nx_prev = nx;
        nx = (k1 - fpg * (px - 1) + x - 1) / x;

        if (nx * x > k1 - fpg * (px - 1))
            break;

        if (nx != nx_prev || nx_prev == -1)
            cnt_nx++;

        x++;
    }

    if (cnt_nx == 0 || cnt_px == 0){
        cout << -1 << " " << -1 << "\n";
    }
    else if (cnt_nx == 1 && cnt_px == 1){
        cout << px << " " << nx << "\n";
    }
    else if (cnt_nx > 1 && cnt_px == 1){
        cout << px << " " << 0 << "\n";
    }
    else if (cnt_nx == 1 && cnt_px > 1){
        cout << 0 << " " << nx << "\n";
    }
    else if (cnt_nx > 1 && cnt_px > 1){
        cout << 0 << " " << 0 << "\n";
    }

    return 0;
}