#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Using hash map:
class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hMap;
        
        for (int num : nums) {
            if (hMap.find(num) != hMap.end()) {
                return true;
            }
            hMap.insert(num);
        }

        return false;
    }
};


/* Using sorting algorithms :
class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }

        return false;
    }
};
*/

int main() {
    vector<int> input = { 1, 2, 3, 2 };
    bool output = Solution::containsDuplicate(input);
    cout << "Output: " << (output ? "true" : "false") << endl;
	return 0;
}
