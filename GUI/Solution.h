#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution {
private:
    bool backtracking(std::vector<std::vector<char>>& board);
    bool isValid(int row, int col, char val, std::vector<std::vector<char>>& board);
    bool isBoardValid(const std::vector<std::vector<char>>& board);

public:
    bool solveSudoku(std::vector<std::vector<char>>& board);
};

#endif // SOLUTION_H
