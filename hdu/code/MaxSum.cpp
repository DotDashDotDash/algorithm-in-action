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
