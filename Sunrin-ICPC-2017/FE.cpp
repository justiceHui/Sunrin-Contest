#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

int vs(int a, int b){
    if(a==b) return 0;
    switch(a){
        case 1:
            if(b==2) return 1;
            if(b==3) return -1;
            break;
        case 2:
            if(b==1) return -1;
            if(b==3) return 1;
            break;
        case 3:
            if(b==1) return 1;
            if(b==2) return -1;
    }
}

p arr[301];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i].first);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i].second);
    }
    int win=0; //최근 승리
    int cnt=0, ans=0;
    for(int i=0; i<n; i++){
        int res=vs(arr[i].first, arr[i].second);
        if(res==0) res=-1*win;
        if(res==win){
            cnt++;
        }
        else{
            cnt=1;
            win=res;
        }
        ans=max(cnt, ans);
    }
    printf("%d", ans);
}