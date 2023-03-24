#include <iostream>
#include <vector>
using namespace std;
 class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int l = 0, r;
        r = l;
        int len = nums.size();
        if (len == 1)
        {
            return;
        }
        while (l < len && r < len)
        {
            if (nums[l] != 0 && nums[r] != 0)
            {
                l++;
                r++;
                continue;
            }
            if (nums[l] == 0)
            {
                l++;
            }
            else 
            {
                nums[r] = nums[l];
                nums[l] = 0;
                r++;
            }
        }
    }
};
int main()
{
    int a[3] = {1,1,0};
    vector<int>b(a, a + 3);
    Solution c;
    c.moveZeroes(b);
    cout << b[0]<<b[1]<<b[2];






}