#include <bits/stdc++.h>
using namespace std;

int N, K, A[5050], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    sort(A+1, A+N+1);
    for(int i=1, j=N; i<j; i++){
        while(i < j && A[i] + A[j] > K) j--;
        if(i < j && A[i] + A[j] <= K) R++, j--;
    }
    cout << R;
}