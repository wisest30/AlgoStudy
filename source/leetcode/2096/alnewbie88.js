/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
var getDirections = function(root, startValue, destValue) {
    let startNode = null;
    let destNode = null;
    var traverse = function(parent, node) {
        if (!node) {
            return;
        }
        
        node.up = parent;
        if (node.val === startValue) {
            startNode = node;
        } else if (node.val === destValue) {
            destNode = node;
        }
        
        traverse(node, node.left);
        traverse(node, node.right);
    }
    
    traverse(null, root);
    
    // dfs
    let visited = new Array(100001).fill(false);
    let q = [];
    q.push({node: startNode, path: ""});
    while(q.length > 0) {
        let elem = q.pop();
        if (visited[elem.node.val]) {
            continue;
        }
        
        visited[elem.node.val] = true;
        if (elem.node.val === destValue) {
            return elem.path;   // possible only one path from start to dest.
        }
        
        if (elem.node.up) {
            q.push({node: elem.node.up, path: elem.path + "U"});
        }
        if (elem.node.left) {
            q.push({node: elem.node.left, path: elem.path + "L"});
        }
        if (elem.node.right) {
            q.push({node: elem.node.right, path: elem.path + "R"});
        }
    }
    
    return "";  // error!
};
