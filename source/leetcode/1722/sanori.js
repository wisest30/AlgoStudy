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
 * @param {number[]} source
 * @param {number[]} target
 * @param {number[][]} allowedSwaps
 * @return {number}
 */
var minimumHammingDistance = function(source, target, allowedSwaps) {
  const n = source.length;
  const sIdx = {};
  for (let i = 0; i < n; i++) {
    const s = sIdx[source[i]];
    if (s === undefined) {
      sIdx[source[i]] = [i];
    } else {
      s.push(i);
    }
  }
  const comp = new UF(n);
  for (const [u, v] of allowedSwaps) {
    comp.union(u, v);
  }

  const used = Array(n).fill(false);
  let res = 0;
  for (let i = 0; i < n; i++) {
    const idxs = sIdx[target[i]];
    if (idxs === undefined) {
      res++;
      continue;
    }
    const icomp = comp.find(i);
    let found = false;
    for (const idx of idxs) {
      if (!used[idx] && comp.find(idx) === icomp) {
        used[idx] = true;
        found = true;
        break;
      }
    }
    if (!found) {
      res++;
    }
  }
  return res;
};
