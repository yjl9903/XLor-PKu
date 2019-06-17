#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#ifdef XLor
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 998244353;
const int inf = 1 << 30;
const int maxn = 200000 + 5;

namespace SA {
    int n, m, sa[maxn], x[maxn], y[maxn], c[maxn], h[maxn];
    void rsort() {
        for (int i = 1; i <= m; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) c[x[i]]++;
        for (int i = 1; i <= m; i++) c[i] += c[i - 1];
        for (int i = n; i >= 1; i--) sa[c[x[y[i]]]--] = y[i];
    }
    int cmp(int i, int j, int k) {
        int a = i + k > n ? -1 : y[i + k];
        int b = j + k > n ? -1 : y[j + k];
        return y[i] == y[j] && a == b;
    }
    void build(int nn, char* s) {
        n = nn; m = 255; // important
        for (int i = 1; i <= n; i++) x[i] = s[i], y[i] = i;
        rsort();
        for (int k = 1, p; k <= n; k += k, m = p) {
            p = 0;
            for (int i = n; i > n - k; i--) y[++p] = i;
            for (int i = 1; i <= n; i++) if (sa[i] > k) y[++p] = sa[i] - k;
            rsort();
            // swap(x, y); 
            for (int i = 1; i <= n; i++) swap(x[i], y[i]);
            x[sa[1]] = p = 1;
            for (int i = 2; i <= n; i++) x[sa[i]] = cmp(sa[i], sa[i - 1], k) ? p : ++p;
        }
        for (int i = 1; i <= n; i++) x[sa[i]] = i;
        for (int i = 1, k = 0; i <= n; i++) {
            if (k) k--;
            int j = sa[x[i] - 1];
            while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
            h[x[i]] = k;
        }
    }
}

char s[maxn];
int n, m, k;

int main() {
    while (scanf("%d", &k) == 1 && k) {
        scanf("%s", s + 1);
        m = strlen(s + 1); s[m + 1] = '$';
        scanf("%s", s + m + 2);
        SA::build(n = strlen(s + 1), s);
        ll ans = 0, sum = 0;
        vector<PII> stk;
        for (int i = 2; i <= n; i++) {
            if (SA::h[i] < k) {
                stk.clear(); sum = 0; continue;
            }
            int tot = 0;
            while (!stk.empty() && stk.back().first >= SA::h[i]) {
                tot += stk.back().second;
                sum -= 1ll * (stk.back().first - SA::h[i]) * stk.back().second;
                stk.pop_back();
            }
            if (SA::sa[i - 1] <= m) {
                sum += SA::h[i] - k + 1; tot++;
            }
            stk.push_back({ SA::h[i], tot });
            if (SA::sa[i] > m) ans += sum;
        }
        stk.clear(); sum = 0;
        for (int i = 2; i <= n; i++) {
            if (SA::h[i] < k) {
                stk.clear(); sum = 0; continue;
            }
            int tot = 0;
            while (!stk.empty() && stk.back().first >= SA::h[i]) {
                tot += stk.back().second;
                sum -= 1ll * (stk.back().first - SA::h[i]) * stk.back().second;
                stk.pop_back();
            }
            if (SA::sa[i - 1] > m) {
                sum += SA::h[i] - k + 1; tot++;
            }
            stk.push_back({ SA::h[i], tot });
            if (SA::sa[i] <= m) ans += sum;
        }
        printf("%lld\n", ans);
    }
    return 0;
}