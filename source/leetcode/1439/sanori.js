/**
 * @class Heap
 */
function Heap() {
  this.q = [];
}

Heap.prototype._swap = function(a, b) {
  const temp = this.q[a];
  this.q[a] = this.q[b];
  this.q[b] = temp;
};

/**
 * Returns the size of the heap
 * @method Heap#size
 * @return {Number}
 */
Heap.prototype.size = function() {
  return this.q.length;
};

/**
 * Enqueue obj to the heap
 * @method Heap#enQ
 * @param {Object} obj object to be pushed
 * @param {Object} key comparable key
 */
Heap.prototype.enQ = function(obj, key) {
  const Q = this.q;
  Q.push({key, obj});
  let cur = Q.length - 1;
  let parent = Math.floor((cur+1) / 2) - 1;
  while (cur > 0 && (Q[cur].key < Q[parent].key)) {
    this._swap(cur, parent);
    cur = parent;
    parent = Math.floor((cur+1) / 2) - 1;
  }
};

/**
 * Dequeue (get smallest object) from the heap
 * @method Heap#deQ
 * @return {Object} smallest object
 */
Heap.prototype.deQ = function() {
  const Q = this.q;
  if (Q.length < 1) {
    return;
  }
  const res = Q[0].obj;
  const last = Q.pop();
  if (Q.length > 0) {
    Q[0] = last;
    let cur = 0;
    let leftChild = (cur + 1) * 2 - 1;
    while (leftChild < Q.length) {
      let minChild = leftChild;
      if (leftChild+1 < Q.length && Q[leftChild].key > Q[leftChild+1].key) {
        minChild = leftChild + 1; // rightChild;
      }
      if (Q[cur].key <= Q[minChild].key) {
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
 * @param {number[][]} mat
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(mat, k) {
  const m = mat.length;
  if (m < 1) {
    return 0;
  }
  const n = mat[0].length;
  const diffMat = Array(m);
  for (let i = 0; i < m; i++) {
    const d = [mat[i][0]];
    for (let j = 1; j < n; j++) {
      d[j] = mat[i][j] - mat[i][j-1];
    }
    diffMat[i] = d;
  }
  // console.log({diffMat});
  
  const q = new Heap();
  const seen = new Set();
  const config = Array(m).fill(0);
  let sum = mat.map(x => x[0]).reduce((a, b) => a + b, 0);
  config.push(sum);
  q.enQ(config, sum);
  let count = 0;
  while (q.size() > 0) {
    const cnf = q.deQ();
    const curSum = cnf[m];
    if (++count === k) {
      return curSum;
    }
    for (let i = 0; i < m; i++) {
      const newConf = cnf.slice();
      const newCol = ++newConf[i];
      const newIdx = newConf.slice(0, m).join(',');
      if (seen.has(newIdx)) {
        continue;
      }
      if (newCol >= n) continue;
      const newSum = curSum + diffMat[i][newCol];
      newConf[m] = newSum;
      q.enQ(newConf, newSum);
      seen.add(newIdx);
    }
  }
  return 0;
};
