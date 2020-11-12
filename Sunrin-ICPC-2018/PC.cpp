#include <bits/stdc++.h>
using namespace std;

struct asdf{
    int a, b;
};
asdf ans[1000010];

int main(){
    int n; scanf("%d", &n);
    int arr[1010]; for(int i=1; i<=n; scanf("%d", &arr[i++]));
    
    int idx = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<n; j++){
            if(arr[j] > arr[j+1]){
                ans[idx].a = j, ans[idx++].b = j+1;
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
    printf("%d\n", idx);
    for(int i=0; i<idx; i++) printf("%d %d\n", ans[i].a, ans[i].b);
}