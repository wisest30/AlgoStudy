/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function(operations) {
    let ret = 0;
    operations.forEach(operation => {
        if (operation.includes("++")) {
            ret++;
        } else {
            ret--;
        }
    })
    
    return ret;
};