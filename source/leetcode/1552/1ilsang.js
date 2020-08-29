/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
const maxDistance = (position, m) => {
    position.sort((a, b) => a - b);

    let l = 0;
    let r = position[position.length - 1] - position[0];
    let answer = 0;

    while (l <= r) {
        let mid = (l + r) >> 1;
        if (isPossible(position, m, mid)) {
            answer = Math.max(answer, mid);
            l = mid + 1;
        } else r = mid - 1;
    }

    return answer;
}

const isPossible = (position, m, gap) => {
    let prev = 0;
    for (let i = 0; i < position.length; i++) {
        if (prev !== 0 && position[i] - prev < gap) continue;
        prev = position[i];
        m--;
    }
    return m <= 0;
}