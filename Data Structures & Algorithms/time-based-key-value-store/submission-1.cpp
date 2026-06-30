/*
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()){
            return "";
        }
        
        vector<pair<int, string>>& values = store[key];

        int left = 0;
        int right = values.size() - 1;

        string answer = "";

        while(left <= right){
            int mid = left + (right - left)/2;

            int midValue = values[mid].first;
            string midString = values[mid].second;

            if(midValue <= timestamp){
                answer = midString;
                left = ++mid;
            }

            else{
                right = --mid;
            }
        }
        return answer;
    }
};
*/

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timeValueMap;

public:
    TimeMap() {
        
    }

    void set(string key, string value, int timestamp) {
        timeValueMap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(timeValueMap.find(key) == timeValueMap.end()){
            return "";
        }

        vector<pair<int, string>>& entry = timeValueMap[key];
        string result;

        int left = 0;
        int right = entry.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            int midTimestamp = entry[mid].first;
            string midValue = entry[mid].second;

            if(midTimestamp <= timestamp){
                result = midValue;
                left = ++mid;
            }

            else{
                right = --mid;
            }
        }
        return result;
    }
};
