function UF(n) {
  this.parent = Array(n).fill(null).map((_, i) => i);
  this.size = Array(n).fill(1);
}

UF.prototype.find = function(a) {
  if (this.parent[a] === a) {
    return a;
  }
  const res = this.find(this.parent[a]);
  this.parent[a] = res;
  return res;
};

UF.prototype.union = function(a, b) {
  const grpA = this.find(a);
  const grpB = this.find(b);
  if (grpA === grpB) {
    return;
  }
  if (this.size[grpA] > this.size[grpB]) {
    this.parent[grpB] = grpA;
    this.size[grpA] += this.size[grpB];
  } else {
    this.parent[grpA] = grpB;
    this.size[grpB] += this.size[grpA];
  }
};

UF.prototype.sizeE = function(a) {
  const grp = this.find(a);
  return this.size[grp];
}

/**
 * @param {number} n
 * @param {number} threshold
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var areConnected = function(n, threshold, queries) {
  if (queries.length < 1) {
    return [];
  }

  const comp = new UF(n+1);
  for (let i = threshold + 1; i < n; i++) {
    for (let j = 2 * i; j <= n; j += i) {
      comp.union(i, j);
    }
  }
  const res = [];
  for (const [u, v] of queries) {
    res.push(comp.find(u) === comp.find(v));
  }
  return res;
};
