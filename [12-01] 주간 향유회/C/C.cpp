#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M1, M2;
    cin >> N >> M1 >> M2;
    vector<pair<int,int>> mustAdj(M1), mustNot(M2);
    for (auto &p : mustAdj) cin >> p.first >> p.second;
    for (auto &p : mustNot) cin >> p.first >> p.second;

    vector<int> p(N);
    iota(p.begin(), p.end(), 1);
    int pos[11];

    auto ok = [&]() {
        for (int i = 0; i < N; ++i) pos[p[i]] = i;
        for (auto [a,b] : mustAdj)
            if (abs(pos[a] - pos[b]) != 1) return false;
        for (auto [a,b] : mustNot)
            if (abs(pos[a] - pos[b]) == 1) return false;
        return true;
    };

    do {
        if (ok()) {
            for (int i = 0; i < N; ++i) {
                if (i) cout << ' ';
                cout << p[i];
            }
            cout << '\n';
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << -1 << '\n';
    return 0;
}
