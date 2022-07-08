const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const temp = input[0].split(' ');
const a = +temp[0], b = +temp[1], c = +temp[2], d = +temp[3];
const n = +input[1];
let cnt = 0;
for(let i=2; i<=n+1; i++){
    const tmp = input[i].split(' ');
    const u = +tmp[0], v = +tmp[1];
    if(a * (v-b) * (v-b) + c == u) cnt += 1;
}
console.log(cnt);