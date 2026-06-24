class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> valueFreqMap;

        for(int number : nums){
            valueFreqMap[number]++;
        }

        priority_queue<pair<int, int>> heap;

        for(auto& [num, count] : valueFreqMap){
            heap.push({count, num});
        }

        vector<int> result;

        while(k > 0){
            result.push_back(heap.top().second);
            heap.pop();
            k--;
        }
        return result;

        /* ------ learning the solution ------
        unordered_map<int, int> valueFreqPairs;

        for(int number : nums){
            valueFreqPairs[number]++;
        }
        
        priority_queue<pair<int, int>> heap;
        int num, count;
        for(auto& [num, count] : valueFreqPairs){
            //int num = entry.first;
            //int count = entry.second;
            heap.push({count, num});
        }

        vector<int> result;
        while(k > 0){
            result.push_back(heap.top().second);
            heap.pop();
            k--;
        }
        return result;
        */
    }
};
