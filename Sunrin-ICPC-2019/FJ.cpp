#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll f(ll n){
    if(n == 2) return 1;
    return f(n - 2) * (n - 1) % mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << f(n);
}