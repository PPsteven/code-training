#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 定义
        int rows[9][9];
        int cols[9][9];
        int box[3][3][9];

        // 初始化为0
        memset(rows,0,sizeof(rows));
        memset(cols,0,sizeof(cols));
        memset(box,0,sizeof(box));

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                rows[i][board[i][j] - '1']++;
                cols[j][board[i][j] - '1']++;
                box[i/3][j/3][board[i][j] - '1']++;
                if (rows[i][board[i][j] - '1'] > 1 || cols[j][board[i][j] - '1'] > 1 || box[i/3][j/3][board[i][j] - '1'] > 1) {
                    return false;
                }
           }
        }
        return true;
    }
};

