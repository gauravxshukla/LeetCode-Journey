#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    
private:
    int m, n;
    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int letterIdx) {
        if (board[x][y] == word[letterIdx]) {
            if (letterIdx == word.size()-1) return true;
        } else return false;
        
        char temp = board[x][y];
        board[x][y] = '0';
        
        if (x-1>=0) if (dfs(board, x-1, y, word, letterIdx+1)) return true;
        if (x+1<m) if (dfs(board, x+1, y, word, letterIdx+1)) return true;
        if (y-1>=0) if (dfs(board, x, y-1, word, letterIdx+1)) return true;
        if (y+1<n) if (dfs(board, x, y+1, word, letterIdx+1)) return true;
        
        board[x][y] = temp;
        return false;
    }
};