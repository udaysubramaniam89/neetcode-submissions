class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int largest = INT_MIN, largestFreq = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        
        //vector<int> uniqueVals(n-1, 0);
        for(int i=1; i<=n-1; i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
        /*
        for( int i = 0; i < n; i++){
            largest = max(largest, nums[i]);
        }

        vector<int> freq(largest+1, 0);

        for( int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            largestFreq = max(largestFreq, freq[nums[i]]);
            if(largestFreq > 1){
                return true;
            }
        }
        return false;
        */
    }
};