/*
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

    A land cell if grid[r][c] = 0, or
    A water cell containing grid[r][c] fish, if grid[r][c] > 0.

A fisher can start at any water cell (r, c) and can do the following operations any number of times:

    Catch all the fish at cell (r, c), or
    Move to any adjacent water cell.

Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
*/
class Solution {
public:
    int n, m, ans;
    vector<int>dir={-1, 0, 1, 0, -1};
    int dfs(int i, int j, vector<vector<int>>&grid){
        if(i<0 or i>=n or j<0 or j>=m or !grid[i][j]) return 0;
        int cur=grid[i][j];
        grid[i][j]=0;

        for(int k=0;k<4;k++){
            cur+=dfs(i+dir[k], j+dir[k+1], grid);
        }

        return cur;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size(), ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) ans=max(ans, dfs(i, j, grid));
            }
        }

        return ans;
    }
};
