#include <bits/stdc++.h>
using namespace std;

int N, A[50505];

void Solve(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++){
        A[i] = min(A[i], N - A[i] + 1);
        if(A[i-1] > A[i]) A[i] = N - A[i] + 1;
        if(A[i-1] > A[i]){ cout << "NO\n"; return; }
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for(int tc=1; tc<=T; tc++) Solve();
}
