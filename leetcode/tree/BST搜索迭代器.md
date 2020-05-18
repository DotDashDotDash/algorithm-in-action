## BST搜索迭代器

### 题目描述

实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用`next()`将返回二叉搜索树中的下一个最小的数。

[题目来源](https://leetcode-cn.com/problems/binary-search-tree-iterator/)

**示例**：

<div align=center><img src="/assets/bst-tree.png"/></div>

```markdown
BSTIterator iterator = new BSTIterator(root);
iterator.next();    // 返回 3
iterator.next();    // 返回 7
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 9
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 15
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 20
iterator.hasNext(); // 返回 false
```

**提示**:

* `next()`和`hasNext()`操作的时间复杂度是`O(1)`，并使用`O(h)`内存，其中 h 是树的高度。
* 你可以假设`next()`调用总是有效的，也就是说，当调用`next()`时，BST中至少存在一个下一个最小的数。

### 解题思路

1.思路一: 中序线索化二叉树，记录一下中序线索二叉树的搜索起始点即可(但是具体没有实现出来)，调试了半天没有找到原因

```java
class BSTIterator {
    private TreeNode inOrderHead = null;
    private TreeNode curNode = null;

    public BSTIterator(TreeNode root) {
        TreeNode cur = root;
        while(cur != null){
            if(cur.left == null){
                if(inOrderHead == null)
                    inOrderHead = cur;
                cur = cur.right;
            }else{
                TreeNode node = cur.left;
                while(node.right != null && node.right != cur)
                    node = node.right;
                if(node.right == null){
                    node.right = cur;
                    cur = cur.left;
                }else{
                    cur = cur.right;
                }
            }
        }
        curNode = inOrderHead;
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode get = curNode;
        curNode = curNode.right;
        return get.val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if(curNode != null)
            return true;
        return false;
    }
}
```

2.思路二: 利用栈实现


### AC

```java
class BSTIterator {
    private Stack<TreeNode> s = new Stack<>();

    public BSTIterator(TreeNode root) {
        TreeNode t = root;
        while(t != null){
            s.push(t);
            t = t.left;
        }
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode t = s.pop();
        int r = t.val;
        t = t.right;
        while(t != null){
            s.push(t);
            t = t.left;
        }
        return r;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !s.isEmpty();
    }
}
```