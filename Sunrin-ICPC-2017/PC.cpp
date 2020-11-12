#include <bits/stdc++.h>
using namespace std;

int arr[555][555];
int sumi[555], sumj[555];
int sum, maxi;

int f(int x){
    int ret = 0;
    while(x){
        ret += (x % 10) == 9;
        x /= 10;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int t; cin >> t;
            arr[i][j] = f(t);
            sum += arr[i][j];
            sumi[i] += arr[i][j];
            sumj[j] += arr[i][j];
            maxi = max({maxi, sumi[i], sumj[j]});
        }
    }
    cout << (sum - maxi);
}