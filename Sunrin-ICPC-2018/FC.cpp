#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int arr[33];
int chk[33];

int ans = 0;

void f(int pos, int cnt){
    if(cnt == n){
        for(int i=1; i<=2*n; i++) if(!arr[i]) return;
        ans++;
        return;
    }
    if(arr[pos]){
        f(pos+1, cnt);
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(chk[i] || arr[i+pos+1]) continue;
        chk[i] = 1; arr[pos] = arr[i+pos+1] = i;
        f(pos+1, cnt+1);
        chk[i] = arr[pos] = arr[i+pos+1] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x >> y;
    
    arr[x] = arr[y] = y-x-1;
    chk[y-x-1] = 1;
    
    f(1, 1);
    cout << ans;
}