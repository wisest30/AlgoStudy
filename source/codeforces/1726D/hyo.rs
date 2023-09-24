use std::cell::RefCell;
use std::collections::HashSet;
use std::io::{Read, Write};
use std::rc::Rc;

struct Node {
    idx: usize,
    edges: Vec<Rc<RefCell<Edge>>>,
    par: Option<Rc<RefCell<Node>>>,
    depth: i32,
    visited: bool,
}

impl Node {
    pub fn dfs(this_rc: Rc<RefCell<Self>>) {
        this_rc.borrow_mut().visited = true;
        let this = this_rc.borrow();
        let this_idx = this.idx;
        let this_depth = this.depth;
        this.edges.iter().for_each(|edge| {
            let other_rc = {
                let node0 = Rc::clone(&edge.borrow().nodes.0);
                let node1 = Rc::clone(&edge.borrow().nodes.1);
                if node0.borrow().idx == this_idx {
                    node1
                } else {
                    node0
                }
            };

            if !other_rc.borrow().visited {
                edge.borrow_mut().color = '1';
                other_rc.borrow_mut().par = Some(Rc::clone(&this_rc));
                other_rc.borrow_mut().depth = this_depth + 1;
                Self::dfs(Rc::clone(&other_rc));
            }
        });
    }
}

struct Edge {
    nodes: (Rc<RefCell<Node>>, Rc<RefCell<Node>>),
    color: char,
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut stdout = std::io::stdout();
    let mut buf = String::new();

    stdin.read_to_string(&mut buf).unwrap();

    let mut input = buf.split_ascii_whitespace();

    let test_case = input.next().unwrap().parse::<usize>().unwrap();
    for _ in 0..test_case {
        let n = input.next().unwrap().parse::<usize>().unwrap();
        let m = input.next().unwrap().parse::<usize>().unwrap();

        let nodes = (0..n)
            .map(|i| {
                Rc::new(RefCell::new(Node {
                    idx: i,
                    edges: Vec::new(),
                    par: None,
                    depth: 0,
                    visited: false,
                }))
            })
            .collect::<Vec<_>>();

        let edges = (0..m)
            .map(|_| {
                let u = input.next().unwrap().parse::<usize>().unwrap() - 1;
                let v = input.next().unwrap().parse::<usize>().unwrap() - 1;

                let edge = Rc::new(RefCell::new(Edge {
                    nodes: (Rc::clone(&nodes[u]), Rc::clone(&nodes[v])),
                    color: '0',
                }));

                nodes[u].borrow_mut().edges.push(Rc::clone(&edge));
                nodes[v].borrow_mut().edges.push(Rc::clone(&edge));

                edge
            })
            .collect::<Vec<_>>();

        Node::dfs(Rc::clone(&nodes[0]));

        let cnt0 = edges
            .iter()
            .map(|edge| edge.borrow().color)
            .filter(|&color| color == '0')
            .count();
        if cnt0 == 3 {
            let mut node_set = HashSet::new();
            edges
                .iter()
                .filter(|edge| edge.borrow().color == '0')
                .for_each(|edge| {
                    node_set.insert(edge.borrow().nodes.0.borrow().idx);
                    node_set.insert(edge.borrow().nodes.1.borrow().idx);
                });

            if node_set.len() == 3 {
                let (_, i) = node_set
                    .iter()
                    .map(|&i| (nodes[i].borrow().depth, i))
                    .max()
                    .unwrap();

                let par_idx = nodes[i].borrow().par.as_ref().unwrap().borrow().idx;
                let edge0 = Rc::clone(
                    nodes[i]
                        .borrow()
                        .edges
                        .iter()
                        .find(|edge| edge.borrow().color == '0')
                        .unwrap(),
                );
                let edge1 = Rc::clone(
                    nodes[i]
                        .borrow()
                        .edges
                        .iter()
                        .find(|edge| {
                            edge.borrow().color == '1'
                                && edge.borrow().nodes.0.borrow().idx == par_idx
                                || edge.borrow().nodes.1.borrow().idx == par_idx
                        })
                        .unwrap(),
                );

                edge0.borrow_mut().color = '1';
                edge1.borrow_mut().color = '0';
            }
        }

        let ans = edges
            .into_iter()
            .map(|edge| edge.borrow().color)
            .collect::<String>();
        writeln!(stdout, "{ans}").ok();
    }
}
