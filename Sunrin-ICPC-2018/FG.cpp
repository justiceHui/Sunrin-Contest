#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<p> v(n);
    for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;
    
    int start = -2e9, last = -2e9, ans = 0;
    for(int i=0; i<n; i++){
        if(last < v[i].x){
            ans += last - start;
            start = v[i].x;
            last = v[i].y;
        }
        last = max(last, v[i].y);
    }
    ans += last - start;
    cout << ans;
}