const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

function isLeaf(y){
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

function getMaxDate(y, m){
    if(m == 2) return 28 + (isLeaf(y) ? 1 : 0);
    else if(m <= 7 && m % 2 == 1 || m >= 8 && m % 2 == 0) return 31;
    else return 30;
}

const T = parseInt(input[0]);
for(let i=1; i<=T; i++){
    const line = input[i].split(' ');
    const y = parseInt(line[0]);
    const m = parseInt(line[1]);
    if(m > 1) console.log(y + ' ' + (m-1) + ' ' + getMaxDate(y, m-1));
    else console.log(y-1 + ' 12 31');
}