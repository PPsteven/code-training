#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

// 本题是细心题，但是没有一次AC
class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) {
            return "IPv4";
        }
        if (isIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

    bool isIPv4(string s) {
        vector<string> ip_addr;
        string tmp;
        for (char c: s) {
            if (c == '.') {
                ip_addr.push_back(tmp); tmp ="";
            } else {
                tmp += c;
            }
        }
        ip_addr.push_back(tmp);

        if (ip_addr.size() != 4) {
            return false;
        }

        for (string ip: ip_addr) {
            // !!!! 没有考虑到可能为空
            if (ip.length()==0) {
                return false;
            }
            int i = 0;
            for (char c: ip) {
                // 数字
                if (c < '0' || c>'9') {
                    return false;
                }
                // leading zero
                if (ip.length()>1 && ip[0]=='0') {
                    return false;
                }
                i = 10*i + c - '0';
                //!!! 没有考虑到超过最大值的情况, python养成的坏习惯
                if (i >= 256) {
                    return false;
                }
            }
            if (i >= 256) {
                return false;
            }
        }
        return true;
    }

    bool isIPv6(string s) {
        vector<string> ip_addr;
        string tmp;
        for (char c: s) {
            if (c == ':') {
                ip_addr.push_back(tmp); tmp ="";
            } else {
                tmp += c;
            }
        }
        ip_addr.push_back(tmp);

        if (ip_addr.size() != 8) {
            return false;
        }

        for (string ip: ip_addr) {
            int i = 0;
            // 大小在1~4
            if (ip.length()<1 || ip.length()>4) {
                return false;
            }
            for (char c: ip) {
                // 16 进制
                if (!((c>='a' && c <='f')
                     || (c>='A' && c<='F')
                     || (c>='0' && c<='9')
                    )) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    auto ans = Solution().isIPv6("192.0.0.1");
    cout << ans << endl;
    return 0;
}
