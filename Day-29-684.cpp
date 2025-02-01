/*
684. Redundant Connection

Use Union-Find with Rank: Each node starts as its own parent (ds[i] = i), and a rank array helps in merging smaller trees under larger ones.
Detect Cycle: For each edge (a, b), find their parents using find_parent(). If they have the same parent, the edge forms a cycle and should be returned.
Union Operation: If no cycle is found, merge the sets using rank (attach the smaller tree to the larger one).
*/
class Solution {
public:
    int find_parent(int element, vector<int>&ds){
        if(ds[element]==element) return element;
        else return find_parent(ds[element], ds);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>ds(n+1), rank(n+1);
        
        for(int i=0;i<=n;i++) ds[i]=i, rank[i]=1;
        
        for(vector<int>v: edges){
            int element1=v[0], element2=v[1];
            int p1=find_parent(element1, ds);
            int p2=find_parent(element2, ds);

            if(p1==p2) return v;
            else{
                if(rank[p1]>rank[p2]) ds[p2]=p1;
                else if(rank[p2]>rank[p1]) ds[p1]=p2;
                else ds[p2]=p1, rank[p1]++;
            }
        }
        
        return {};
    }
};
