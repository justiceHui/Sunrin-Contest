#include <bits/stdc++.h>
using namespace std;

int N, A[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; A[1] = 1;
    if(N % 3 == 0) for(int i=1; i<=N; i+=3) A[i] = -1, A[i+1] = 2, A[i+2] = 2;
    if(N % 3 == 1) for(int i=1; i<=N; i+=3) A[i] = 2, A[i+1] = -1, A[i+2] = 2;
    if(N % 3 == 2) for(int i=2; i<=N; i+=3) A[i] = 2, A[i+1] = -1, A[i+2] = 2;
    partial_sum(A, A+N+1, A);
    cout << N << "\n";
    for(int i=0; i<N; i++) cout << (A[i] + N) % N + 1 << " ";
    cout << 1;
}