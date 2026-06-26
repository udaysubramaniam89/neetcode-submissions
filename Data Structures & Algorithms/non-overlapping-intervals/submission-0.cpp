class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int result = 0;
        sort(intervals.begin(), intervals.end());

        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if(currentStart < prevEnd){
                result++;
                prevEnd = min(prevEnd, currentEnd);
            }

            else{
                prevEnd = currentEnd;
            }
        }
        return result;
    }
};
