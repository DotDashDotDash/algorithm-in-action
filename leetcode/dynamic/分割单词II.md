## 单词拆分II

### 题目描述

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

**说明：**

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
**示例 1：**

```
输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
```

```
输出:
[
  "cats and dog",
  "cat sand dog"
]
```

**示例 2：**

```
输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
```

```
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
```

**示例 3：**

```
输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
```

```
输出:
[]
```

[题目来源](https://leetcode-cn.com/problems/word-break-ii)

### 解题思路

1. 通过和[分割单词I](分割单词I.md)中的类似，但是不同的就是额外定义一个备忘录`valid[len+1][len]`，其中`valid[i][j]`表示`s[j, i)`是一个合法的字符串，可以在j处分割
2. `valid`记录完所有可以分割的位置之后，通过**从后向前**的形式进行分割，其次再配备dfs回溯与剪枝
3. 当一个单词全部分割完之后，把它纳入到`result`中

### AC

```java
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        int len = s.length();
        boolean[] f = new boolean[len + 1];
        boolean[][] valid = new boolean[len + 1][len];

        f[0] = true;    //空字符串是可以由wordDict组成
        for(int i = 1; i <= len; i++){
            for(int j = 0; j < i; j++){
                if(f[j] && wordDict.contains(s.substring(j, i))){
                    f[i] = true;
                    valid[i][j] = true;
                    // break;
                }
            }
        }

        List<String> path = new ArrayList<>();
        List<String> result = new ArrayList<>();
        dfs(s, len, path, result, valid);
        return result;
    }

    public void dfs(String s, int head, List<String> path, List<String> result, boolean[][] valid){
        if(head == 0){
            //说明已经分割了全部的字符串
            StringBuilder builder = new StringBuilder();
            for(int i = path.size() - 1; i >= 0; i--){
                builder.append(path.get(i)).append(" ");
            }
            builder.deleteCharAt(builder.length() - 1);
            result.add(builder.toString());
            return;
        }

        for(int i = 0; i < s.length(); i++){
            if(valid[head][i]){
                path.add(s.substring(i, head));
                dfs(s, i, path, result, valid);
                path.remove(path.size() - 1);
            }
        }
    }
}
```