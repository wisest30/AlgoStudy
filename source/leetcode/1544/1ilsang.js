/**
 * @param {string} s
 * @return {string}
 */
const makeGood = (s) => {
  const stack = [];

  [...s].forEach((e) => {
    const TOP = stack.length - 1;
    if (TOP === -1) {
      stack.push(e);
      return;
    }

    Math.abs(stack[TOP].charCodeAt() - e.charCodeAt()) === 32
      ? stack.pop()
      : stack.push(e);
  });

  return stack.join("");
};
