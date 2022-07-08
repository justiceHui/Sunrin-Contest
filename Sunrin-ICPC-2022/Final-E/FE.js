const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const temp = input[0].split(' ');
const n = +temp[0], q = +temp[1];
let res = 0;
for(let i=1; i<=q; i++){
    const tmp = input[i].split(' ');
    const t = +tmp[0], l = +tmp[1], r = +tmp[2];
    if(t == 1) res = 1 - res;
    else if(Math.floor((r-l+1)/2)%2 == 1) res = 1 - res;
    console.log(res);
}