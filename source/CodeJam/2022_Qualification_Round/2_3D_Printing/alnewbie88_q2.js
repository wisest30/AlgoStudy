
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
        for (let i = 0; i < splitedLines.length; i += 3) {
            let testCase = [];
            testCase.push(splitedLines[i]);
            testCase.push(splitedLines[i + 1]);
            testCase.push(splitedLines[i + 2]);
            problem.testCases.push(testCase);
        }

        solveProblem(problem);
        process.exit();
    });
}

function solveProblem(problem) {
    console.log(`problem=${JSON.stringify(problem)}`);
    /*
    problem = {
        "T": 3,
        "testCases": [
            [
                [300000,200000,300000,500000],
                [300000,200000,500000,300000],
                [300000,500000,300000,200000"]
            ],
            [
                [1000000,1000000,0,0],
                [0,1000000,1000000,1000000],
                [999999,999999,999999,999999"]
            ],
            [
                [768763,148041,178147,984173],
                [699508,515362,534729,714381],
                [949704,625054,946212,951187"]
            ]
        ]
    }
    */
    const numPrinters = 3;
    const numCartridges = 4;
    const needInkToPrintD = 1000000;
    for (let t = 0; t < problem.T; t++) {
        const testCase = problem.testCases[t];
        let minInk = new Array(4).fill(needInkToPrintD);
        for (let i = 0; i < numCartridges; i++) {
            for (let j = 0; j < numPrinters; j++) {
                minInk[i] = Math.min(minInk[i], testCase[j][i]);
            }
        }

        let ans = '';
        let sumMinInk = minInk.reduce((accum, curVal) => accum + curVal, 0);
        if (sumMinInk < needInkToPrintD) {
            ans = 'IMPOSSIBLE';
        } else {
            let remained = needInkToPrintD;
            for (let i = 0; i < numCartridges; i++) {
                const usedInk = Math.min(remained, minInk[i]);
                remained -= usedInk;
                ans += usedInk.toString() + (i === 3 ? '' : ' ');
            }
        }
        console.log(`Case #${t + 1}: ${ans}`);
    }
}

readInput();
