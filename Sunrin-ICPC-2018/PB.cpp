#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    char str[1010]; scanf("%s", str);
    int ans = 0;
    for(int i=0; i<n-1; i++){
        if(str[i] == 'E' && str[i+1] == 'W') ans++;
    }
    printf("%d", ans);
}