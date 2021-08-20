#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long D[44] = {0, 1, 2};
    for(int i=3; i<44; i++) D[i] = D[i-1] + D[i-2] + 1;

    int T; cin >> T;
    while(T--){
        int V; cin >> V;
        int res = upper_bound(D+1, D+44, V) - D - 1;
        cout << res << "\n";
    }
}