let bitset;
let numOneBits;
let isFlip;

/**
 * @param {number} size
 */
var Bitset = function(size) {
    bitset = new Array(size).fill(0);
    numOneBits = 0;
    isFlip = false;
};

/** 
 * @param {number} idx
 * @return {void}
 */
Bitset.prototype.fix = function(idx) {
    if ((bitset[idx] === 1 && !isFlip) || (bitset[idx] === 0 && isFlip)) {
        return;
    }
    
    bitset[idx] = isFlip ? 0 : 1;
    numOneBits++;
};

/** 
 * @param {number} idx
 * @return {void}
 */
Bitset.prototype.unfix = function(idx) {
    if ((bitset[idx] === 0 && !isFlip) || (bitset[idx] === 1 && isFlip)) {
        return;
    }
    
    bitset[idx] = isFlip ? 1 : 0;
    numOneBits--;
};

/**
 * @return {void}
 */
Bitset.prototype.flip = function() {
    isFlip = !isFlip; 
    numOneBits = bitset.length - numOneBits;
};

/**
 * @return {boolean}
 */
Bitset.prototype.all = function() {
    return bitset.length === numOneBits;
};

/**
 * @return {boolean}
 */
Bitset.prototype.one = function() {
    return numOneBits > 0;
};

/**
 * @return {number}
 */
Bitset.prototype.count = function() {
    return numOneBits;
};

/**
 * @return {string}
 */
Bitset.prototype.toString = function() {
    if (!isFlip) {
        return bitset.join('');  
    }
    
    let ret = '';
    for (let i = 0; i < bitset.length; i++) {
        ret += bitset[i] === 0 ? '1' : '0';
    } 
    
    return ret;
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