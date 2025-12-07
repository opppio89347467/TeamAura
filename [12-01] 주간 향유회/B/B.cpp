#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> a(N);
    int M = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        M = max(M, a[i]);
    }
    vector<long long> freq(M + 1);
    for (int x : a) freq[x]++;
    vector<int> mu(M + 1), lp(M + 1), pr;
    mu[1] = 1;
    for (int i = 2; i <= M; ++i) {
        if (!lp[i]) {
            lp[i] = i;
            pr.push_back(i);
            mu[i] = -1;
        }
        for (int p : pr) {
            long long v = 1LL * p * i;
            if (v > M) break;
            lp[v] = p;
            if (p == lp[i]) { mu[v] = 0; break; }
            else mu[v] = -mu[i];
        }
    }
    vector<long long> cnt(M + 1);
    for (int d = 1; d <= M; ++d)
        for (int m = d; m <= M; m += d)
            cnt[d] += freq[m];
    long long ans = 0;
    for (int d = 1; d <= M; ++d)
        if (mu[d] && cnt[d] >= 2)
            ans += mu[d] * (cnt[d] * (cnt[d] - 1) / 2);
    cout << ans << '\n';
    return 0;
}
