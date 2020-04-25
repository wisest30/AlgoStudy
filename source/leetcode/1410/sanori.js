/**
 * @param {string} text
 * @return {string}
 */
var entityParser = function(text) {
  const trans = {
    quot: '"',
    apos: '\'',
    amp: '&',
    gt: '>',
    lt: '<',
    frasl: '/'
  }
  const re = new RegExp('&([^&;]+);', 'g');
  const matches = text.matchAll(re);
  const n = text.length;
  const resArr = [];
  let p = 0;
  for (const m of matches) {
    const tCh = trans[m[1]];
    if (tCh !== undefined) {
      const txt = text.slice(p, m.index);
      resArr.push(txt);
      p = m.index + m[0].length;
      resArr.push(tCh);
    }
  }
  if (p < n) {
    const txt = text.slice(p);
    resArr.push(txt);
  }
  return resArr.join('');
};