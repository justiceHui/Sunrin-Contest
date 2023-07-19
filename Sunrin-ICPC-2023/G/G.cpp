#include <bits/stdc++.h>
using namespace std;

int A[10], D[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Check(int x){
    for(int i=0; i<10; i++){
        if(A[i] && to_string(x).find(i+'0') != string::npos) return false;
    }
    return true;
}

void Solve(){
    int R = 0;
    for(int i=0; i<10; i++) cin >> A[i];
    for(int i=1; i<=12; i++) for(int j=1; j<=D[i]; j++) R += Check(i) && Check(j);
    cout << R << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int TC; cin >> TC;
    for(int tc=1; tc<=TC; tc++) Solve();
}