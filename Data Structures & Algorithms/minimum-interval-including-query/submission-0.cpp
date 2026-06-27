class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> sortedQueries;

        for(int i = 0; i < queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> answer(queries.size(), -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int i = 0;

        for(auto& [query, originalIndex] : sortedQueries){
            while(i < intervals.size() && (intervals[i][0] <= query)){
                int left = intervals[i][0];
                int right = intervals[i][1];
                int length = right - left + 1;

                minHeap.push({length, right});
                i++;
            }

            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }

            if(!minHeap.empty()){
                answer[originalIndex] = minHeap.top().first;
            }
        }
        return answer;
    }
};
