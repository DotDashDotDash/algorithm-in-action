## 恢复BST

### 题目描述

二叉搜索树中的两个节点被错误地交换

请在不改变其结构的情况下，恢复这棵树

[题目来源](https://leetcode-cn.com/problems/recover-binary-search-tree/)

**示例 1**:

```markdown
输入: [1,3,null,null,2]

   1
  /
 3
  \
   2
```

```markdown
输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
```

**示例 2**:

```markdown
输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2
```

```markdown
输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
```

**进阶**:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？

### 解题思路

1.可以通过中序遍历，设置一个pre和一个root，中序遍历序列的pre一定小于root，如果发现逆序，交换值即可
2.Morris中序遍历法

### AC

* **递归中序遍历**

```java
class Solution {
    private TreeNode errorNode1 = null;
    private TreeNode errorNode2 = null;
    private TreeNode pre = null;

    public void recoverTree(TreeNode root) {
        inOrder(root);
        int tmp = errorNode1.val;
        errorNode1.val = errorNode2.val;
        errorNode2.val = tmp;
    }

    public void inOrder(TreeNode root){
        if(root != null){
            inOrder(root.left);
            if(pre != null && pre.val > root.val){
                if(errorNode1 == null)
                    errorNode1 = pre;
                errorNode2 = root;
            }
            pre = root;
            inOrder(root.right);
        }
    }
}
```

* **Morris非递归中序遍历法**

```java
class Solution {
    private TreeNode errorNode1 = null;
    private TreeNode errorNode2 = null;
    private TreeNode pre = null;
    private TreeNode cur = null;

    public void recoverTree(TreeNode root) {
        cur = root;
        while(cur != null){
            if(cur.left == null){
                doCheckOrder(pre, cur);
                pre = cur;
                cur = cur.right;
            }else{
                TreeNode node = cur.left;
                while(node.right != null && node.right != cur)
                    node = node.right;
                if(node.right == null){
                    node.right = cur;
                    cur = cur.left;
                }else{
                    doCheckOrder(pre, cur);
                    node.right = null;
                    pre = cur;
                    cur = cur.right;
                }
            }
        }
        int tmp = errorNode1.val;
        errorNode1.val = errorNode2.val;
        errorNode2.val = tmp;
    }

    public void doCheckOrder(TreeNode pre, TreeNode cur){
        if(pre != null && pre.val > cur.val){
            if(errorNode1 == null)
                errorNode1 = pre;
            errorNode2 = cur;
        }
    }
}
```