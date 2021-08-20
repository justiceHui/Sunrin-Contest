#include <bits/stdc++.h>
using namespace std;

int N, A[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    int mx = 0;
    for(int i=1; i+2<=10; i++){
        int now = 0;
        for(int j=1; j<=N; j++){
            if(i <= A[j] && A[j] <= i+2) mx = max(mx, ++now);
            else now = 0;
        }
    }
    cout << mx;
}