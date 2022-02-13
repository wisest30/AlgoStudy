/**
 * @param {number} size
 */
var Bitset = function (size) {
  this.size = size;
  this.bits = [Array(size).fill(0), Array(size).fill(1)];
  this.flipped = 0;
  this.cnt = 0;
};

/** 
 * @param {number} idx
 * @return {void}
 */
Bitset.prototype.fix = function (idx) {
  if (this.bits[this.flipped][idx] === 1) return;
  this.bits[this.flipped][idx] = 1;
  this.bits[1 - this.flipped][idx] = 0;
  if (this.flipped === 1) {
    this.cnt--;
  } else {
    this.cnt++;
  }
};

/** 
 * @param {number} idx
 * @return {void}
 */
Bitset.prototype.unfix = function (idx) {
  if (this.bits[this.flipped][idx] === 1) return;
  this.bits[this.flipped][idx] = 0;
  this.bits[1 - this.flipped][idx] = 1;
  if (this.flipped === 0) {
    this.cnt--;
  } else {
    this.cnt++;
  }
};

/**
 * @return {void}
 */
Bitset.prototype.flip = function () {
  this.flipped = 1 - this.flipped;
};

/**
 * @return {boolean}
 */
Bitset.prototype.all = function () {
  return (this.flipped === 0) ? (this.cnt === this.size) : (this.cnt === 0);
};

/**
 * @return {boolean}
 */
Bitset.prototype.one = function () {
  return (this.flipped === 0) ? (this.cnt > 0) : (this.cnt < this.size);
};

/**
 * @return {number}
 */
Bitset.prototype.count = function () {
  return (this.flipped === 0) ? (this.cnt) : (this.size - this.cnt);
};

/**
 * @return {string}
 */
Bitset.prototype.toString = function () {
  // console.log({bits:this.bits, flipped:this.flipped});
  return this.bits[this.flipped].join('');
};

/** 
 * Your Bitset object will be instantiated and called as such:
 * var obj = new Bitset(size)
 * obj.fix(idx)
 * obj.unfix(idx)
 * obj.flip()
 * var param_4 = obj.all()
 * var param_5 = obj.one()
 * var param_6 = obj.count()
 * var param_7 = obj.toString()
 */
