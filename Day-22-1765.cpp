/*
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

    If isWater[i][j] == 0, cell (i, j) is a land cell.
    If isWater[i][j] == 1, cell (i, j) is a water cell.

You must assign each cell a height in a way that follows these rules:

    The height of each cell must be non-negative.
    If the cell is a water cell, its height must be 0.
    Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.*/
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(), m=isWater[0].size();
        vector<vector<int>>height(n, vector<int>(m, -1));
        queue<P>q;
        vector<int>X={0, 1, 0, -1}, Y={1, 0, -1, 0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0, q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [r, c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+X[i], nc=c+Y[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and height[nr][nc]==-1){
                    height[nr][nc]=height[r][c]+1;
                    q.push({nr, nc});
                }
            }
        }
        
        return height;
    }
};
