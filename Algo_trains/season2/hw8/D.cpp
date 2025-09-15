#include <bits/stdc++.h>
using namespace std;

pair<int, int> furthestFrom(vector<vector<int>>& graph, int start) {
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    
    q.push({start, 0});
    visited.emplace(start);

    int maxDist = 0;
    int furthest = start;

    while (!q.empty()) {

        int current = q.front().first;
        int currDist = q.front().second;
        q.pop();

        if (currDist > maxDist) {
            maxDist = currDist;
            furthest = current;
        }

        for (auto node: graph[current]) {
            if (visited.count(node) == 0) {
                q.push({node, currDist+1});
                visited.emplace(node);
            }
        }
    }

    return {furthest, maxDist};
}


int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1, vector<int>(0));

    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;

        graph[left].push_back(right);
        graph[right].push_back(left);
    }

    auto f1 = furthestFrom(graph, 1);
    auto f2 = furthestFrom(graph, f1.first);

    cout << f2.second + 1 << "\n";

    return 0;
}