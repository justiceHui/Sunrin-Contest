#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll w, h, W, H; cin >> w >> h >> W >> H;
    ll x, y; cin >> x >> y;
    ll dx, dy; cin >> dx >> dy;
    if(dx < 0) x = W - w - x;
    if(dy < 0) y = H - h - y;
    W -= w; H -= h;
    for(int i=0; i<1010101; i++){
        ll t = W - x + i*W;
        if((y+t)%H == 0){
            cout << t; return 0;
        }
    }
    cout << -1;
}