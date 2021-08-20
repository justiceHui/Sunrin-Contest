#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

int N, A[202020], D[202020][4], P[202020][4];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    memset(D, 0x3f, sizeof D); // D[i][j] <- INF
    D[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=3; j++){
            if(D[i-1][j] <= A[i] && D[i][j] > A[i]) D[i][j] = A[i], P[i][j] = j;
            if(j > 0 && D[i][j] > D[i-1][j-1])      D[i][j] = D[i-1][j-1], P[i][j] = j-1;
        }
    }

    for(int ti=0; ti<=3; ti++){
        if(D[N][ti] != INF){
            cout << "YES\n" << ti << "\n";
            for(int i=N, j=ti; i>=1; j=P[i][j], i--){
                if(P[i][j] == j-1) cout << i << " " << D[i][j] << "\n";
            }
            return 0;
        }
    }
    cout << "NO\n";
}