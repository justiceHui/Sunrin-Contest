#include <bits/stdc++.h>
using namespace std;

int arr[11][2];

set<int> st;

void chk(int x){ //거짓말 고정 
    for(int i=1; i<=9; i++){ //1루수 고정
        bool flag = 1;
        for(int j=1; j<=9; j++){ //쿼리
            if(j == x){
                if(arr[j][0] && arr[j][1] == i) flag = 0;
                if(!arr[j][0] && arr[j][1] != i) flag = 0;
            }else{
                if(arr[j][0] && arr[j][1] != i) flag = 0;
                if(!arr[j][0] && arr[j][1] == i) flag = 0;
            }
        }
        if(flag) st.insert(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i<=9; i++) cin >> arr[i][0] >> arr[i][1];
    
    for(int i=1; i<=9; i++) chk(i);
    
    if(st.size() == 1) cout << *st.begin();
    else cout << -1;
}