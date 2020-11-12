#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int chk[10101];
vector<int> prime;

vector<int> fact[10101010];

void eratos(){
    for(int i=2; i<=3300; i++){
        if(chk[i]) continue;
        prime.push_back(i);
        for(int j=i*i; j<=3300; j+=i) chk[j] = 1;
    }
}

void soinsu(ll x){
    ll n = x;
    for(auto i : prime){
        if(i*i > n) break;
        while(n%i == 0) fact[x].push_back(i), n /= i;
    }
    if(n != 1) fact[x].push_back(n);
}

int cnt[10101010];

ll mod = 1e9+7;

ll f(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a;
    ll now = f(a, b/2);
    now *= now; now %= mod;
    if(b%2 == 1) now *= a;
    return now % mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    eratos();
    int n; cin >> n;
    while(n--){
        int a, b; cin >> a >> b; a = b - a;
        if(fact[a].empty()) soinsu(a);
        if(fact[b].empty()) soinsu(b);
        for(auto i : fact[a]) cnt[i]++;
        for(auto i : fact[b]) cnt[i]--;
    }
    
    ll x = 1, y = 1;
    for(int i=1; i<10101010; i++){
        if(!cnt[i]) continue;
        if(cnt[i] > 0) x *= f(i, cnt[i]), x %= mod;
        else cnt[i] *= -1, y *= f(i, cnt[i]), y %= mod;
    }
    cout << x << " " << y;
}