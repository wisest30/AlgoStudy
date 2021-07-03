/**
 * @param {string} startTime
 * @param {string} finishTime
 * @return {number}
 */
var numberOfRounds = function(startTime, finishTime) {
    let parse = startTime.split(':');
    let startTimeHour = Number.parseInt(parse[0]);
    let startTimeMin = Number.parseInt(parse[1]);
    
    parse = finishTime.split(':');
    let finishTimeHour = Number.parseInt(parse[0]);
    let finishTimeMin = Number.parseInt(parse[1]);
    
    let startTimeTotalMin = startTimeHour * 60 + startTimeMin;
    let finishTimeTotalMin = finishTimeHour * 60 + finishTimeMin;
    if (startTimeTotalMin > finishTimeTotalMin) {
        let padding = Math.ceil((1440 - startTimeTotalMin) / 60) * 60;
        startTimeTotalMin = (startTimeTotalMin + padding) % 1440;
        finishTimeTotalMin = (finishTimeTotalMin + padding);
    }

    let startedRounds = 0;
    for (let i = startTimeTotalMin; i <= finishTimeTotalMin; i++) {
        if (i % 15 === 0) {
            startedRounds++;
        }
    }
    
    return Math.max(0, startedRounds - 1);
};