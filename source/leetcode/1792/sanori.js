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
 * @param {number[][]} classes
 * @param {number} extraStudents
 * @return {number}
 */
var maxAverageRatio = function(classes, extraStudents) {
  const n = classes.length;
  const h = new Heap((a,b) => b[0] - a[0]);
  for (let i = 0; i < n; i++) {
    const [a, b] = classes[i];
    h.enQ([(a+1)/(b+1) - a/b, a, b, i]);
  }
  for (let i = 0; i < extraStudents; i++) {
    let [f, a, b, i] = h.deQ();
    a++;
    b++;
    h.enQ([(a+1)/(b+1) - a/b, a, b, i]);
  }
  let sum = 0;
  while (h.size() > 0) {
    const [f, a, b, i] = h.deQ();
    sum += a/b;
  }
  return sum / n;
};
