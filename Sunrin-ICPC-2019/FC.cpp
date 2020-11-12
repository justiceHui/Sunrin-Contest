#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;

int dp[555][555][5];
char arr[555][555];
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<=n; i++){
        if(i) cin >> (arr[i] + 1);
        for(int j=0; j<=n; j++){
            dp[i][j][0] = 0;
            for(int k=1; k<=4; k++) dp[i][j][k] = -inf;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<=4; k++){
                dp[i][j][0] = max({dp[i][j][0], dp[i-1][j][k], dp[i][j-1][k]});
            }
            if(arr[i][j] == 'M'){
                dp[i][j][1] = max({dp[i-1][j][4], dp[i][j-1][4], dp[i - 1][j][0], dp[i][j - 1][0]});
            }
            if(arr[i][j] == 'O'){
                dp[i][j][2] = max(dp[i-1][j][1], dp[i][j-1][1]);
            }
            if(arr[i][j] == 'L'){
                dp[i][j][3] = max(dp[i-1][j][2], dp[i][j-1][2]);
            }
            if(arr[i][j] == 'A'){
                dp[i][j][4] = max(dp[i-1][j][3], dp[i][j-1][3]) + 1;
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i<=4; i++) ans = max(ans, dp[n][n][i]);
    cout << ans;
}