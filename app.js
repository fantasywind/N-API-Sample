const fibonacci = require('./build/Release/fibonacci');
const size = 90;

console.time('[c] Fibonacci');
const result = fibonacci.calculate(size);
console.timeEnd('[c] Fibonacci');

console.time('[js] Fibonacci');
let nowNum = 0;
let lastNum = 1;
let lastLastNum = 0;

for (let i = 1; i < size; i += 1) {
  nowNum = lastNum + lastLastNum;
  lastLastNum = lastNum;
  lastNum = nowNum;
}

console.timeEnd('[js] Fibonacci');

console.log(result);
console.log(nowNum);

const sumTimes = 130000000;

console.time('[c] Sum');
const sumResult = fibonacci.sum(sumTimes);
console.timeEnd('[c] Sum');

console.time('[js] Sum');
let sum = 0;

for (let i = 0; i < sumTimes; i += 1) {
  sum += i;
}

console.timeEnd('[js] Sum');

console.log(sumResult);
console.log(sum);
