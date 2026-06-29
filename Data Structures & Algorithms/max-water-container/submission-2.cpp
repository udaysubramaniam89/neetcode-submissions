class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maximumArea = 0;

        int left = 0, right = heights.size() - 1;
        while(left < right){
            int width = right - left;
            int usableHeight = min(heights[left], heights[right]);
            int currentArea = width * usableHeight;

            maximumArea = max(maximumArea, currentArea);
            if(heights[left] < heights[right]){
                ++left;
            }

            else if(heights[left] > heights[right]){
                --right;
            }

            else{
                ++left;
            }
        }
        return maximumArea;
    }
};
