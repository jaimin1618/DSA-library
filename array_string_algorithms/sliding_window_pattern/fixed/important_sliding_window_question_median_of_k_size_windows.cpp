class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2); // pointer pointing to mid of set
        vector<double> medians;
        int i = 0, j = k, n = nums.size();

        while(j <= n) {
            if(k % 2 != 0)
                medians.push_back((double) *mid);
            else
                medians.push_back(((double) *mid + (double) *prev(mid)) / 2);
            
            if(j == n) {
                // just calculate median and break 
                break;
            }
                

            // this is for incrementing j
            window.insert(nums[j]);
            if(nums[j] < *mid)
                mid--;
            
            if(nums[i] <= *mid)
                mid++;
            
            // now increment i
            window.erase(window.find(nums[i])); // 
            
            ++i;
            ++j;
        }

        return medians;
    }
};