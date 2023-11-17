#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n, int startRow, int startCol) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        // Place the first queen at the specified position
        board[startRow][startCol] = 'Q';

        // Start solving from the next column
        solve(startCol + 1, board, ans, n);
        return ans;
    }
};

int main() {
    int n = 4;  // we are taking a 4*4 grid and 4 queens
    int startRow = 2;
    int startCol = 0;

    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n, startRow, startCol);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
