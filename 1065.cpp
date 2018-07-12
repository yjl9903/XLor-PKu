#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int maxn = 5000 + 5;

int n, vis[maxn];
PII p[maxn];

int main(){
    int T; cin >> T;
    while (T--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> p[i].first >> p[i].second;
        }
        sort(p, p + n); ms(vis, 0);
        int res = 0;
        for (int i = 0; i < n; i++){
            if (vis[i]) continue;
            int x = p[i].second;
            for (int j = i; j < n; j++){
                if (p[j].second >= x && !vis[j]){
                    vis[j] = 1;
                    x = p[j].second;
                }
            }
            res++;
        }
        cout << res << endl;
    }
    return 0;
}