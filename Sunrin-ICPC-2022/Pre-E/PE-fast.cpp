#include <bits/stdc++.h>
using namespace std;

int N, A[101010], C[111], D[111][111], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i], C[A[i]] += 1;
    R = *max_element(C, C+111);
    for(int d=1; d<=100; d++){
        for(int i=1; i<=N; i++){
            if(A[i] - d >= 1) D[d][A[i]] = max(D[d][A[i]], D[d][A[i]-d] + 1);
            else D[d][A[i]] = max(D[d][A[i]], 1);
            R = max(R, D[d][A[i]]);
        }
    }
    reverse(A+1, A+N+1);
    memset(D, 0, sizeof D);
    for(int d=1; d<=100; d++){
        for(int i=1; i<=N; i++){
            if(A[i] - d >= 1) D[d][A[i]] = max(D[d][A[i]], D[d][A[i]-d] + 1);
            else D[d][A[i]] = max(D[d][A[i]], 1);
            R = max(R, D[d][A[i]]);
        }
    }
    cout << R;
}
