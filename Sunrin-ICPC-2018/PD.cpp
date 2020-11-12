#include <bits/stdc++.h>
using namespace std;

int bin[8] = {2, 4, 8, 16, 32, 64, 128, 256};
double a, b, c;

int main(){
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if((int)b % (int)a){
        printf("둘다틀렸근");
        return 0;
    }
    if((int)c % (int)a){
        printf("둘다틀렸근");
        return 0;
    }
    
    b /= a; c /= a; a /= a;
    
    if(b*b - 4*a*c <= 0){
        printf("둘다틀렸근");
        return 0;
    }
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i==j) continue;
            if(bin[i] + bin[j] == -b && bin[i] * bin[j] == c){
                printf("이수근");
                return 0;
            }
        }
    }
    
    for(int i=-200; i<=200; i++){
        for(int j=-200; j<=200; j++){
            if(i+j == -b && i*j == c){
                printf("정수근");
                return 0;
            }
        }
    }
    
    printf("둘다틀렸근");
}