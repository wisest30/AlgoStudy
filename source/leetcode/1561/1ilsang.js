/**
 * @param {number[]} piles
 * @return {number}
 */
const maxCoins = (piles) => {
  piles.sort((a, b) => a - b);

  let answer = 0;
  for (let i = piles.length / 3; i < piles.length; i += 2) {
    answer += piles[i];
  }
  return answer;
};