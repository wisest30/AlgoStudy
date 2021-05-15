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
 * @param {number[][]} intervals
 * @param {number[]} queries
 * @return {number[]}
 */
var minInterval = function(intervals, queries) {
  const m = intervals.length;
  const n = queries.length;
  if (m < 1) {
    return Array(n).fill(-1);
  }

  const qArr = queries.map((x, i) => [x, i]);
  const intArr = intervals.map(x => [x[0], x[1], x[1] - x[0] + 1]);
  qArr.sort((a, b) => a[0] - b[0]);
  intArr.sort((a, b) => (a[0] !== b[0]) ? a[0] - b[0] : a[1] - b[1]);
  const ints = new Heap((a,b) => (a[2] !== b[2]) ? a[2] - b[2]: ((a[0] !== b[0]) ? a[0] - b[0] : a[1] - b[1]));
  let nextI = 0;

  const res = [];
  for (let i = 0; i < n; i++) {
    const [x, idx] = qArr[i];
    while (nextI < m && intArr[nextI][0] <= x) {
      ints.enQ(intArr[nextI]);
      nextI++;
    }
    while (ints.size() > 0 && ints.q[0][1] < x) {
      ints.deQ();
    }

    if (ints.size() > 0) {
      const [l, h, d] = ints.q[0];
      if (x >= l && x <= h) {
        res[idx] = d;
      } else {
        res[idx] = -1;
      }
    } else {
      res[idx] = -1;
    }
  }

  return res;
};