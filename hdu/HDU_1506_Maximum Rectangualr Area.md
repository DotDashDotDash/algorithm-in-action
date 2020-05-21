## HDU 1506 Maximum Rectangular Area

### Problem Description

A histogram is a polygon composed of a sequence of rectangles aligned at a common base line. The rectangles have equal widths but may have different heights. For example, the figure on the left shows the histogram that consists of rectangles with the heights 2, 1, 4, 5, 1, 3, 3, measured in units where 1 is the width of the rectangles:
![img](http://acm.hdu.edu.cn/data/images/1506-1.gif)
Usually, histograms are used to represent discrete distributions, e.g., the frequencies of characters in texts. Note that the order of the rectangles, i.e., their heights, is important. Calculate the area of the largest rectangle in a histogram that is aligned at the common base line, too. The figure on the right shows the largest aligned rectangle for the depicted histogram.

### Input

The input contains several test cases. Each test case describes a histogram and starts with an integer n, denoting the number of rectangles it is composed of. You may assume that 1 <= n <= 100000. Then follow n integers h1, ..., hn, where 0 <= hi <= 1000000000. These numbers denote the heights of the rectangles of the histogram in left-to-right order. The width of each rectangle is 1. A zero follows the input for the last test case.

### Output

For each test case output on a single line the area of the largest rectangle in the specified histogram. Remember that this rectangle must be aligned at the common base line.

### Sample Input

```
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
```

### Sample Output

```
8
4000
```

### Solving Ideas

* 令`l[i]`, `r[i]`分别表示比`i`高的最左边的横坐标，比`i`高的最右边的横坐标，则有递推公式`l[i]=min(l[i], l[l[i] - 1])`,`r[i]=max(r[i], r[r[i] + 1])`

### Code

```c++
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>

typedef long long ll;
using namespace std;

ll a[100002];
int l[100002], r[100002], n, i;

ll max(ll a, ll b){
	return a > b ? a : b;
}

int main(){
	while(~scanf("%d", &n), n){
		a[0] = a[n + 1] = -1;	//indicate that a[0] and a[n+1] must smaller than a[i]
		for(i = 1; i <= n; i++){
			scanf("%I64d", &a[i]);
			l[i] = r[i] = i;
		}
		
		//calculate left
		for(i = 1; i <= n; i++){
			while(a[l[i] - 1] >= a[i])
				l[i] = l[l[i] - 1];
		}
		
		//calculate right
		for(i = n; i >= 1; i--){
			while(a[r[i] + 1] >= a[i])
				r[i] = r[r[i] + 1];
		}
		
		//calculate res
		ll res = 0;
		for(i = 1; i <= n; i++){
			res = max(res, a[i] * (r[i] - l[i] + 1));
		}
		
		//print
		printf("%I64d\n", res);
	}
	return 0;
}
```

