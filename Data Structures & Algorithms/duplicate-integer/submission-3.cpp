class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int> seen;

        for(int x : nums){
            if(seen.count(x)){
                return true;
            }

            seen.insert(x);
        }
        return false;

        /* ----- O(n) solution - unordered_map -----
        unordered_map<int,int> uMap;
        
        for(int x : nums){
            uMap[x]++;
            if(uMap[x] > 1){
                return true;
            }
        }
        return false;
        */
        
        /* ----- learning attempt -----
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
        */


        /* ----- self approach -----
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