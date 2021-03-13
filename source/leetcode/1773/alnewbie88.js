/**
 * @param {string[][]} items
 * @param {string} ruleKey
 * @param {string} ruleValue
 * @return {number}
 */
var countMatches = function(items, ruleKey, ruleValue) {
    const keyIdx = ruleKey === "type" ? 0 : ruleKey === "color" ? 1 : 2;
    let ret = 0;
    items.forEach(item => { 
        if (item[keyIdx] === ruleValue) {
           ret++; 
        }
    });
    
    return ret;
};