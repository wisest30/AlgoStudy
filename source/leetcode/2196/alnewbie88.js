/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function(descriptions) {
    const n = descriptions.length;
    let nodeMap = new Map();
    for (let i = 0; i < n; i++) {
        const desc = descriptions[i];
        const parentVal = desc[0];
        const childVal = desc[1];
        const isLeft = desc[2];
        if (!nodeMap.has(parentVal)) {
            nodeMap.set(parentVal, new TreeNode(parentVal, null, null));
        }
        if (!nodeMap.has(childVal)) {
            nodeMap.set(childVal, new TreeNode(childVal, null, null));
        }
        
        let parent = nodeMap.get(parentVal);
        let child = nodeMap.get(childVal);
        parent.val = parentVal;
        if (isLeft) {
            parent.left = child;
        } else {
            parent.right = child;
        }
        
        child.hasParent = true;
    }
    
    let rootNode = undefined;
    nodeMap.forEach((value, key) => {
        const node = value;
        if (!node.hasParent) {
            rootNode = node;
            return;
        }
    });
    
    return rootNode;
};