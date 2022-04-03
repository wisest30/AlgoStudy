
function readInput() {
    const readline = require('readline')
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
        terminal: false
    });

    let problem = {
        T: 0,
        testCases: []
    };

    rl.on('line', function (line) {
        if (problem.T === 0) {
            problem.T = Number(line);
        } else {
            const [a, b] = line.split(' ');
            problem.testCases.push([parseInt(a), parseInt(b)]);
        }
    })
    .on('close', () => {
        solveProblem(problem);
        process.exit();
    });
}

function solveProblem(problem) {
    //console.log(`problem=${JSON.stringify(problem)}`);
    /*
    problem = {
        "T": 3,
        "testCases": [
            [3,4],
            [2,2],
            [2,3]
        ]
    }
    */
    for (let t = 0; t < problem.T; t++) {
        const testCase = problem.testCases[t];
        const R = testCase[0];
        const C = testCase[1];

        let line1 = '';
        let line2 = '';
        for (let i = 0; i < C; i++) {
            line1 += '+-';
            line2 += '|.';
        }
        line1 += '+';
        line2 += '|';

        console.log(`Case #${t + 1}:`);
        for (let i = 0; i < R; i++) {
            if (i === 0) {
                console.log('..' + line1.substr(2));
                console.log('..' + line2.substr(2));
            } else {
                console.log(line1);
                console.log(line2);
            }
        }
        console.log(line1);
    }
}

readInput();
