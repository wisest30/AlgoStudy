class Heap {
  constructor(compFn) {
    this.q = [];
    if (compFn === undefined) {
      throw new Error('Comparison function is required');
    }
    this.compFn = compFn;
  }

  _swap(a, b) {
    const temp = this.q[a];
    this.q[a] = this.q[b];
    this.q[b] = temp;
  }

  get length() {
    return this.q.length;
  }

  push(obj) {
    const Q = this.q;
    Q.push(obj);
    let cur = Q.length - 1;
    let parent = Math.floor((cur + 1) / 2) - 1;
    while (cur > 0 && this.compFn(Q[cur], Q[parent]) < 0) {
      this._swap(cur, parent);
      cur = parent;
      parent = Math.floor((cur + 1) / 2) - 1;
    }
  }

  shift() {
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
        if (leftChild + 1 < Q.length &&
          this.compFn(Q[leftChild], Q[leftChild + 1]) > 0) {
          minChild = leftChild + 1;
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
  }
}

/**
 * @param {number} n
 * @param {number[]} batteries
 * @return {number}
 */
var maxRunTime = function(n, batteries) {
  if (batteries.length < n) {
    return 0;
  }
  const q = new Heap((a,b) => b - a);
  for (let i = 0; i < batteries.length; i++) {
    q.push(batteries[i]);
  }

  let res = 0;
  while (q.length >= n) {
    const cand = [];
    for (let i = 0; i < n; i++) {
      cand.push(q.shift());
    }
    const last = cand[cand.length-1];
    const time = (q.length > 0) ? last - q.q[0] + 1 : last;
    console.log({cand, last, time});
    res += time;
    while (cand.length > 0) {
      const re = cand.pop() - time;
      if (re > 0) {
        q.push(re);
      }
    }
  }

  return res;
};
