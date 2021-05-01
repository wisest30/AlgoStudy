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
 * @param {number[][]} tasks
 * @return {number[]}
 */
var getOrder = function(tasks) {
  const ts = tasks.map((x,i) => [x[0], x[1], i]);
  ts.sort((a, b) => b[0] - a[0]);
  // console.log({ts})

  const q = new Heap((a,b) => (a[1] !== b[1]) ? a[1] - b[1] : a[2] - b[2]);
  const res = [];
  let time = 1;
  while(ts.length > 0 || q.size() > 0) {
    while(ts.length > 0 && ts[ts.length-1][0] <= time) {
      const t = ts.pop();
      q.enQ(t);
    }
    // console.log({time, q:q.q});
    if (q.size() > 0) {
      const [_, p, i] = q.deQ();
      res.push(i);
      time += p;
    } else {
      time = ts[ts.length-1][0];
    }
  }
  return res;
};
