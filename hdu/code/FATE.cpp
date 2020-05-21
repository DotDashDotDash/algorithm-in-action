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
