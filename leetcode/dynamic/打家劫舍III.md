## 打家劫舍III

### 题目描述

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

**示例 1:**

```
输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
```

**示例 2:**

```
输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
```

[题目来源](https://leetcode-cn.com/problems/house-robber-iii)


### 解题思路

假设我们用`f[i]`表示抢劫当前根节点得到的最大值，用`g[i]`表示不抢劫当前根节点得到的最大值，则我们有递推公式:

```
f[i] = i.val + g[i.left] + g[i.right]
g[i] = f[i.left] + f[i.right]
```

### AC

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int rob(TreeNode root) {
        return dfs(root)[0];
    }

    int[] dfs(TreeNode root){
        int[] dp = new int[]{0, 0};
        if(root != null){
            int[] dpl = dfs(root.left);
            int[] dpr = dfs(root.right);
            dp[1] = dpl[0] + dpr[0];
            dp[0] = Math.max(dp[1], dpl[1] + dpr[1] + root.val);
        }
        return dp;
    }
}
```