#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int ans = 0;
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++){
        int t; scanf("%d", &t);
        v.push_back(t);
    }
    for(int i=0; i<v.size(); i++){
        int now = 0;
        for(int j=i+1; j<v.size(); j++){
            if(v[i] > v[j]) now++;
            else break;
        }
        ans = max(ans, now);
    }
    printf("%d", ans);
}