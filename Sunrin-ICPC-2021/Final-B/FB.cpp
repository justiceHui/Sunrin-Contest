#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
// X^{N+K-2} * sum(1..X)^2 * K

//get a^b mod MOD in O(log b)
ll Pow(ll a, ll b){
    ll res = 1;
    for(; b; b >>= 1, a = a * a % MOD) if(b & 1) res = res * a % MOD;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N, K, X; cin >> N >> K >> X;
    ll S = X * (X + 1) / 2 % MOD;
    ll R = Pow(X, N+K-2) * Pow(S, 2) % MOD * K % MOD;
    for(int i=1; i<=N-K+1; i++) cout << R << " ";
}