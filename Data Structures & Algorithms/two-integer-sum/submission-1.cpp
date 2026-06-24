class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];

            if(seen.find(needed) != seen.end()){
                return {seen[needed], i};
            }

            seen[nums[i]] = i;
        }
        return {};
        
        /* ----- brute-force -----
        vector<int> result;
        
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
        */
        
        /* ----- approach 1 -----
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];

            if(seen.find(needed) != seen.end()){
                return {seen[needed], i};
            }
            seen[nums[i]] = i;
        }
        return {};
        */
        
        /* ----- learning approach -----
        sort(nums.begin(), nums.end());

        vector<int> result(2, 0);

        int i = 0, j = nums.size() - 1;

        while(i < j){
            int start = nums[i], end = nums[j];

            if( (start + end) < target ){
                i++;
            }else if( (start + end) > target ){
                j--;
            }else{
                break;
            }
        }
        result = {i, j};
        return result;
        */
    }
};
