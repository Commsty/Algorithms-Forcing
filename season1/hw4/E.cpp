#include<bits/stdc++.h>
using namespace std;



int main(){

    auto comparator = [](const pair<int, int>& a, const pair<int, int>& b){
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> heap(comparator);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        heap.push({x, y});
    }

    int height = 0;
    long long prev = INT_MAX;

    while (!heap.empty()){
        auto top = heap.top();
        if (top.first < prev){
            height += top.second;
            prev = top.first;
        }
        heap.pop();   
    }

    cout << height;


    return 0;
}