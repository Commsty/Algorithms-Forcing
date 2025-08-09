#include<bits/stdc++.h>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

long long main(){

    long long t, d, n;
    cin >> t >> d >> n;

    unordered_set<pair<long long, long long>, pair_hash> av_pos = {{0, 0}}, new_av_pos = {};
    unordered_set<pair<long long, long long>, pair_hash> last_added = {{0, 0}}, new_last_added = {}; 
    unordered_set<pair<long long, long long>, pair_hash> nav_pos;

    for (long long i = 0; i < n; i++){

        for (long long j = 0; j < t; j++){

            new_last_added.clear();

            for (const auto& [p1,p2]: last_added){
                av_pos.insert({p1+1, p2});
                av_pos.insert({p1-1, p2});
                av_pos.insert({p1, p2+1});
                av_pos.insert({p1, p2-1});

                new_last_added.insert({p1+1, p2});
                new_last_added.insert({p1-1, p2});
                new_last_added.insert({p1, p2+1});
                new_last_added.insert({p1, p2-1});
            }
            last_added = new_last_added;
        }

        long long x, y;
        cin >> x >> y;

        nav_pos.insert({x, y});

        for (long long i = x - d; i <= x + d; i++){
            for (long long j = y - d; j <= y + d; j++){
                if (abs(x-i) + abs(y-j) <= d){
                    nav_pos.insert({i, j});
                }
            }
        }

        new_av_pos.clear();
        for (const pair<long long, long long>& p: av_pos){
            if (nav_pos.count(p) != 0)
                new_av_pos.insert(p);
        }
        av_pos = new_av_pos;

        new_last_added = {};
        for (const pair<long long, long long>& p: last_added){
            if (nav_pos.count(p) != 0)
                new_last_added.insert(p);
        }
        last_added = new_last_added;

        nav_pos.clear();
    }


    cout << av_pos.size() << "\n";
    for (const auto& [x, y]: av_pos){
        cout << x << " " << y << "\n";
    }

    return 0;
}