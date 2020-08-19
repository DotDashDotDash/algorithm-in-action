#include<iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct block{
	int l, w, h;
	
	bool operator < (const block &p) const{ return l * w < p.l * p.w; }
	bool operator > (const block &p) const{ return l > p.l && w > p.w; }
};

vector<block> l;
int dp[10001], i, j, res, N, cnt = 1;

int main(){
	while(~scanf("%d", &N), N){
		res = 0;
		if(!N)	return 0;
		l.clear();
		for(i = 0; i < N; i++){
			int a[3];
			scanf("%d%d%d", a, a + 1, a + 2);
			sort(a, a + 3);
			l.push_back((block){a[2], a[0], a[1]});
			l.push_back((block){a[2], a[1], a[0]});
			l.push_back((block){a[1], a[0], a[2]});
		}
		sort(l.begin(), l.end());
		dp[0] = l[0].h;
		for(i = 1; i < l.size(); i++){
			dp[i] = l[i].h;
			for(j = i - 1; j >= 0; j--){
				if(l[i] > l[j])
					dp[i] = max(dp[i], dp[j] + l[i].h);
			}
			res = max(res, dp[i]);
		}
		printf("Case %d: maximum height = %d\n", cnt++, res);
	}
	return 0;
}
