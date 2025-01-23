/*
1267. Count Servers that Communicate
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.
*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row[250]={0}, column[250]={0}, cnt=0;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) row[i]++, column[j]++, cnt++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and row[i]==1 and column[j]==1){
                    cnt--;
                }
            }
        }
        return cnt;
    }
};
