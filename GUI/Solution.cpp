#include "Solution.h"
#include <set>
bool Solution::backtracking(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool Solution::isValid(int row, int col, char val, std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) {
        if (board[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}
bool Solution::isBoardValid(const std::vector<std::vector<char>>& board) {
    // 行檢查
    for (int i = 0; i < 9; ++i) {
        std::set<char> seen;
        for (int j = 0; j < 9; ++j) {
            char val = board[i][j];
            if (val != '.') {
                if (seen.count(val)) return false;
                seen.insert(val);
            }
        }
    }

    // 列檢查
    for (int j = 0; j < 9; ++j) {
        std::set<char> seen;
        for (int i = 0; i < 9; ++i) {
            char val = board[i][j];
            if (val != '.') {
                if (seen.count(val)) return false;
                seen.insert(val);
            }
        }
    }

    // 3x3區塊檢查
    for (int block = 0; block < 9; ++block) {
        std::set<char> seen;
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                char val = board[i][j];
                if (val != '.') {
                    if (seen.count(val)) return false;
                    seen.insert(val);
                }
            }
        }
    }

    return true;
}

bool Solution::solveSudoku(std::vector<std::vector<char>>& board) {
    if (!isBoardValid(board)) {
        return false;
    }
    return backtracking(board);
}
