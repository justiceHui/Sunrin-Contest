#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;

ll n, a[505050], b[505050];
vector<ll> mn, mx;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        ll x, y; cin >> x >> y;
        a[i] = x - y; mn.push_back(a[i]);
        b[i] = x + y; mx.push_back(b[i]);
    }
    sort(all(mn)); sort(all(mx));
    for(int i=1; i<=n; i++){
        int t1 = lower_bound(all(mx), a[i]) - mx.begin() + 1;
        int t2 = upper_bound(all(mn), b[i]) - mn.begin();
        cout << t1 << " " << t2 << "\n";
    }
}