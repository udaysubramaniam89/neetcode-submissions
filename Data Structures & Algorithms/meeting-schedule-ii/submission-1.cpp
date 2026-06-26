/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        if(intervals.size() == 0){
            return 0;
        }

        int result;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0; i < intervals.size(); i++){
            int currentStart = intervals[i].start;
            int currentEnd = intervals[i].end;

            if(!minHeap.empty() && (minHeap.top() <= currentStart)){
                minHeap.pop();
            }

            minHeap.push(currentEnd);
        }
        return minHeap.size();
    }
};
