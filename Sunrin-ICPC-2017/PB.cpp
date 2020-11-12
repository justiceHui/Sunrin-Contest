#include <bits/stdc++.h>
using namespace std;

int arr[101010];
int now, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n+n; i++){
        int t; cin >> t;
        arr[t]++;
        if(arr[t] == 1) now++;
        else now--;
        ans = max(ans, now);
    }
    cout << ans;
}