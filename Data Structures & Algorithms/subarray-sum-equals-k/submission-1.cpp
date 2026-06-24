class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> seen;

        seen[0] = 1;

        int sum = 0; 
        int result = 0;

        for(int x : nums){
            sum += x;
            int needed = sum - k;

            if(seen.count(needed)){
                result += seen[needed];
            }

            seen[sum]++;
        }
        return result;

        /*
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if(sum == k){
                    result++;
                }
            }
        }
        return result;
        */
    }
};