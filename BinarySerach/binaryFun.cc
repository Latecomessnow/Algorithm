class Solution {
public:
    int leftBorder(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left ) / 2;
            // 左边界
            // 找到target且mid为第一次等于target的下标
            if ((mid == left && nums[mid] == target)
            || (nums[mid] == target && nums[mid - 1] < target))
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        // 数组中不存在target
        return -1;
    }

    int rightBorder(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 右边界
            if ((mid == right && nums[mid] == target)
            || (nums[mid] == target && nums[mid + 1] > target))
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(leftBorder(nums, target));
        v.push_back(rightBorder(nums, target));
        return v;
    }
};
