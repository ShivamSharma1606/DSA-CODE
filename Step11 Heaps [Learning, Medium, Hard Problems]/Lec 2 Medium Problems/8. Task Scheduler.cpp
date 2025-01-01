//todo: Priority queue approach



//* Greedy Approach

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mpp;

        // mapping of the character and frequency
        for (auto it : tasks) {
            mpp[it]++;
        }

        // finding the maxfrequent element
        int max_freq = 0;
        for (auto [x, y] : mpp) {
            max_freq = max(max_freq, y);
        }

        // finding the count of max_frequent element
        int count = 0;
        for (auto [x, y] : mpp) {
            if (y == max_freq) {
                count++;
            }
        }

        // how i drive this formula please check this image
        int slot = (max_freq - 1) * (n + 1) + count;
        int maxSlot = max(slot, (int)tasks.size());

        return maxSlot;
    }
};