function Heap(compFn) {
  this.q = [];
  if (compFn === undefined) {
    throw new Error('Comparison function is required');
  }
  this.compFn = compFn;
}

Heap.prototype = {
  _swap(a, b) {
    const temp = this.q[a];
    this.q[a] = this.q[b];
    this.q[b] = temp;
  },
  get size() {
    return this.q.length;
  },
  enQ(obj) {
    const Q = this.q;
    Q.push(obj);
    let cur = Q.length - 1;
    let parent = Math.floor((cur+1) / 2) - 1;
    while (cur > 0 && this.compFn(Q[cur], Q[parent]) < 0) {
      this._swap(cur, parent);
      cur = parent;
      parent = Math.floor((cur+1) / 2) - 1;
    }
  },
  deQ() {
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
  },
  get top() {
  return this.q[0];
  }
};

/**
 * @param {number[]} apples
 * @param {number[]} days
 * @return {number}
 */

var eatenApples = function(apples, days) {
  const n = apples.length;
  const q = new Heap((a,b) => a[0] - b[0]);
  
  let res = 0;
  for (let i = 0; i < n || q.size > 0; i++) {
    if (i < n && apples[i] > 0) {
      q.enQ([i + days[i], apples[i]]);
    }
    while (q.size > 0 && (q.top[0] <= i || q.top[1] < 1)) {
      q.deQ();
    }
    if (q.size > 0) {
      q.top[1]--;
      res++;
    }
  }
  
  return res;
};
