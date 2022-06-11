const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

n = parseInt(input[0]);
s = input[1];

res = '';
for(let i=0; i<n; i++) res += s;
console.log(res);