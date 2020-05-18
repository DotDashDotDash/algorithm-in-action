## 解码方法

### 题目描述

一条包含字母 A-Z 的消息通过以下方式进行了编码：

```java
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

给定一个只包含数字的非空字符串，请计算解码方法的总数。

**示例 1:**

```java
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
```

**示例 2:**

```java
输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
```
[题目来源](https://leetcode-cn.com/problems/decode-ways)

### AC

```java
public class Solution {
    public int numDecodings(String s) {
        if (s.isEmpty() || s.charAt(0) == '0') return 0;
        int prev = 0;
        int cur = 1;
        // 长度为n的字符串，有 n+1个阶梯
        for (int i = 1; i <= s.length(); ++i) {
            if (s.charAt(i - 1) == '0') 
                cur = 0;
            if (i < 2 || !(s.charAt(i - 2) == '1' ||
                    (s.charAt(i - 2) == '2' && s.charAt(i - 1) <= '6')))
                prev = 0;
            int tmp = cur;
            cur = prev + cur;
            prev = tmp;
        }
        return cur;
    }
}
```