#include <bits/stdc++.h>
using namespace std;

int N, A[111][111], D[111][111], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> A[i][j];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int mx = 0;
            for(int r=1; r<=i; r++) for(int c=1; c<=j; c++) if(A[r][c] < A[i][j]) mx = max(mx, D[r][c]);
            D[i][j] = mx + 1; R = max(R, D[i][j]);
        }
    }
    cout << R;
}