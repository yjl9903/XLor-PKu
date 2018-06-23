#include <cstdio>
#include <cstring>
#include <algorithm>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn = 50000 + 5;

int pre[maxn], rank[maxn], N, K, res = 0;
void init(){
    for (int i = 0; i < maxn; i++){
        pre[i] = i;
        rank[i] = 0;
    }
}
int find(int x){
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void join(int x, int y){
    x = find(x); y = find(y);
    pre[y] = x;
}

int main(){
    init(); int cmd, x, y;
    scanf("%d%d", &N, &K);
    while (K--){
        scanf("%d%d%d", &cmd, &x, &y);
        if (x > N || y > N){
            res++;
            continue;
        }
        if (cmd == 1){

        }
        if (cmd == 2){
            if (x == y){
                res++;
                continue;
            }

        }
    }
    printf("%d", res);
    return 0;
}