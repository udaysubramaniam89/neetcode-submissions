class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        
        int left = 0;
        int right = heights.size() - 1;

        while(left < right){
            int usableHeight = min(heights[left], heights[right]);
            int width = right - left;

            int maxArea = usableHeight * width;
            result = max(result, maxArea);

            if(heights[left] <= heights[right]){
                left++;
            }

            else{
                right--;
            }
        }
        return result;
    }
};

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    int maxArea(vector<int>& heights) {
        int result = 0;

        int left = 0;
        int right = heights.size() - 1;

        while(left < right){
            int usableHeight = min(heights[left], heights[right]);
            int width = right - left;

            int area = width * usableHeight;
            result = max(result, area);

            if(heights[left] < heights[right]){
                left++;
            }
            else if(heights[left] > heights[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return result;
    }
};
*/
