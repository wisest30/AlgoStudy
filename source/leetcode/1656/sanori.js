/**
 * @param {number} n
 */
var OrderedStream = function(n) {
  this.ptr = 1;  
  this.q = [];
};

/** 
 * @param {number} id 
 * @param {string} value
 * @return {string[]}
 */
OrderedStream.prototype.insert = function(id, value) {
  this.q[id - this.ptr] = value;
  const res = [];
  while (this.q[0] !== undefined) {
    res.push(this.q.shift());
    this.ptr++;
  }
  return res;
};
