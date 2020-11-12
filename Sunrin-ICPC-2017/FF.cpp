#include <stdio.h>

typedef long long ll;

int abs(int n){
    return n>0?n:-n;
}

int main(){
    ll ans = 0;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++){
        int t; scanf("%d", &t);
        ans += abs(t);
    }
    for(int i=0; i<n; i++){
        int t; scanf("%d", &t);
        ans += abs(t);
    }
    printf("%lld", ans);
}