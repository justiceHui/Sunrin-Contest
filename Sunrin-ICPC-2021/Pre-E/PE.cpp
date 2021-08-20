#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll pw3[40] = {1};

void Solve(){
    ll N; cin >> N;
    ll R = 0;
    for(int i=0; i<40; i++) if(N & (1LL << i)) R += pw3[i];
    cout << R << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=1; i<40; i++) pw3[i] = pw3[i-1] * 3;
    int T; cin >> T;
    while(T--) Solve();
}