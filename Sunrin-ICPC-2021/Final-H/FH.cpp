#include <bits/stdc++.h>
using namespace std;

int N, A[5050], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++){
        int l = i, r = i;
        while(l > 1 && A[l] > A[l-1]) l--;
        while(r < N && A[r] > A[r+1]) r++;
        R = max(R, r-l+1);
    }
    cout << R;
}