## 买卖股票的最佳时机V

### 题目描述

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

```markdown
输入: [1,2,3,0,2]
```

```markdown
输出: 3 
```

```markdown
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
```

[题目来源](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown)

### 解题思路

假如我们用`sell[i]`表示第i天不持有股票的最大利润，用`buy[i]`表示第i天持有股票的最大利润，可以得到递推公式

* `sell[i] = max(sell[i - 1], buy[i - 1] + prices[i])`
* `buy[i] = max(buy[i - 1], sell[i - 1] - prices[i])`

### AC

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length < 2)
            return 0;
        int n = prices.length;
        int[] sell = new int[n];
        int[] buy = new int[n];
        buy[0] = -prices[0];  //第一天买入
        for(int i = 1; i < n; i++){
            sell[i] = Math.max(buy[i - 1] + prices[i], sell[i - 1]);
            buy[i] = Math.max(((i >= 2) ? sell[i - 2] : 0) - prices[i], buy[i - 1]);
        }
        return sell[n - 1];
    }
}
```