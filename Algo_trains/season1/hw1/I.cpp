#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

    vector<int> tmp = {a, b, c};
    sort(tmp.begin(), tmp.end());
	
	if (tmp[1] <= max(e, d) && tmp[0] <= min(e, d)){
    	cout << "YES";
        return 0;
	}

	cout << "NO";


	return 0;
}