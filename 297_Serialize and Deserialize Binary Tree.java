/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder builder = new StringBuilder();
        Queue<TreeNode> queue = new LinkedList<TreeNode> ();
        if (root == null) return builder.toString();
        queue.offer(root);
        int count = 1;
        while (count != 0) {
        	TreeNode curr = queue.poll();
        	if (curr != null) {
        		--count;
        		builder.append(curr.val).append(",");
        		queue.offer(curr.left);
        		queue.offer(curr.right);
        		if (curr.left != null) ++count;
        		if (curr.right != null) ++count;
        	} else {
        		builder.append("null,");
        		queue.offer(null);
        		queue.offer(null);
        	}
        }
        return builder.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (isEmpty(data)) {
        	return null;
        }
        String[] ss = data.split(",");
        Map<Integer, TreeNode> map = new HashMap<Integer, TreeNode>();
        TreeNode root = null;
        for (int i = 0; i != ss.length; ++i) {
        	if (!isEmpty(ss[i]) && !ss[i].equals("null")) {
        		int number = Integer.parseInt(ss[i]);
        		TreeNode curr = new TreeNode(number);
        		if (i != 0) {
        			int j = (i - 1) / 2;
        			TreeNode parent = map.get(j);
        			if (parent != null) {
        				if (i % 2 != 0) {
	        				parent.left = curr;
	        			} else {
	        				parent.right = curr;
	        			}
        			}
        		} else {
        			root = curr;
        		}
        		map.put(i, curr);
        	}
        }
        return root;
    }

    private boolean isEmpty(String data) {
    	return data == null || "".equals(data);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));