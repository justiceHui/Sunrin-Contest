#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, A[505050];

bool Check(ll x){
    ll res = 0;
    for(int i=1; i<=N; i++) res += max(0LL, A[i] - x);
    return res <= K;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    ll l = 0, r = 1e12;
    while(l < r){
        ll m = (l + r) / 2;
        if(Check(m)) r = m; else l = m + 1;
    }
    cout << r;
}