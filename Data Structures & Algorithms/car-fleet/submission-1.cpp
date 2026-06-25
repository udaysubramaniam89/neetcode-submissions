class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;

        for(int i = 0; i < position.size(); i++){
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });

        int fleets = 0;
        double fleetTime = 0.0;

        for(int j = 0; j < cars.size(); j++){
            double currentTime = cars[j].second;
            
            if(currentTime > fleetTime){
                fleets++;
                fleetTime = currentTime;
            }
        }
        return fleets;
    }
};
