#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (const auto& g : guards) {
            grid[g[0]][g[1]] = 2; 
        }
        for (const auto& w : walls) {
            grid[w[0]][w[1]] = -1; 
        }
        
        for (const auto& g : guards) {
            int x = g[0], y = g[1];
            
            // North
            for (int i = x - 1; i >= 0; i--) {
                if (grid[i][y] == -1 || grid[i][y] == 2) break;
                grid[i][y] = 1;
            }
            
            // South
            for (int i = x + 1; i < m; i++) {
                if (grid[i][y] == -1 || grid[i][y] == 2) break;
                grid[i][y] = 1;
            }
            
            // West
            for (int j = y - 1; j >= 0; j--) {
                if (grid[x][j] == -1 || grid[x][j] == 2) break;
                grid[x][j] = 1;
            }
            
            // East
            for (int j = y + 1; j < n; j++) {
                if (grid[x][j] == -1 || grid[x][j] == 2) break;
                grid[x][j] = 1;
            }
        }
        
        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unguarded++;
                }
            }
        }
        
        return unguarded;
    }
};
