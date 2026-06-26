class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for(vector<int>& point : points){
            int x = point[0];
            int y = point[1];

            int dist = x*x + y*y;
            maxHeap.push({dist, point});

            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;

        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};

    /* ----- brute-force O(n logn) -----

        vector<vector<int>> result;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];

            return distA < distB;
        });

        for(int i = 0; i < k; i++){
            result.push_back(points[i]);
        }

        return result;
    }
};
*/
