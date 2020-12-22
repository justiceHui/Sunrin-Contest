#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll pw(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return ret;
}

int len;
string N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; len = N.size();

    ll ans = 0;
    for(int i=0; i<len; i++){
        ll now = pw(2, i) * pw(11, len-i-1) * (N[i] - '0') % mod;
        ans = (ans + now) % mod;
    }
    cout << ans;
}