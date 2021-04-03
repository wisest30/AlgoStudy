function Heap(compFn) {
  this.q = [];
  if (compFn === undefined) {
    throw new Error('Comparison function is required');
  }
  this.compFn = compFn;
}

Heap.prototype._swap = function(a, b) {
const temp = this.q[a];
this.q[a] = this.q[b];
this.q[b] = temp;
};

Heap.prototype.size = function() {
return this.q.length;
};

Heap.prototype.enQ = function(obj) {
const Q = this.q;
Q.push(obj);
let cur = Q.length - 1;
let parent = Math.floor((cur+1) / 2) - 1;
while (cur > 0 && this.compFn(Q[cur], Q[parent]) < 0) {
  this._swap(cur, parent);
  cur = parent;
  parent = Math.floor((cur+1) / 2) - 1;
}
};

Heap.prototype.deQ = function() {
const Q = this.q;
if (Q.length < 1) {
  return;
}
const res = Q[0];
const last = Q.pop();
if (Q.length > 0) {
  Q[0] = last;
  let cur = 0;
  let leftChild = (cur + 1) * 2 - 1;
  while (leftChild < Q.length) {
    let minChild = leftChild;
    if (leftChild+1 < Q.length &&
        this.compFn(Q[leftChild], Q[leftChild+1]) > 0) {
      minChild = leftChild + 1; // rightChild;
    }
    if (this.compFn(Q[cur], Q[minChild]) <= 0) {
      break;
    }
    this._swap(cur, minChild);
    cur = minChild;
    leftChild = (cur + 1) * 2 - 1;
  }
}
return res;
};

/**
* @param {number[][]} orders
* @return {number}
*/
var getNumberOfBacklogOrders = function(orders) {
const buy = new Heap((a,b)=>b[0]-a[0]);
const sell = new Heap((a,b)=>a[0]-b[0]);
for (let [price, amount, type] of orders) {
  if (type) { // sell
    while (buy.size()> 0 && buy.q[0][0] >= price && amount > 0) {
      let [priceB, amountB] = buy.deQ();
      const a = Math.min(amountB, amount);
      amountB -= a;
      amount -= a;
      if (amountB > 0) {
        buy.enQ([priceB, amountB]);
      }
    }
    if (amount > 0) {
      sell.enQ([price, amount]);
    }
  } else {
    while (sell.size()> 0 && sell.q[0][0] <= price && amount > 0) {
      let [priceS, amountS] = sell.deQ();
      const a = Math.min(amountS, amount);
      amountS -= a;
      amount -= a;
      if (amountS > 0) {
        sell.enQ([priceS, amountS]);
      }
    }
    if (amount > 0) {
      buy.enQ([price, amount]);
    }
  }
}
const mod = 1e9 + 7;
let res = 0;
while (buy.size() > 0) {
  const [_, amount] = buy.deQ();
  res = (res + amount) % mod;
}
while (sell.size() > 0) {
  const [_, amount] = sell.deQ();
  res = (res + amount) % mod;
}

return res;
};