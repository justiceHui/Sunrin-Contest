#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

//q번째 메시지를 읽지 않은 사람 <= 마지막 메시지를 읽지 않은 사람 

typedef pair<int, char> p;

vector<p> v;
int chk[26];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, q; cin >> n >> k >> q;
    v.resize(k+1);
    for(int i=1; i<=k; i++) cin >> v[i].x >> v[i].y;
    
    if(v[q].x == 0){
        cout << -1; return 0;
    }
    
    chk[0] = 1;
    for(int i=1; i<=k; i++){
        if(v[q].x <= v[i].x) chk[v[i].y - 'A'] = 1;
    }
    
    for(int i=0; i<n; i++){
        if(!chk[i]) cout << (char)(i + 'A') << " ";
    }
}