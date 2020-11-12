#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll fibo[44];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    fibo[1] = 5; fibo[2] = 13;
    for(int i=3; i<44; i++) fibo[i] = fibo[i-1] + fibo[i-2] + 1;
    
    int x; cin >> x; x--;
    for(int i=40; i>=2; i--) if(fibo[i] <= x) x -= fibo[i] + 1;
    if(x == -1 || x == 5) cout << "Messi Messi Gimossi";
    else cout << "Messi Gimossi"[x];
}