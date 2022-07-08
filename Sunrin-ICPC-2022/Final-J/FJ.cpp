#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, R = 1; cin >> N;
    for(int i=1,t; i<=N-2; i++) cin >> t, R = lcm(R, t);
    cout << R;
}