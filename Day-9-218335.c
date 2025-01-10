class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        for(auto it:words1){
            vector<int>frq(26, 0);
            int f=0;
            for(auto ch:it) frq[ch-'a']++;
            for(auto iit:words2){
                for(auto cch:iit) frq[cch-'a']--;
                for(auto cnt:frq){
                    if(cnt<0) f=1;
                }
            }
            if(f==0) ans.push_back(it);
        }
        return ans;
    }
};
