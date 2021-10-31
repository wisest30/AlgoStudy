/**
 * @param {string} sentence
 * @return {number}
 */
 var countValidWords = function(sentence) {
  const re = /^(?:[a-z]+(?:-[a-z]+)?)?[!.,]?$/;
  let res = 0;
  for (const w of sentence.split(' ')) {
    if (w.length > 0 && w.match(re)) {
      res++;
    }
  }
  return res;
};
