/**
 * @param {string} homepage
 */
var BrowserHistory = function(homepage) {
  this.hist = [homepage];
  this.next = 1;
};

/** 
 * @param {string} url
 * @return {void}
 */
BrowserHistory.prototype.visit = function(url) {
  if (this.hist.length > this.next) {
    this.hist = this.hist.slice(0, this.next);
  }
  this.hist.push(url);
  this.next++;
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.back = function(steps) {
  this.next = Math.max(1, this.next - steps);
  return this.hist[this.next-1];
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.forward = function(steps) {
  this.next = Math.min(this.hist.length, this.next + steps);
  return this.hist[this.next-1];
};
