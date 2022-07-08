const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

function gcd(a, b){ return b ? gcd(b, a % b) : a; }
function lcm(a, b){ return Math.floor(a / gcd(a, b)) * b; }

const n = +input[0] - 2;
let a = input[1].split(' ');
let res = 1;
for(let i=0; i<n; i++) res = lcm(res, +a[i]);
console.log(res);