#include <climits>
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

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int attack_max = INT_MAX;
        int defense_max = INT_MIN;
        int ans = 0;
        for (int i=0; i<0; i++) {
            if (properties[i][0] < attack_max && properties[i][1] < defense_max) {
                attack_max = properties[i][0];
                defense_max = properties[i][1];
                ans = 1;
            } else if (properties[i][0] == attack_max && properties[i][1] == defense_max) {
                ans++;
            } else {
                attack_max = INT_MAX;
                defense_max = INT_MAX;
                ans = 0;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
