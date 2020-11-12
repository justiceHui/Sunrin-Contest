#include <bits/stdc++.h>
using namespace std;

int  x;
void f(int n){
    if(n == 0){
        printf("No more bottles of beer on the wall, no more bottles of beer.\n");
        if(x != 1) printf("Go to the store and buy some more, %d bottles of beer on the wall.", x);
        else printf("Go to the store and buy some more, %d bottle of beer on the wall.", x);
        return;
    }
    if(n == 1){
        printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
        printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
        return;
    }
    printf("%d bottles of beer on the wall, %d bottles of beer.\n", n, n);
    if(n-1 != 1) printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", n-1);
    else printf("Take one down and pass it around, %d bottle of beer on the wall.\n\n", n-1);
}

int main(){
    int n; cin >> n;
    x = n;
    for(int i=n; i>=0; i--) f(i);
}