#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 > N2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = 2 * N1;
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = N1 + N2 - mid1;

            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1-1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2-1) / 2];
            double R1 = mid1 == 2 * N1 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == 2 * N2 ? INT_MAX : nums2[mid2 / 2];

            if (L1 > R2) high = mid1 - 1;
            else if (L2 > R1) low = mid1 + 1;
            else return (max(L1, L2) + min(R1, R2)) * 0.5;
        }

        return -1;
    }
};