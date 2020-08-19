#include<iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[10001], i, j, res, N, sum;
vector<int> l;

int main(){
	while(~scanf("%d", &N)){
		sum = 0;
		if(N < 0)	return 0;
		l.clear();
		for(i = 0; i < N; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			for(j = 1; j <= b; j++)
				l.push_back(a);
			sum += a * b;
		}
		memset(dp, 0, sizeof dp);
		int half = sum / 2;
		for(i = 0; i < l.size(); i++){
			for(j = half; j >= l[i]; j--){
				dp[j] = max(dp[j], dp[j - l[i]] + l[i]);
			}
		}
		printf("%d %d\n", sum - dp[half], dp[half]);
	}
	return 0;
}
