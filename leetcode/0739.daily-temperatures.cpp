#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    // vector<int> temperatures = {5, 4, 1};
    auto ans = Solution().dailyTemperatures(temperatures);
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
