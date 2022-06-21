#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    static int maxArea(vector<int>& height) {
        int maxArea = 0;
        int l_ptr = 0, r_ptr = height.size() - 1;

        //two pointer approach
        int l, r, width, lMin;
        while (l_ptr < r_ptr) {
            l = height[l_ptr];
            r = height[r_ptr];
            width = r_ptr - l_ptr;

            lMin = min(l, r);
            maxArea = max(maxArea, lMin * width);
            
            l < r ? l_ptr++ : r_ptr--;
        }
        return maxArea;
    }
};


#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int l_ptr = 0, r_ptr = heightSize - 1;

    while (l_ptr < r_ptr) {
        if (height[l_ptr] < height[r_ptr]) {
            maxArea = MAX(maxArea, height[l_ptr] * (r_ptr - l_ptr));
            l_ptr++;
        }
        else {
            maxArea = MAX(maxArea, height[r_ptr] * (r_ptr - l_ptr));
            r_ptr--;
        }
    }

    return maxArea;
}


int main() {
    int height[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    printf("%d", maxArea(height, sizeof(height)/ sizeof(int)));

    /*
    vector<int> height { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int additionalInput;
    std::cin >> additionalInput;
    height.push_back(additionalInput);

    int output = Solution::maxArea(height);
    std::cout << "Output: " << output << std::endl;
	*/
    return 0;
}
