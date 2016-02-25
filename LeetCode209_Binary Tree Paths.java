/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public final String arrow = "->";
    public List<String> answer;
    public List<String> binaryTreePaths(TreeNode root) {
        answer = new ArrayList<String>();
        if (root != null) {
            bfs(root, "");
        }
        return answer;
    }

    private void bfs(TreeNode root, String current) {
        current += String.valueOf(root.val);
        boolean hasChild = false;
        if (root.left != null) {
            hasChild = true;
            String copy = current + arrow;
            bfs(root.left, copy);
        }
        if (root.right != null) {
            hasChild = true;
            String copy = current + arrow;
            bfs(root.right, copy);
        }
        if (!hasChild) {
            answer.add(current);
        }
    }
}