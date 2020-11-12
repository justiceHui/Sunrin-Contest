#include <stdio.h>

int main(){
    int n, cnt = 0; scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int t; scanf("%d", &t);
        if(i^t) cnt++;
    }
    printf("%d", cnt);
}