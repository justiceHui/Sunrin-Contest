#include <bits/stdc++.h>
using namespace std;

int arr[30303];
int dist[30303];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n-1; i++) cin >> dist[i];
    
    int now = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > now){
            cout << "엄마 나 전역 늦어질 것 같아"; return 0;
        }
        now = max(now, arr[i] + dist[i]);
    }
    cout << "권병장님, 중대장님이 찾으십니다";
}