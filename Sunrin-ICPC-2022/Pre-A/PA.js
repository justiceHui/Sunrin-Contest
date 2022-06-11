const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

function InRange(s, e, bmi){
    return s <= bmi && bmi < e;
}

function f(h, w){
    if(h <= 140) return 6;
    if(h < 146) return 5;
    if(h < 159 || h >= 204) return 4;
    const bmi = w / (h/100.0) / (h/100.0);
    if(159 <= h && h < 161){
        if(InRange(16.0, 35.0, bmi)) return 3;
        else return 4;
    }
    if(InRange(20.0, 25.0, bmi)) return 1;
    if(InRange(18.5, 20.0, bmi) || InRange(25.0, 30.0, bmi)) return 2;
    if(InRange(16.0, 18.5, bmi) || InRange(30.0, 35.0, bmi)) return 3;
    return 4;
}

const T = parseInt(input[0]);
for(let i=1; i<=T; i++){
    const line = input[i].split(' ');
    const h = parseInt(line[0]);
    const w = parseInt(line[1]);
    console.log(f(h, w));
}