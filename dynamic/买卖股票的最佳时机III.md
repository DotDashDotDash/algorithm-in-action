## 买卖股票的最佳时机III

### 题目描述

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1**:

```markdown
输入: [3,3,5,0,0,3,1,4]
```

```markdown
输出: 6
```

```markdown
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
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

**示例 3**:

```markdown
输入: [7,6,4,3,1]
```

```markdown
输出: 0 
```

```markdown
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
```

[题目来源](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii)

### 解题思路

因为最多进行两笔交易，因此分为左右两个区间即可，分别在每个区间上进行[买卖股票的最佳时机I](买卖股票的最佳时机I.md)

### AC

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length <= 1)
            return 0;
        if(prices.length == 2)
            return Math.max(0, prices[1] - prices[0]);
        int[] diff = new int[prices.length - 1];
        for(int i = 1; i < prices.length; i++)
            diff[i - 1] = prices[i] - prices[i - 1];
        int maxGlobal = 0;
        for(int i = 0; i < diff.length - 1; i++){
            int maxLeft = maxSubProfit(diff, 0, i);
            int maxRight = maxSubProfit(diff, i + 1, diff.length - 1);
            maxGlobal = Math.max(maxGlobal, maxLeft + maxRight);
        }
        return maxGlobal;
    }

    private int maxSubProfit(int[] diff, int left, int right){
        int maxHere = 0, maxGlobal = 0;
        for(int i = left; i <= right; i++){
            maxHere += diff[i];
            maxGlobal = Math.max(maxGlobal, maxHere);
            if(maxHere < 0)
                maxHere = 0;
        }
        return maxGlobal;
    }
}
```