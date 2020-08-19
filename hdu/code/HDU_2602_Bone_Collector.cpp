#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		int n, s;
		scanf("%d %d", &n, &s);
		int c[n + 1], w[n + 1];
		for(int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		for(int i = 1; i <= n; i++)
			scanf("%d", &c[i]);
		int f[n + 1][s + 1];
		memset(f, 0, sizeof f);
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= s; j++){
				if(j >= c[i])
					f[i][j] = max(f[i - 1][j], f[i - 1][j - c[i]] + w[i]);
				else
					f[i][j] = f[i - 1][j];
			}
		}
		printf("%d\n", f[n][s]);
	}
	return 0;
}
