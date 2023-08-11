class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy(m + 1);
        for (int i = 0; i < m; i++)
        {
            nums1_copy[i] = nums1[i];
        }
        nums1_copy[m] = INT_MAX;
        nums2.push_back(INT_MAX);
        int N = n + m;
        int ptr1 = 0, ptr2 = 0;
        for (int i = 0; i < N; i++)
        {
            if(nums1_copy[ptr1] < nums2[ptr2])
            {
                nums1[i] = nums1_copy[ptr1];
                ptr1++;
            }
            else
            {
                nums1[i] = nums2[ptr2];
                ptr2++;
            }
        }
    }
};