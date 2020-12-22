#include <stdio.h>

typedef long long ll;
const ll mod = 1e9+7; // 1 000 000 007

int C[2020][2020];

void calc(int N){
    C[0][0] = 1;
    for(int i=1; i<=N; i++){
        C[i][0] = 1;
        for(int j=1; j<=i; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    calc(N);

    ll ans = 0;
    for(int i=0; i<N; i++){
        int j = N - i - 1;
        if((i + j*2) % 3 != 1) continue;
        ans = (ans + C[N-1][i]) % mod;
    }
    printf("%lld", ans);
}