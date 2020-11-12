#include <stdio.h>

typedef long long ll;

ll dp[40] = {0};
const int m = 1e9+9;

int main(){
    int n; scanf("%d", &n);
    dp[1] = 0;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] * 3;
        dp[i] %= m;
    }
    printf("%lld", dp[n]);
}