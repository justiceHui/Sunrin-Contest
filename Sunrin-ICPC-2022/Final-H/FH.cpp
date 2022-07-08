#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int TC; cin >> TC;
    for(int tc=1; tc<=TC; tc++){
        ll N; cin >> N;
        if(N % 2) cout << N * (N-1) * (N-2) << "\n";
        else if(__gcd(N, N-3) == 1) cout << N * (N-1) * (N-3) << "\n";
        else cout << (N-1) * (N-2) * (N-3) << "\n";
    }
}