#include <bits/stdc++.h>
using namespace std;

int N, A[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    int idx = max_element(A+1, A+N+1) - A;
    for(int i=1; i<idx; i++){
        if(A[i] >= A[i+1]){ cout << "NO"; return 0; }
    }
    for(int i=idx; i<N; i++){
        if(A[i] <= A[i+1]){ cout << "NO"; return 0; }
    }
    cout << "YES";
}