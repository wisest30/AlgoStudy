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
 * @param {number[][]} edgeList
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var distanceLimitedPathsExist = function(n, edgeList, queries) {
  const en = edgeList.length;
  edgeList.sort((a, b) => a[2] - b[2]);
  const queries2 = queries.map((x, i) => [x[0], x[1], x[2], i])
     .sort((a,b) => a[2] - b[2]);
  const res = [];
  const uf = new UF(n);
  let ei = 0;
  for (const [p, q, limit, i] of queries2) {
    while (ei < en && edgeList[ei][2] < limit) {
      uf.union(edgeList[ei][0], edgeList[ei][1]);
      ei++;
    }
    res[i] = (uf.find(p) === uf.find(q));
  }
  return res;
};
