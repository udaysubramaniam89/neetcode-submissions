class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0){
            return -1;
        }

        if(n == 1){
            return nums[0];
        }

        int excludeLast = newRob(nums, 0, n - 2);
        int excludeFirst = newRob(nums, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }

private:
    int newRob(vector<int>& nums, int start, int end){
        int rob1 = 0, rob2 = 0;
        int newMaxRob;
        
        for(int i = start; i <= end; i++){
            newMaxRob = max(rob2, nums[i] + rob1);
            rob1 = rob2;
            rob2 = newMaxRob;
        }
        return newMaxRob;
    }
};
