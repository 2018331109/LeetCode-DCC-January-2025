/*
2948. Make Lexicographically Smallest Array by Swapping Elements


You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.
*/
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>>index;

        for(int i=0;i<nums.size();i++){
            index.push_back({nums[i], i});
        }

        sort(index.begin(), index.end());
        vector<vector<int>>groups={{index[0].second}};

        for(int i=1;i<nums.size();i++){
            if(index[i].first-index[i-1].first<=limit){
                groups.back().push_back(index[i].second);
            }
            else{
                groups.push_back({index[i].second});
            }
        }

        for(auto& group:groups){
            vector<int>val;
            for(int it:group) val.push_back(nums[it]);
            sort(val.begin(), val.end());
            sort(group.begin(), group.end());

            for(int i=0;i<group.size();i++){
                nums[group[i]]=val[i];
            }
        }

        return nums;
    }
};
