/**
 * @param {string} s
 * @return {boolean}
 */
var areNumbersAscending = function(s) {
    const tokens = s.split(' ');
    let lastNum = -1;
    for (let i = 0; i < tokens.length; i++) {
        const token = tokens[i];
		const num = parseInt(token);
		if (!isNaN(num)) {
			if (num <= lastNum) {
				return false;
			}
			lastNum = num;
        }
    }
    
    return true;
};