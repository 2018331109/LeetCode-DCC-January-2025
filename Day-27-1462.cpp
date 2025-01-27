/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

*/
class Solution {
public:
    const int N=1000;
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>dist(n, vector<int>(n, N));
        unordered_map<int, vector<int>>adj;
        vector<bool>ans;

        for(int i=0;i<n;i++) dist[i][i]=0;
         
        for(auto edge:prerequisites){
            adj[edge[0]].push_back(edge[1]);
            dist[edge[0]][edge[1]]=1;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        for(auto q:queries){
            if(dist[q[0]][q[1]]<N) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};
