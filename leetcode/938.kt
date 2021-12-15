/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution938 {
    
    var sum = 0
    fun rangeSumBST(root: TreeNode?, low: Int, high: Int): Int {
        root?.let { node ->
            if (node.`val` >= low && node.`val` <= high) {
                sum += node.`val`
            }

            node.left?.let { rangeSumBST(it, low, high) }
            node.right?.let { rangeSumBST(it, low, high) }
        }
        return sum
    }
}