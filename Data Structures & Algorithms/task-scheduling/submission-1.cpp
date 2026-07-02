class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for(char task : tasks){
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        
        for(int freq : count){
            if(freq > 0){
                maxHeap.push(freq);
            }
        }

        queue<pair<int, int>> cooldown;
        int time = 0;

        while(!maxHeap.empty() || !cooldown.empty()){
            time++;
            if(!maxHeap.empty()){
                int freq = maxHeap.top();
                maxHeap.pop();
                freq--;

                if(freq > 0){
                    cooldown.push({freq, time + n});
                }
            }

            if(!cooldown.empty() && (time == cooldown.front().second)){
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};
