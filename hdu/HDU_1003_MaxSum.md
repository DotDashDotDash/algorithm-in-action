## HDU 1003 MaxSum

### **Problem Description**

Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.

### **Input**

The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).

### Output

For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.

### Sample Input

```
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
```

### Sample Output

```
Case 1:
14 1 4

Case 2:
7 1 6
```

### Code

```c++
#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int a[100001], sum, sum_start, max_start, max_end, max_sum;
int n, i, j, cases = 1;

int main(){
	scanf("%d", &n);
	while(n--){
		int c;
		scanf("%d", &c);
		for(i = 1; i <= c; i++)
			scanf("%d", &a[i]);
		sum = max_sum = -INF;
		sum_start = max_start = max_end = 1;
		for(i = 1; i <= c; i++){
			if(sum < 0){
				sum = a[i];
				sum_start = i;
			}else{
				sum += a[i];
			}
			if(sum > max_sum){
				max_sum = sum;
				max_end = i;
				max_start = sum_start;
			}
		}
		printf("Case %d:\n%d %d %d\n", cases++, max_sum, max_start, max_end);
		if(n != 0) printf("\n");
	}
	return 0;
}
```

