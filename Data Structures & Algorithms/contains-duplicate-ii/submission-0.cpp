class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {

            // If nums[i] is already in the current window,
            // its previous occurrence is within distance k.
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }

            // Add the current element to the set.
            seen.insert(nums[i]);

            // Keep at most k elements in the set.
            if (seen.size() > k) {
                seen.erase(nums[i - k]);
            }
        }

        return false;
    }
};