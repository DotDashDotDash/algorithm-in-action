#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>

using namespace std;

int a[10001], dp[10001];

int main(){
	int N;
	while(~scanf("%d", &N)){
		if(!N)	return 1;
		memset(a, 0, sizeof a);
		for(int i = 1; i <= N; i++)
			scanf("%d", &a[i]);
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= N; i++){
			dp[i] = a[i];
			for(int j = 1; j < i; j++){
				if(a[i] > a[j])
					dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
		int max_sum = 1e-8;
		for(int i = 1; i <= N; i++)
			max_sum = max(max_sum, dp[i]);
		printf("%d\n", max_sum);
	}
	return 0;
}
