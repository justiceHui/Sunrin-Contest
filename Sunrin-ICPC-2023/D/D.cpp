#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x){ return x * (x + 1) / 2; }
tuple<ll,ll,ll> MaxSum(const vector<ll> &v){
    ll mx = 0, le = 0, ri = 0;
    ll vm = 0, vl = 0, vr = 0;
    for(int i=0; i<v.size(); i++) vm = max(0LL, vm) + v[i], mx = max(mx, vm);
    for(int i=0; i<v.size(); i++) vl += v[i], le = max(le, vl);
    for(int i=(int)v.size()-1; i>=0; i--) vr += v[i], ri = max(ri, vr);
    return {mx, le, ri};
}

ll N, A[505050], S, R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    S = accumulate(A+1, A+N+1, 0LL);

    vector<ll> A4;
    for(int i=1; i<=N*4; i++) A4.push_back(A[(i-1)%N+1] - i);
    R = max(R, get<0>(MaxSum(A4)));

    ll k = (2 * S + N * N - N) / (2 * N * N);
    if(k <= 4){ cout << R; return 0; }

    vector<ll> le, ri;
    for(int i=1; i<=N+N; i++) le.push_back(A[(i-1)%N+1] - i);
    for(int i=1; i<=N+N; i++) ri.push_back(A[(i-1)%N+1] - (k-1) * N - i);
    ll sum = S * (k - 3) - f((k-1)*N) + f(2*N);
    R = max(R, get<2>(MaxSum(le)) + sum + get<1>(MaxSum(ri)));
    cout << R;
}