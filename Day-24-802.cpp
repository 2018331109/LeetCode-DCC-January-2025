/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/
class Solution {
public:
    vector<bool>safe;

    bool checkSafe(vector<vector<int>>&graph, vector<int>&vis, int cur){
        vis[cur]=1;
        bool isSafe=true;

        for(int nbr:graph[cur]){
            if(vis[nbr]==0) isSafe&=checkSafe(graph, vis, nbr);
            else if(vis[nbr]==1) return safe[cur]=false;
            else isSafe&=safe[nbr];
        }

        vis[cur]=2;
        return safe[cur]=isSafe;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        safe=vector<bool>(n, true);
        vector<int>vis(n, 0), ans;

        for(int i=0;i<n;i++){
            if(vis[i]==0) checkSafe(graph, vis, i);
        }

        for(int i=0;i<n;i++){
            if(safe[i]==true) ans.push_back(i);
        }

        return ans;
    }
};
