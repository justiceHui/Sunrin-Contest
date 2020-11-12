#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n+1);
    
    for(int i=1; i<=n; i++) cin >> v[i];
    int k; cin >> k;
    if(v[1] == k){
        cout << "T"; return 0;
    }
    for(int i=1; i<=n; i++){
        double a = (double)v[i] / i;
        double b = (double)v[i-1] / (i-1);
        if(a > b) swap(a, b);
        if(a <= k && k <= b){
            cout << "T"; return 0;
        }
    }
    cout << "F";
}