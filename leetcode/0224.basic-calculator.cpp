#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 双栈
// 注意
// 1：同等级别的运算符，如+，-  要及时计算，不然 1-2+3 用栈存放计算时为 (3+2)-1
// 2. 如何处理-1，分情况-1+2 和(0)-1 ，负号要补上0.
//    - 操作符为空或者(: 添加0
// 3. 1+3, (1+3) 第一种情况最后的3如何判断，结果一定需要判断 tmp == '' 不能直接用数字
class Solution {
public:
    int calculate(string s) {
        stack<string> num_st;
        stack<char> op_st;
        string tmp;

        // clean string: 1.remove space 2.add 0
        string t;
        for (const char& c : s) {
            if (c == '+') {
                if (t.empty() || t.back() == '(') t += "0+";
                else t.push_back(c);
            }  else if (c == '-') {
                if (t.empty() || t.back() == '(') t += "0-";
                else t.push_back(c);
            } else if (c != ' ') {
                t.push_back(c);
            }
        }

        s = t;
        for (const char& c:s) {
            if (c == '(') {
                op_st.push(c);
                continue;
            }
            switch (c) {
                case '+':
                case '-':
                    if (tmp != "") {
                        num_st.push(tmp); tmp = "";
                    }
                    cal(num_st, op_st);
                    op_st.push(c);
                    break;
                case ')':
                    if (tmp != "") {
                        num_st.push(tmp); tmp = "";
                    }
                    cal(num_st, op_st);
                    op_st.pop();
                    break;
                default:
                    tmp += c;
            }
        }
        if (tmp != "") {
            num_st.push(tmp);
        }
        cal(num_st, op_st);
        return atoi(num_st.top().c_str());
    }

    void cal(stack<string>& num_st, stack<char>& op_st) {
        string a; string b; char op;
        int ans;
        while(!op_st.empty() && (op_st.top() == '+' || op_st.top() == '-')) {
            op = op_st.top(); op_st.pop();
            b = num_st.top(); num_st.pop();
            a = num_st.top(); num_st.pop();
            if (op == '+') {
                ans = atoi(a.c_str()) + atoi(b.c_str());
            }
            if (op == '-') {
                ans = atoi(a.c_str()) - atoi(b.c_str());
            }
            num_st.push(to_string(ans));
        }
    }
};


int main() {
    auto ans = Solution().calculate(" -2+(-1+ 3)");
    cout << ans << endl;
    return 0;
}

// (1+(-3))
//
//
//
//
// +
// ( 1
