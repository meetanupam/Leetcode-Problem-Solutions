class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        // Push all stones into the max heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        // Smash stones until there is only 0 or 1 stone left
        while (maxHeap.size() > 1) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if (x != y) {
                maxHeap.push(y - x);
            }
        }

        // Return the remaining stone's weight, or 0 if there are none left
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
