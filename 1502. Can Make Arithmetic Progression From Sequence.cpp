class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        int minValue = *std::min_element(arr.begin(), arr.end());
        int maxValue = *std::max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if ((maxValue - minValue) % (n - 1) != 0) {
            return false;
        }
        
        int diff = (maxValue - minValue) / (n - 1);
        int i = 0;
        
        while (i < n) {
            if (arr[i] == minValue + i * diff) {
                i += 1;
            } else if ((arr[i] - minValue) % diff != 0) {
                return false;
            } else {
                int j = (arr[i] - minValue) / diff;
              
                if (arr[i] == arr[j]) {
                    return false;
                }
              swap(arr[i], arr[j]);  // Swap arr[i] with arr[j]
            }
        }
        
        return true;
    }
};
