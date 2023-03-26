class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> bag;
        for (int i = 0; i < numOnes; i++) {
            bag.push_back(1);
        }
        for (int i = 0; i < numZeros; i++) {
            bag.push_back(0);
        }
        for (int i = 0; i < numNegOnes; i++) {
            bag.push_back(-1);
        }
        sort(bag.begin(), bag.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += bag[i];
        }
        return sum;
    }
};
