/**
 * @param {string[]} names
 * @return {string[]}
 */
const getFolderNames = (names) => {
  const answer = names.reduce((acc, cur) => {
    if (!acc.has(cur)) {
      acc.set(cur, 1);
      return acc;
    }

    let cnt = acc.get(cur);
    let next = `${cur}(${cnt})`;

    while (acc.has(next)) {
      cnt++;
      next = `${cur}(${cnt})`;
    }

    acc.set(cur, cnt);
    acc.set(next, 1);
    return acc;
  }, new Map());

  return [...answer.keys()];
};
