#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

struct BigIntegar{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigIntegar(ll x = 0){*this = x;}
    BigIntegar(const string& str){
        *this = str;
    }
    BigIntegar operator = (ll x){
        s.clear(); 
        do{
            s.push_back(x % BASE);
            x /= BASE;
        } while (x > 0);
        return *this;
    }
    BigIntegar operator = (const string& str){
        s.clear(); 
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++){
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    BigIntegar operator + (const BigIntegar& b) const {
        BigIntegar c; c.s.clear();
        for (int i = 0, g = 0; ; i++){
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) x += s[i];
            if (i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
};

ostream& operator << (ostream& out, const BigIntegar& x){
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--){
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}
istream& operator >> (istream& in, BigIntegar& x){
    string str; in >> str;
    x = str;
    return in;
}

int main(){
    int T, kase = 0; cin >> T;
    BigIntegar x1, x2, res;
    while (T--){
        string s1, s2; cin >> s1 >> s2;
        x1 = s1; x2 = s2; res = x1 + x2;
        cout << "Case " << ++kase << ":\n" << s1 << " + " << s2 << " = " << res << endl;
        if (T) cout << endl;
    }
    return 0;
}