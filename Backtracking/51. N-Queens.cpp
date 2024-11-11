#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(int col,vector<vector<string>> &ans,vector<string> &board,
    vector<int> &leftrow, vector<int> &lowerdiagonal, vector<int> &upperdiagonal, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && 
                upperdiagonal[n-1-row+col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1-row+col]=1;
                solve(col+1,ans,board,leftrow,lowerdiagonal,upperdiagonal,n);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1-row+col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> leftrow(n,0);
        vector<int> lowerdiagonal(2*n-1,0);
        vector<int> upperdiagonal(2*n-1,0);
        solve(0,ans,board,leftrow,lowerdiagonal,upperdiagonal,n);
        return ans;
    }
};