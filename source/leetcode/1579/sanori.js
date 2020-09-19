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

UF.prototype.clone = function() {
  const res = new UF(0);
  res.parent = this.parent.slice();
  res.size = this.size.slice();
  return res;
}

/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var maxNumEdgesToRemove = function(n, edges) {
  const uf3 = new UF(n);
  let res = 0;
  for (const [_, u, v] of edges.filter(x => x[0] === 3)) {
    const grpU = uf3.find(u-1);
    const grpV = uf3.find(v-1);
    if (grpU === grpV) {
      res++;
    } else {
      uf3.union(grpU, grpV);
    }
  }
  
  const uf2 = uf3.clone();
  for (const [_, u, v] of edges.filter(x => x[0] === 2)) {
    const grpU = uf2.find(u-1);
    const grpV = uf2.find(v-1);
    if (grpU === grpV) {
      res++;
    } else {
      uf2.union(grpU, grpV);
    }
  }
  if (uf2.sizeE(0) < n) {
    return -1;
  }
  
  const uf1 = uf3.clone();
  for (const [_, u, v] of edges.filter(x => x[0] === 1)) {
    const grpU = uf1.find(u-1);
    const grpV = uf1.find(v-1);
    if (grpU === grpV) {
      res++;
    } else {
      uf1.union(grpU, grpV);
    }
  }
  if (uf1.sizeE(0) < n) {
    return -1;
  }
  
  return res; 
};