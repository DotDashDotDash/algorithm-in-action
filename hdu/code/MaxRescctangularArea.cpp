#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>

typedef long long ll;
using namespace std;

ll m, n, d;
int i, c;

int main(){
	while(~scanf("%I64d %I64d", &m, &n), m && n){
		c = 0;
		for(d = m; d <= n; d++){
			int t = d, last = -1;
			while(t){
				int cur = t % 10;
				if((cur == 4) || (cur == 2 && last == 6)){
					c++;
					break;
				}
				last = cur;
				t /= 10;
			}
		}
		printf("%d\n", n - m + 1 - c);
	}
	return 0;
}
