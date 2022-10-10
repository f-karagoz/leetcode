#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    bool isBadVersion(int version)
    {
        // defined by the leetcode, not public
        // the local project does not function correctly
    }
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (isBadVersion(mid))
            {
                if (!isBadVersion(mid - 1))
                    return mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return -1;
    }
};

Solution sol;

int main(void)
{
    return 0;
}