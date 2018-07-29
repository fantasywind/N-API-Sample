const math = require('./build/Release/math');
const size = 93;

console.time('[c] Fibonacci');
const result = math.fibonacci(size);
console.timeEnd('[c] Fibonacci');

console.time('[js] Fibonacci');
let nowNum = BigInt(0);
let lastNum = BigInt(1);
let lastLastNum = BigInt(0);

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
const sumResult = math.sum(sumTimes);
console.timeEnd('[c] Sum');

console.time('[js] Sum');
let sum = 0;

for (let i = 0; i < sumTimes; i += 1) {
  sum += i;
}

console.timeEnd('[js] Sum');

console.log(sumResult);
console.log(sum);
