## 买卖股票的最佳时机II

### 题目描述

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1**:

```markdown
输入: [7,1,5,3,6,4]
```

```markdown
输出: 7
```

```markdown
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 
```

**示例 2**:

```markdown
输入: [1,2,3,4,5]
```

```markdown
输出: 4
```

```markdown
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

**示例 3**:

```markdown
输入: [7,6,4,3,1]
```

```markdown
输出: 0
```

```markdown
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

[题目来源](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii)

### 解题思路

可以创建差值数组diff，既然存在多次交易，那么就可以将结果转化为diff数组的最大子序列和

### AC

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length <= 1)
            return 0;
        int n = prices.length;
        int[] diff = new int[n - 1];
        for(int i = 1; i < n; i++){
            diff[i - 1] = prices[i] - prices[i - 1];
        }
        //此时因为参与了多次买卖，就转化成了求diff数组的子序列和
        int[] dp = new int[n - 1];
        dp[0] = Math.max(0, diff[0]);
        for(int i = 1; i < n - 1; i++){
            int maxTmp = 0;
            for(int j = 0; j < i; j++){
                maxTmp = Math.max(maxTmp, Math.max(dp[j], dp[j] + diff[i]));
            }
            dp[i] = maxTmp;
        }
        return dp[n - 2];
    }
}
```