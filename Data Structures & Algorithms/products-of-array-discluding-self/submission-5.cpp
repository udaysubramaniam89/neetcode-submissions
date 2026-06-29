class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int prefix = 1;
        for(int i = 0; i < n; i++){
            result[i] *= prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i = n - 1; i >= 0; i--){
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};














/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for(int i = 0; i < n; i++){
            int product = 1;
            for(int j = 0; j < n; j++){
                if(j == i){
                    continue;
                }
                product *= nums[j];
            }
            result.push_back(product);
        }
        return result;
    }
};
*/