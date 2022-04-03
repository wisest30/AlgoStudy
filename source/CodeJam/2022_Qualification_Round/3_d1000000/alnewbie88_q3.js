
function readInput() {
    const readline = require('readline')
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
        terminal: false
    });

    let splitedLines = [];
    let problem = {
        T: 0,
        testCases: [],
    };

    rl.on('line', function (line) {
        if (problem.T === 0) {
            problem.T = Number(line);
        } else {
            splitedLines.push(line.split(' ').map(str => parseInt(str)));
        }
    })
    .on('close', () => {
        for (let i = 0; i < splitedLines.length; i += 2) {
            let testCase = { N: splitedLines[i + 1].length, S: splitedLines[i + 1] };
            problem.testCases.push(testCase);
        }

        solveProblem(problem);
        process.exit();
    });
}

function solveProblem(problem) {
    //console.log(`problem=${JSON.stringify(problem)}`);
    /*
    problem = {
        "T": 4,
        "testCases": [
            {
                "N": 4,
                "S": [6,10,12,8]
            },
            {
                "N": 6,
                "S": [5,4,5,4,4,4]
            },
            {
                "N": 10,
                "S": [10,10,7,6,7,4,4,5,7,4]
            },
            {
                "N": 1,
                "S": [10]
            }
        ]
    }
    */
    for (let t = 0; t < problem.T; t++) {
        const testCase = problem.testCases[t];
        testCase.S.sort((a, b) => { return a - b; });
        
        let ans = 0;
        testCase.S.forEach(dice => {
            if (dice >= ans + 1) {
                ans++; 
            } else {
                return;
            }
        });

        console.log(`Case #${t + 1}: ${ans}`);
    }
}

readInput();
