#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll a, b, c, d; cin >> a >> b >> c >> d;
    int N, R = 0; cin >> N;
    for(int i=1; i<=N; i++){
        ll u, v; cin >> u >> v;
        R += a * (v-b) * (v-b) + c == u;
    }
    cout << R;
}