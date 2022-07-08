const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

function gcd(a, b){ return b ? gcd(b, a % b) : a; }

const tc = +input[0];
for(let i=1; i<=tc; i++){
    const n = +input[i];
    if(n % 2 == 1) console.log(n * (n-1) * (n-2));
    else if(gcd(n, n-3) ==  1) console.log(n * (n-1) * (n-3));
    else console.log((n-1) * (n-2) * (n-3));
}