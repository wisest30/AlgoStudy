/**
 * @param {string[]} bank
 * @return {number}
 */
var numberOfBeams = function(bank) {
    var countSecurityDevices = function(row) {
        let cnt = 0;
        for (let i = 0; i < row.length; i++) {
            if (row[i] === '1') {
                cnt++;
            }
        }
        return cnt;
    }
    
    let totalBeams = 0;
    let beamSrcDevices = 0;
    for (let i = 0; i < bank.length; /*empty*/) {
        if (i === 0) {
            beamSrcDevices = countSecurityDevices(bank[i]);
        }
        let beamDestDevices = 0;
        for (let j = i + 1; j < bank.length; j++) {
            beamDestDevices = countSecurityDevices(bank[j]);
            if (beamDestDevices > 0) {
                i = j;
                break;
            }
        }
        
        if (beamDestDevices > 0) {
            totalBeams += beamSrcDevices * beamDestDevices;
            beamSrcDevices = beamDestDevices;
        } else {
            break;
        }
    }
    
    return totalBeams;
};