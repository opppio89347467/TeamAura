#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> pi(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    vector<int> c(n+1);
    for(int i=0;i<n;i++) c[pi[i]]++;
    for(int i=n;i>0;i--) c[pi[i-1]]+=c[i];
    for(int i=1;i<=n;i++) c[i]++;
    vector<int> occ;
    for(int x=n;x>0;x=pi[x-1]) occ.push_back(c[x]);
    sort(occ.begin(), occ.end());
    int Q; cin >> Q;
    while(Q--){
        int k; cin >> k;
        cout << (occ.end() - lower_bound(occ.begin(), occ.end(), k)) << "\n";
    }
}
