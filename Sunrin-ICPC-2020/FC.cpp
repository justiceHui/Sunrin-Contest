#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K, base, A[1<<18];
ll DP[1<<18], Up[1<<18], mx;

ll f(int s, int e){
    s += base; e += base;
    ll now = 0, mx1 = 0, mx2 = 0;
    auto Update = [&mx1,&mx2](ll v){
        if(v > mx1) mx2 = mx1, mx1 = v;
        else if(v > mx2) mx2 = v;
    };
    while(s < e){
        for(int i=s; i<=e; i++) now += A[i];
        if(s & 1) Update(DP[s^1]);
        if(~e & 1) Update(DP[e^1]);
        s >>= 1; e >>= 1;
    }
    Update(Up[s]);
    return now + A[s] + mx1 + mx2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; base = (N+1)/2-1; K = 31 - __builtin_clz(N+1);
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=base+1; i<=N; i++) DP[i] = A[i];
    for(int i=base; i; i--) DP[i] = max(DP[i<<1], DP[i<<1|1]) + A[i];
    for(int i=2; i<=N; i++) Up[i] = max(Up[i>>1], DP[i^1]) + A[i>>1];
    for(int i=K; i<=base+1; i++) mx = max(mx, f(i-K+1, i));
    cout << mx;
}
