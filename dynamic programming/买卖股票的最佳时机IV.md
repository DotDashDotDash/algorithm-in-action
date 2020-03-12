## 买卖股票的最佳时机IV

### 题目描述

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1**:

```markdown
输入: [2,4,1], k = 2
```

```markdown
输出: 2
```

```markdown
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
```

**示例 2**:

```markdown
输入: [3,2,6,5,0,3], k = 2
```

```markdown
输出: 7
```

```markdown
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
```

[题目来源](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv)


### 解题思路

假如我们用`global[i][j]`表示前i天最多完成了j笔交易赚取的利润的最大值，用`local[i][j]`表示前i-1天最多完成了j-1笔交易且第i天完成了第j笔交易，那么可以得到递推公式

* `local[i][j] = max{local[i - 1][j] + diff, global[i - 1][j - 1] + max{0, diff}}`
* `global[i][j] = max{local[i][j], global[i - 1][j]}`

关于 local 的状态转移方程，取下面二者中较大的一个：
* 全局前 `i-1` 天进行了 `j-1` 次交易，然后然后加上今天的交易产生的利润（如果赚钱就交易，不赚钱
就不交易，什么也不发生，利润是0）
* 局部前 `i-1` 天进行了 `j` 次交易，然后加上今天的差价（ `local[i-1][j]` 是第 `i-1` 天卖出的交易，
它加上`diff`后变成第 i 天卖出，**并不会增加交易次数(精彩之处)**。无论 diff 是正还是负都要加上，否则就不满
足 local[i][j] 必须在最后一天卖出的条件了）

注意，当 k 大于数组的大小时，上述算法将变得低效，此时可以改为不限交易次数的方式解决，即等价于[买卖股票的最佳时机II](买卖股票的最佳时机II.md)


### AC

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        if(k < 1 || prices.length < 2)
            return 0;
        if(k > prices.length)
            return maxProfit2(prices);
        int[][] global = new int[prices.length][k + 1];
        int[][] local = new int[prices.length][k + 1];
        for(int i = 1; i < prices.length; i++){
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j <= k; j++){
                local[i][j] = Math.max(local[i - 1][j] + diff, global[i - 1][j - 1] + Math.max(0, diff));
                global[i][j] = Math.max(global[i - 1][j], local[i][j]);
            }
        }
        return global[prices.length - 1][k];
    }

    private int maxProfit2(int[] prices){
        int result = 0;
        for(int i = 1; i < prices.length; i++){
            if(prices[i] - prices[i - 1] > 0)
                result += prices[i] - prices[i - 1];
        }
        return result;
    }
}
```