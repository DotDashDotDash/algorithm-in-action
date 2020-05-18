## BST后序遍历序列的合法性

### 题目描述

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

[题目链接](https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

### 思路

对于一个BST的后序遍历序列，一定满足下面几个条件:

* 树的根节点在后序遍历序列的最后面
* 存在或者不存在一段连续的序列，使得所有的值小于根节点的值(左子树)
* 存在或者不存在一段连续的序列，使得所有的值大于根节点的值(右子树)

### AC:

* 原始版本

```java
public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if(sequence == null || sequence.length == 0)
            return false;
        return verify(sequence, 0, sequence.length - 1);
    }
    
    public boolean verify(int[] sequence, int left, int right){
        if(left >= right)    return true;
        int leftRoot = left;
        while(leftRoot < right && sequence[leftRoot] < sequence[right])
            leftRoot++;
        for(int j = leftRoot + 1; j < right; j++)
            if(sequence[j] < sequence[right])
                return false;
        return verify(sequence, left, leftRoot - 1) && verify(sequence, leftRoot, right - 1);
    }
}
```

* 还可以优化一下，剪纸，就是**如果需要verify的区间只剩两个节点，那么它一定能组成一个合法的后序遍历区间**

```java
public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if(sequence == null || sequence.length == 0)
            return false;
        return verify(sequence, 0, sequence.length - 1);
    }
    
    public boolean verify(int[] sequence, int left, int right){
        //其实也就是这里不同罢了，一个小小的优化
        if(right - left <= 1)    return true; 
        int leftRoot = left;
        while(leftRoot < right && sequence[leftRoot] < sequence[right])
            leftRoot++;
        for(int j = leftRoot + 1; j < right; j++)
            if(sequence[j] < sequence[right])
                return false;
        return verify(sequence, left, leftRoot - 1) && verify(sequence, leftRoot, right - 1);
    }
}
```