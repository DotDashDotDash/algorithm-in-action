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

