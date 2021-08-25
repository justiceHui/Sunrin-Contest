#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    sort(A+2, A+N+1);

    ll now = A[1];
    for(int i=2; i<=N; i++){
        if(now <= A[i]){ cout << "No"; return 0; }
        now += A[i];
    }
    cout << "Yes";
}