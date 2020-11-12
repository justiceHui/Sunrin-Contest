#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int n;
int w[111][111];
vector<int> g[111];

int ans[111];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin >> w[i][j];
        if(w[i][j]) g[i].push_back(j);
    }
    for(int i=1; i<=n; i++) ans[i] = i;
    while(1){
        int flag = 1, idx;
        for(int i=1; i<=n; i++){
            int j = i + 1; if(i == n) j = 1;
            if(!w[ans[i]][ans[j]]){ flag = 0; idx = i; break; }
        }
        if(flag) break;
        for(int j=1; j<=n; j++){
            int i = idx;
            int ii = i + 1, jj = j + 1;
            if(i == n) ii = 1;
            if(j == n) jj = 1;
            if(w[ans[i]][ans[j]] && w[ans[ii]][ans[jj]]){
                if(i < j) swap(ans[ii], ans[j]);
                else swap(ans[jj], ans[i]);
                break;
            }
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}