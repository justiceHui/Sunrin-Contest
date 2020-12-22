#include <stdio.h>

typedef long long ll;

int N, Q;
ll G[2020][35];

int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int now;
            scanf("%1d", &now);
            if(now) G[i][j/60] |= 1LL << (j%60);
        }
    }

    scanf("%d", &Q);
    while(Q--){
        int u, v, ans = 0;
        scanf("%d %d", &u, &v);
        for(int i=0; i<35; i++){
            ans += __builtin_popcountll(G[u][i] & G[v][i]);
        }
        printf("%d\n", ans);
    }
}