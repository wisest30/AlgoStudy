/**
 * @param {number} n
 * @param {number[][]} meetings
 * @param {number} firstPerson
 * @return {number[]}
 */
var findAllPeople = function(n, meetings, firstPerson) {
    // sort meetings by time asc (for Map.forEach iteration order)
    meetings.sort(function(a, b) { return a[2] - b[2]; });
    
    let timeToMeetingIndexes = new Map();
    for (let i = 0; i < meetings.length; i++) {
        const time = meetings[i][2];
        if (!timeToMeetingIndexes.has(time)) {
            timeToMeetingIndexes.set(time, new Array());
        }
        timeToMeetingIndexes.get(time).push(i);
    }
    
    let personHasSecret = new Array(n).fill(false);
    personHasSecret[0] = true;
    personHasSecret[firstPerson] = true;
    
    timeToMeetingIndexes.forEach(function(value, key) {
        const time = key;
        const meetingIndexesOnTime = value;
        
        let personToGroup = new Map();
        let groupToPersons = new Map();
        let incrementGroupID = 1;
        for (let i = 0; i < meetingIndexesOnTime.length; i++) {
            const a = meetings[meetingIndexesOnTime[i]][0];
            const b = meetings[meetingIndexesOnTime[i]][1];
            const groupIDInA = personToGroup.get(a);
            const groupIDInB = personToGroup.get(b);
            if (!groupIDInA && !groupIDInB) {
                const groupID = incrementGroupID++;
                groupToPersons.set(groupID, new Set());
                groupToPersons.get(groupID).add(a);
                groupToPersons.get(groupID).add(b);
                personToGroup.set(a, groupID);
                personToGroup.set(b, groupID);
            } else if (!groupIDInA) {
                groupToPersons.get(groupIDInB).add(a);
                personToGroup.set(a, groupIDInB);
            } else if (!groupIDInB) {
                groupToPersons.get(groupIDInA).add(b);
                personToGroup.set(b, groupIDInA);
            } else if (groupIDInA !== groupIDInB) {
                // merge groupInB to groupInA
                const personsInGroupB = groupToPersons.get(groupIDInB);
                for (let person of personsInGroupB) {
                    groupToPersons.get(groupIDInA).add(person);
                    personToGroup.set(person, groupIDInA);
                }
                groupToPersons.delete(groupIDInB);
            }
        }
        
        groupToPersons.forEach(function(value, key) {
            const groupID = key;
            const personsInGroup = value;
            let secretSharedOnGroup = false;
            for (let person of personsInGroup) {
                if (personHasSecret[person]) {
                    secretSharedOnGroup = true;
                    break;
                }
            }
            
            if (secretSharedOnGroup) {
                for (let person of personsInGroup) {
                    personHasSecret[person] = true;
                }
            }
        });
    });
    
    let hasSecretPersonIndexes = [];
    for (let i = 0; i < n; i++) {
        if (personHasSecret[i]) {
            hasSecretPersonIndexes.push(i);
        }
    }
    
    return hasSecretPersonIndexes;
};
