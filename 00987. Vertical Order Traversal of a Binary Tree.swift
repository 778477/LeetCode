/**
 987. Vertical Order Traversal of a Binary Tree
 DescriptionHintsSubmissionsDiscussSolution
 Given a binary tree, return the vertical order traversal of its nodes values.
 
 For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
 
 Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
 
 If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
 
 Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
 
 
 
 Example 1:
 
 
 
 Input: [3,9,20,null,null,15,7]
 Output: [[9],[3,15],[20],[7]]
 Explanation:
 Without loss of generality, we can assume the root node is at position (0, 0):
 Then, the node with value 9 occurs at position (-1, -1);
 The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
 The node with value 20 occurs at position (1, -1);
 The node with value 7 occurs at position (2, -2).
 Example 2:
 
 
 
 Input: [1,2,3,4,5,6,7]
 Output: [[4],[2],[1,5,6],[3],[7]]
 Explanation:
 The node with value 5 and the node with value 6 have the same position according to the given scheme.
 However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 
 
 Note:
 
 The tree will have between 1 and 1000 nodes.
 Each node's value will be between 0 and 1000.
 
 
 */
//30 / 30 test cases passed.
//Status: Accepted
//Runtime: 16 ms

//Definition for a binary tree node.
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    typealias Dic = [Int:[(Int,Int)]] // x:(y,val)
    var min_x_level = Int.max
    var max_x_level = Int.min
    func dfs(_ root: TreeNode?, _ dic: inout Dic, _ x: Int, _ y: Int){
        guard let root = root else {
            return
        }
        dic[x,default: []].append((y, root.val))
        min_x_level = min(min_x_level, x)
        max_x_level = max(max_x_level, x)
        dfs(root.left, &dic, x-1, y-1)
        dfs(root.right, &dic, x+1, y-1)
    }
    func verticalTraversal(_ root: TreeNode?) -> [[Int]] {
        
        var dic : Dic = Dic()
        dfs(root, &dic, 0, 0)
        
        var ans : [[Int]] = [[Int]]()
        for i in min_x_level...max_x_level{
            if let nodes = dic[i] {
                ans.append( nodes.sorted{ return $0.0 < $1.0 || $0.0==$1.0 && $0.1 < $1.1}.map{$0.1} )
            }
        }
        return ans
    }
}


var root : TreeNode = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right?.left = TreeNode(15)
root.right?.right = TreeNode(7)

let solution : Solution = Solution()
print(solution.verticalTraversal(root))

