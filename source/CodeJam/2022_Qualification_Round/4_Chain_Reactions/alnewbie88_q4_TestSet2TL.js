
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
            let testCase = { N: splitedLines[i][0], F: splitedLines[i + 1], P: splitedLines[i + 2].map(num => num - 1) };
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
        "T": 3,
        "testCases": [
            {
                "N": 4,
                "F": [60,20,40,50],
                "P": [-1,0,0,1]
            },
            {
                "N": 5,
                "F": [3,2,1,4,5],
                "P": [-1,0,0,0,-1]
            },
            {
                "N": 8,
                "F": [100,100,100,90,80,100,90,100],
                "P": [-1,0,1,0,1,2,0,2]
            }
        ]
    }
    */
    let trigger = function(modules, initiatorIndex, visited, remainedInitiators) {
        let index = initiatorIndex;
        let fun = modules[index].fun;
        let additiveFun = 0;
        do {
            fun = Math.max(fun, modules[index].fun);
            visited[index] = true;
            // 방문한 모듈(index) 을 직접 트리거하는 이니시에이터가 있다면, remainedInitiators 제거
            if (moduleToTriggers.has(index)) {
                for (let i = 0; i < remainedInitiators.length; i++) {
                    const initiator = remainedInitiators[i];
                    if (moduleToTriggers.get(index).includes(initiator)) {
                        additiveFun += modules[initiator].fun;
                        remainedInitiators.splice(i, 1);
                        i--;
                    }
                }
            }
            index = modules[index].next;
        } while (index !== -1 && !visited[index])
        
        return fun + additiveFun;
    }

    for (let t = 0; t < problem.T; t++) {
        const testCase = problem.testCases[t];
        let modules = new Array(testCase.N);
        let moduleToTriggers = new Map();
        for (let i = 0; i < testCase.N; i++) {
            modules[i] = {};
            modules[i].fun = testCase.F[i];
            modules[i].next = testCase.P[i];
            if (modules[i].next !== -1) {
                if (moduleToTriggers.has(modules[i].next)) {
                    moduleToTriggers.get(modules[i].next).push(i);
                } else {
                    moduleToTriggers.set(modules[i].next, [i]);
                }
            }
        }

        let initiators = [];
        for (let i = 0; i < testCase.N; i++) {
            if (!moduleToTriggers.has(i)) {
                initiators.push(i);
            }
        }

        // dfs
        let q = [];
        for (let i = 0; i < initiators.length; i++) {
            let visited = new Array(testCase.N).fill(false);
            let remainedInitiators = initiators.slice();
            remainedInitiators.splice(i, 1);
            let fun = trigger(modules, initiators[i], visited, remainedInitiators);
            q.push({sumFun: 0 + fun, visited: visited, remainedInitiators: remainedInitiators});
        }

        let maxSumFun = 0;
        while (q.length > 0) {
            let elem = q.pop();
            if (elem.remainedInitiators.length === 0) {
                maxSumFun = Math.max(maxSumFun, elem.sumFun);
                continue;
            }

            for (let i = 0; i < elem.remainedInitiators.length; i++) {
                let visited = elem.visited.slice();
                let remainedInitiators = elem.remainedInitiators.slice();
                remainedInitiators.splice(i, 1);
                let fun = trigger(elem.remainedInitiators[i], visited, remainedInitiators);
                q.push({sumFun: elem.sumFun + fun, visited: visited, remainedInitiators: remainedInitiators});
            }
        }

        console.log(`Case #${t + 1}: ${maxSumFun}`);
    }
}

readInput();
