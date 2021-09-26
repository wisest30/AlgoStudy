var isSubseqRepeatedK = function(sub, s, k) {
    let subIdx = 0;
    let repeatedCnt = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === sub[subIdx]) {
            subIdx++;
            if (subIdx === sub.length) {
                repeatedCnt++;
                if (repeatedCnt === k) {
                    return true;
                }
                subIdx = 0;
            }
        }
    }
    return false;
}

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var longestSubsequenceRepeatedK = function(s, k) {
    let longest = "";
    let q = [];
    q.push("");
    while(q.length > 0) {
        let sub = q.shift();
        for (let i = 0; i < 26; i++) {
            const ch = String.fromCharCode("a".charCodeAt(0) + i);
            const newSub = sub + ch;
            if (isSubseqRepeatedK(newSub, s, k)) {
                q.push(newSub);
                if (newSub.length > longest.length || (newSub.length === longest.length && newSub > longest)) {
                    longest = newSub;
                }
            }
        }
    }
    
    return longest;
};
