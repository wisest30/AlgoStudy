/**
 * @param {string[]} names
 * @return {string[]}
 */
var getFolderNames = function(names) {
  const fns = new Set();
  const res = [];
  for (const fn of names) {
    if (fns.has(fn)) {
      let i = 1;
      let nfn = `${fn}(${i})`;
      while (fns.has(nfn)) {
        i++;
        nfn = `${fn}(${i})`;
      }
      fns.add(nfn);
      res.push(nfn);
    } else {
      fns.add(fn);
      res.push(fn);
    }
  }
  return res;
};