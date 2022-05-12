#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>
using namespace std;

// 逆波兰表达式
// 最好的题解是作图，偷懒不画了
class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}, {')', 3}};
        stack<int> n_st;
        stack<char> c_st;
        int temp_a;
        int temp_b;
        char temp_c;
        int cal_ret;
        int a = 0;
        for (auto c: s) {
            if ('0' <= c && c <= '9') {
                a = 10 * a + (c - '0');
            } else {
                switch (c) {
                    case '(':
                        c_st.push(c);
                        break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        n_st.push(a); a = 0;
                        // 一定是<= ，因为同一级别就可以弹出了
                        while (!c_st.empty() && priority[c] <= priority[c_st.top()]) {
                            temp_b = n_st.top(); n_st.pop();
                            temp_a = n_st.top(); n_st.pop();

                            temp_c = c_st.top(); c_st.pop();
                            // 顺序不能错，不然除法会有问题
                            n_st.push(cal(temp_a, temp_b, temp_c));
                        }
                        c_st.push(c);
                        break;
                    case ')':
                        while (c_st.top() != '(') {
                            temp_c = c_st.top(); c_st.pop();
                            temp_a = n_st.top(); n_st.pop();
                            a = cal(temp_a, a, temp_c);
                        }
                        c_st.pop(); // pop '('
                        break;
                }
            }
        }
        while (!c_st.empty()) {
            a = cal(n_st.top(), a, c_st.top());
            // 稍不注意容易死循环
            n_st.pop(); c_st.pop();
        }
        return a;
    }

    int cal(int a, int b, char c) {
        switch (c) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return 0;
    }
};


int main() {
    // auto ans = Solution().calculate("1+1");
    auto ans = Solution().calculate("2*(5+5*2)/3");
    cout << ans << endl;
    return 0;
}
