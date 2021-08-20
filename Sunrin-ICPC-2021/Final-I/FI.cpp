#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

int N, A[5050];
ll D[5050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];

    for(int i=1; i<=N; i++){
        D[i] = 1;
        for(int j=i-1; j>=1; j--) if(A[j] < A[i]) D[i] += D[j];
        D[i] %= MOD;
    }
    for(int i=1; i<=N; i++) cout << D[i] << " ";
}