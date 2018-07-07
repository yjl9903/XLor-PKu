#include <iostream>
#include <cstring>
#include <algorithm>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn = 10 + 5;

int map[maxn][maxn], n, dp[1 << 11][11];

void floyd(){
    for (int k = 0; k <= n; k++) for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++){
        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    }
}

int main(){
    while (cin >> n && n){
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) cin >> map[i][j];
        floyd();
        int ss = (1 << (n + 1)) - 1;
        ms(dp, -1); dp[1][0] = 0;
        for (int s = 1; s <= ss; s += 2){
            for (int i = 0; i <= n; i++) if (dp[s][i] != -1){
                for (int j = 0; j <= n; j++) if (i != j){
                    if (dp[s | (1 << j)][j] == -1 || dp[s | (1 << j)][j] > dp[s][i] + map[i][j])
                        dp[s | (1 << j)][j] = dp[s][i] + map[i][j];
                }
            }
        }
        cout << dp[ss][0] << endl;
    }
    return 0;
}