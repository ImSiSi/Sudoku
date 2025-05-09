#include<vector>
#include<cstdlib>
#include <sstream>
#include<iostream>

using namespace std;

class Solution {
    private:
    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {        
            for (int j = 0; j < board[0].size(); j++) { 
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {     //to check if spot[i][j] is okay to put 'k'
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;                
                            if (backtracking(board)) return true; 
                            board[i][j] = '.';              //board[i][j] = k can't find solution
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }
    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
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
    public:
        void solveSudoku(vector<vector<char>>& board) {
            backtracking(board);
        }
    };
    

    int main() {
        vector<vector<char>> board;
        cout << "Please create the board (type one line with 9 characters(type 0 if that grid is empty), separated by space or dot for empty):" << endl;
    
        int count = 1;
        while (count <= 9) {
            cout << "Line " << count << " : ";
            string line;
            getline(cin, line); // 讀整行輸入
            istringstream iss(line);
            vector<char> chars;
            string token;
    
            while (iss >> token) {
                if (token.length() == 1 && (isdigit(token[0]))) {
                    if(token[0] == '0')
                        token[0] = '.';
                    chars.push_back(token[0]);
                } else {
                    cout << "⚠️ 忽略非法輸入（必須是單一數字或點 .）: " << token << endl;
                }
            }
    
            if (chars.size() != 9) {
                cout << "⚠️ 該行輸入長度不是 9，請重新輸入。" << endl;
                continue; // 不遞增 count，讓使用者重輸
            }
    
            board.push_back(chars);
            count++;
        }
    
        cout << "\n你輸入的棋盤如下：\n";
        for (const auto& row : board) {
            for (char c : row) cout << c << " ";
            cout << endl;
        }
    
        Solution sol;
        sol.solveSudoku(board);
    
        cout << "\n解出的 Sudoku 棋盤：\n";
        for (const auto& row : board) {
            for (char c : row) cout << c << " ";
            cout << endl;
        }
    
        return 0;
    }

    