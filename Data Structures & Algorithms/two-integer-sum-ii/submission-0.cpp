class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result = {};
        unordered_map<int, int> numMap;

        int needed;
        for(int i = 0; i < numbers.size(); i++){
            needed = target - numbers[i];

            if(numMap.find(needed) != numMap.end()){
                int index = numMap[needed];
                return {index + 1, i + 1}; 
            }

            numMap[numbers[i]] = i;
        }
        return result;   
    }
};
