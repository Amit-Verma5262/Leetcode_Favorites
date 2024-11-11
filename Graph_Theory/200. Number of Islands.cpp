#include <bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis ){
        vis[row][col]=1;
        int m =grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(row,col));
        int delrow[]={1,0,-1,0};
        int delcol[]={0,-1,0,1};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int j=0;j<4;j++){
                int nrow=row+delrow[j];
                int ncol=col+delcol[j];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1') {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};