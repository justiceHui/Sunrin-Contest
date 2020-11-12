#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

bool isp[10101];
void sieve(){
    memset(isp, 1, sizeof isp);
    isp[0] = isp[1] = 0;
    for(int i=2; i<10101; i++){
        if(!isp[i]) continue;
        for(int j=i+i; j<10101; j+=i) isp[j] = 0;
    }
}

int n, m, a[11];
set<int> st;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m; for(int i=0; i<n; i++) cin >> a[i]; sieve();
    for(int bit=0; bit<(1<<n); bit++){
        int sum = 0, cnt = 0;
        for(int i=0; i<n; i++) if(bit & (1 << i)) cnt++, sum += a[i];
        if(cnt == m && isp[sum]) st.insert(sum);
    }
    if(st.empty()){ cout << -1; return 0; }
    for(auto i : st) cout << i << " ";
}