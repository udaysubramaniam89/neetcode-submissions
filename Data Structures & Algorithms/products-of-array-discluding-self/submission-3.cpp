class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /* ----- prefix suffix approach ----- */
        int n = nums.size();

        vector<int> result(n, 1);

        int prefix = 1;

        for(int i = 0; i < nums.size(); i++){
            result[i] *= prefix;
            prefix *= nums[i];
        }

        int suffix = 1;

        for(int i = n-1; i >= 0; i--){
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
        
        /* ----- brute force -----
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int product = 1;
            for(int j = 0; j < nums.size(); j++){
                if(j == i){
                    continue;
                }
                product *= nums[j];
            }
            result.push_back(product);
        }
        return result;
        */
        
        /* ---------- learning ----------
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++){
            int product = 1;
            for(int j = 0; j < nums.size(); j++){
                if(j == i){
                    continue;
                }
                product *= nums[j];
            }
            result.push_back(product);
        }
        return result;
        */
    }
};
