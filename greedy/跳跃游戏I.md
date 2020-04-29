## 跳跃游戏I

### 题目描述

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

**示例 1:**

```
输入: [2,3,1,1,4]
输出: true
```

**解释:** 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

**示例 2:**

```
输入: [3,2,1,0,4]
输出: false
```

**解释:** 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

[题目来源](https://leetcode-cn.com/problems/jump-game)

### 解题思路

* 思路1：贪心算法

我们遍历这个数组，每次遍历维护一个能够到达的最大右边界maxRight

1. 如果当前位置<=maxRight，判断从当前位置能够到达的最大右边界，如果能到达更远的地方，那么刷新maxRight
2. 如果当前位置>maxRight，那么什么都不做，**就说明完全不能到达这一步！！！**


### AC1: 贪心算法

```java
class Solution {
    public boolean canJump(int[] nums) {
        int pos = 0, maxRight = 0;
        for(int i = 0; i < nums.length; i++){
            if(i <= maxRight){
                maxRight = Math.max(maxRight, i + nums[i]);
                if(maxRight >= nums.length - 1)
                    return true;
            }
        }
        return false;
    }
}
```