## HDU 2955 Roberries

### Problem Description

The aspiring Roy the Robber has seen a lot of American movies, and knows that the bad guys usually gets caught in the end, often because they become too greedy. He has decided to work in the lucrative business of bank robbery only for a short while, before retiring to a comfortable job at a university.

For a few months now, Roy has been assessing the security of various banks and the amount of cash they hold. He wants to make a calculated risk, and grab as much money as possible.
His mother, Ola, has decided upon a tolerable probability of getting caught. She feels that he is safe enough if the banks he robs together give a probability less than this.

### **Input**

The first line of input gives T, the number of cases. For each scenario, the first line of input gives a floating point number P, the probability Roy needs to be below, and an integer N, the number of banks he has plans for. Then follow N lines, where line j gives an integer Mj and a floating point number Pj .
Bank j contains Mj millions, and the probability of getting caught from robbing it is Pj .

### **Output**

For each test case, output a line with the maximum number of millions he can expect to get while the probability of getting caught is less than the limit set.

Notes and Constraints

```markdown
0 < T <= 100
0.0 <= P <= 1.0
0 < N <= 100
0 < Mj <= 100
0.0 <= Pj <= 1.0
```

A bank goes bankrupt if it is robbed, and you may assume that all probabilities are independent as the police have very low funds.

### **Sample Input**

```markdown
3
0.04 3
1 0.02
2 0.03
3 0.05
0.06 3
2 0.03
2 0.03
3 0.05
0.10 3
1 0.03
2 0.02
3 0.05
```

### **Sample Output**

```markdown
2
4
6
```

### Solving Ideas

* 被抓的概率不是简单相加的，也不是简单相乘的，所以这一题要先转换，把 被抓的概率转换为逃跑的概率才能实现概率的相乘
* dp算法，dp[0]表示没有抢劫，逃跑概率100%，即`dp[0]`=1
* `dp[j]=max(dp[j], dp[j-bank[i]] * escape[i])` ，即当抢劫数额为`j`的时候的逃跑概率，存在两种情况，本次没抢，即`dp[j]=dp[j]`，本次抢了，即`dp[j]=dp[j - bank[i]] * escape[i]`

### Code

```c++
#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>

using namespace std;

int a[101];	//money in the bank
double dp[10010], b[101];	//b means the escape rate of each back robbering

double max(double a, double b){
	return a > b ? a : b;
}

int main(){
	int t;
	scanf("%d", &t);	//case num
	while(t--){
		int i, j, m, n, sum = 0;
		double c;	//max caught rate
		scanf("%lf%d", &c, &n);
		c = 1 - c;	//transfer to escape rate
		for(i = 1; i <= n; i++){
			double e;
			scanf("%d%lf", &a[i], &e);
			b[i] = 1 - e;
			sum += a[i];
		}
		memset(dp, 0, sizeof dp);
		dp[0] = 1;	//no robbery, no caught rate
		for(i = 1; i <= n; i++){
			for(j = sum; j >= a[i]; j--){
				dp[j] = max(dp[j], dp[j - a[i]] * b[i]);
			}
		}
		for(j = sum; j >= 0; j--){
			if(dp[j] >= c){
				printf("%d\n", j);
				break;
			}
		}
	}
	return 1;
}
```



