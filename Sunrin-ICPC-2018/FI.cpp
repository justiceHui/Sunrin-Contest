#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

const int mod = 1e9+9;

char ma[3010][3010];
int arr[3010][3010] = {0};

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) scanf("%s", ma[i]);
    arr[n-1][m-1] = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(i == n-1 && j == m-1) continue;
            if(ma[i][j] == 'E') arr[i][j] = arr[i][j+1] % mod;
            if(ma[i][j] == 'S') arr[i][j] = arr[i+1][j] % mod;
            if(ma[i][j] == 'B') arr[i][j] = (arr[i][j+1]%mod + arr[i+1][j]%mod)%mod;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans += arr[i][j] % mod;
            ans %= mod;
        }
    }
    printf("%d", ans);
}