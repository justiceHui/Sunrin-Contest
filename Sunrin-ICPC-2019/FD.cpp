#include <bits/stdc++.h>
using namespace std;

int par[303030];

int find(int v){
    return v == par[v] ? v : par[v] = find(par[v]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<303030; i++) par[i] = i;
    int n; cin >> n;
    for(int i=0; i<n-2; i++){
        int a, b; cin >> a >> b;
        a = find(a); b = find(b);
        par[b] = a;
    }
    
    for(int i=1; i<=n; i++){
        if(find(i) == i) cout << i << " ";
    }
}