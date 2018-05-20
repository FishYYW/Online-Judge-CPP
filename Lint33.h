#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > boards;
        string dots(n, '.');
        vector<string> board(n, dots);
        dfs(0, n, board, boards);
        return boards;
    };
private:
    // whether there would be conflict if we put a Queen on (r,c)
    bool is_Conflict(int r, int c, int n, vector<string> &board) {
        for(int i = 0; i < n; i++) {
            if(board[i][c] == 'Q' && i !=r)
                return true;
        }

        int i,j;

        i = r - 1; j = c - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][c] == 'Q')
                return true;
            i--; j--;
        }

        i = r + 1; j = c + 1;
        while(i < n && j < n) {
            if(board[i][c] == 'Q')
                return true;
            i++; j++;
        }

        i = r - 1; j = c + 1;
        while(i >= 0 && j < n) {
            if(board[i][c] == 'Q')
                return true;
            i--; j++;
        }

        i = r + 1; j = c - 1;
        while(i < n && j >= 0) {
            if(board[i][c] == 'Q')
                return true;
            i++; j--;
        }
        return false;
    }
    void dfs(int r, int n, vector<string> board, vector<vector<string> > &boards) {
        if(r == n) {
            boards.push_back(board);
            return;
        }
        // different i is different columns, which ensures one row one Queen
        for(int i = 0; i < n; i++) {
            if(is_Conflict(r, i, n, board)) {
                board[r][i] = 'Q';
                dfs(r+1, n, board, boards);
                board[r][i] = '.';
            }
        }
    }
};
