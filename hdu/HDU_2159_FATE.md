## FATE

### Problem Description

最近xhd正在玩一款叫做FATE的游戏，为了得到极品装备，xhd在不停的杀怪做任务。久而久之xhd开始对杀怪产生的厌恶感，但又不得不通过杀怪来升完这最后一级。现在的问题是，xhd升掉最后一级还需n的经验值，xhd还留有m的忍耐度，每杀一个怪xhd会得到相应的经验，并减掉相应的忍耐度。当忍耐度降到0或者0以下时，xhd就不会玩这游戏。xhd还说了他最多只杀s只怪。请问他能升掉这最后一级吗？

### Input

输入数据有多组，对于每组数据第一行输入n，m，k，s(0 < n,m,k,s < 100)四个正整数。分别表示还需的经验值，保留的忍耐度，怪的种数和最多的杀怪数。接下来输入k行数据。每行数据输入两个正整数a，b(0 < a,b < 20)；分别表示杀掉一只这种怪xhd会得到的经验值和会减掉的忍耐度。(每种怪都有无数个)

### Output

输出升完这级还能保留的最大忍耐度，如果无法升完这级输出-1。

### Sample Input

```
10 10 1 10
1 1
10 10 1 9
1 1
9 10 2 10
1 1
2 2
```

 ### Sample Output

```
0
-1
1
```

### Code

```c++
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int n, m, k, s;	//还需的经验数，保留的忍耐度，怪物的种类数，最多的杀怪数
int dp[101][101];	//dp[i][j] = k表示当剩余耐久度为i,杀怪数为j时得到的最大exp
int exps[101], cost[101];

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	while(~scanf("%d %d %d %d", &n, &m, &k, &s)){
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= k; i++){
			scanf("%d %d", &exps[i], &cost[i]);
		}
		
		for(int u = 1; u <= k; u++){
			for(int i = cost[u]; i <= m; i++){
				for(int j = 1; j <= s; j++){
					dp[i][j] = max(dp[i][j], dp[i - cost[u]][j - 1] + exps[u]);
				}
			}
		}
		
		int i;
		for(i = 1; i <= m; i++){
			if(dp[i][s] >= n)
				break;
		}
		
		if(i <= m)	printf("%d\n", m - i);
		else printf("-1\n");
	}
	return 0;
} 
```

