## 分割回文串

### 题目描述

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

**示例**:

```markdown
输入: "aab"
```

```markdown
输出: 1
```

**解释**: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

[题目来源](https://leetcode-cn.com/problems/palindrome-partitioning-ii)

### 解题思路

我们将$dp[i]$的值作为分割$S_0, ..., S_i$的最少分割次数，那么可得到的是如果$S_j, S_{j+1}, ..., S_i(0<=j<i)$是个回文串，那么$dp[i]=min\{dp[i], dp[j - 1] + 1\}$

### AC

```java
class Solution {
    public int minCut(String s) {
        if(s == null || s.length() == 0)
            return 0;
        int len = s.length();
        int[] dp = new int[len];
        for(int i = 1; i < len; i++){
            int minVal = dp[i - 1] + 1;
            for(int j = 0; j < i; j++){
                if(isPalindrome(s, j, i)){
                    if(j == 0){
                        //说明(0, i)就是一个回文串,dp[i]不需要分割
                        minVal = 0;
                    }else{
                        //说明(j, i)是一个回文串，需要在j-1处做一次分割
                        minVal = Math.min(minVal, dp[j - 1] + 1);
                    }
                }
            }
            dp[i] = minVal;
        }
        return dp[len - 1];
    }

    private boolean isPalindrome(String s, int i, int j){
        while(i < j){
            if(s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
}
```