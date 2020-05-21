#include <iostream>
#define eps 1e-8
#define INF 0x3f3f3f3f
#define PI acos(-1)
#define lson l,mid,rt<<1
#define rson mid+1,r,(rt<<1)+1
#define CLR(x,y) memset((x),y,sizeof(x))
#define fuck(x) cerr << #x << "=" << x << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int seed = 131;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
int a[maxn];
int main() {
    while (~scanf("%d", &n), n) {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int sum, sumstart, maxsum, maxstart, maxend;
        sum = sumstart = -INF;
        maxsum = maxstart = maxend = -INF;
        for (int i = 1; i <= n; i++) {
            if (sum < 0) {
                sum = a[i];
                sumstart = a[i];
            } else sum += a[i];
            if (sum > maxsum) {
                maxsum = sum;
                maxstart = sumstart;
                maxend = a[i];
            }
        }
        if (maxsum < 0) {
            printf("0 %d %d\n", a[1], a[n]);
        } else {
            printf("%d %d %d\n", maxsum, maxstart, maxend);
        }
    }
    return 0;
}
