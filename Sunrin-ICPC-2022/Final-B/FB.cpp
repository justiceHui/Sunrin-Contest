#include <bits/stdc++.h>
using namespace std;

int N, K, C[10];
string S;

bool Valid(){
    int rem = N - accumulate(C, C+10, 0), mx = *max_element(C, C+10);
    int need = 0;
    for(int i=0; i<10; i++) if(C[i] != 0) need += max(0, mx - C[i] - K);
    return need <= rem;
}

void Solve(){
    cin >> S >> K; N = S.size();
    memset(C, 0, sizeof C);
    for(auto i : S) C[i-'0'] += 1;
    if(Valid()){ cout << S << "\n"; return; }

    int idx = -1, val = -1;
    for(int i=N-1; i>=0; i--){
        C[S[i]-'0'] -= 1;
        for(int j=S[i]-'0'-1; j>=0; j--){
            C[j] += 1;
            if(Valid()){ idx = i; val = j; break; }
            C[j] -= 1;
        }
        if(idx != -1) break;
    }
    S[idx] = char(val + '0');
    if(S[0] == '0') C[0] -= 1, idx -= 1, S.erase(S.begin()); // leading zero

    for(idx++; idx<S.size(); idx++){
        for(int i=9; i>=0; i--){
            C[i] += 1;
            if(Valid()){ S[idx] = char(i+'0'); break; }
            C[i] -= 1;
        }
    }
    cout << S << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int TC; cin >> TC;
    for(int tc=1; tc<=TC; tc++) Solve();
}