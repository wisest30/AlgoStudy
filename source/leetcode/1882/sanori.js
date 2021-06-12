const Heap = (function() {
  function e(a) {
    this.q = [];
    if (void 0 === a) {
      throw Error("Comparison function is required");
    }
    this._compFn = a;
  }
  e.prototype._swap = function(a, c) {
    var b = this.q[a];
    this.q[a] = this.q[c];
    this.q[c] = b;
  };
  Object.defineProperty(e.prototype, "length", {get:function() {
    return this.q.length;
  }, enumerable:!1, configurable:!0});
  e.prototype.push = function(a) {
    var c = this.q;
    c.push(a);
    a = c.length - 1;
    for (var b = Math.floor((a + 1) / 2) - 1; 0 < a && 0 > this._compFn(c[a], c[b]);) {
      this._swap(a, b), a = b, b = Math.floor((a + 1) / 2) - 1;
    }
  };
  e.prototype.shift = function() {
    var a = this.q;
    if (!(1 > a.length)) {
      var c = a[0], b = a.pop();
      if (0 < a.length) {
        a[0] = b;
        b = 0;
        for (var d = 2 * (b + 1) - 1; d < a.length;) {
          var f = d;
          d + 1 < a.length && 0 < this._compFn(a[d], a[d + 1]) && (f = d + 1);
          if (0 >= this._compFn(a[b], a[f])) {
            break;
          }
          this._swap(b, f);
          b = f;
          d = 2 * (b + 1) - 1;
        }
      }
      return c;
    }
  };
  return e;
})();

/**
 * @param {number[]} servers
 * @param {number[]} tasks
 * @return {number[]}
 */
var assignTasks = function(servers, tasks) {
  const avail = new Heap((a,b) => (a[0] !== b[0]) ? a[0] - b[0] : a[1] - b[1]);
  const work = new Heap((a, b) => a[0] - b[0]);
  const res =[];
  for (let i = 0; i < servers.length; i++) {
    avail.push([servers[i], i]);  // weight, index
  }

  let t = 0, i = 0; 
  while (i < tasks.length) {
    if (avail.length < 1) {
      t = work.q[0][0];
    }
    while (work.length > 0 && work.q[0][0] <= t) {
      const [_, w, idx] = work.shift();
      avail.push([w, idx]);
    }
    while (i <= t && i < tasks.length && avail.length > 0) {
      const [sw, idx] = avail.shift();
      res[i] = idx;
      work.push([t + tasks[i], sw, idx]);
      i++;
    }
    t++;
  }

  return res;
};
