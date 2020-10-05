class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> q;
        if (nums.size() < 4) {
            return q;
        }
        sort(nums.begin(), nums.end());  //排序后数组从小到大有序
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;   //i与上一个数相等，跳过该数
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;  //i及最小三个之和大于目标，说明后续不用继续测试，退出循环
            }
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;  //i及最大三个之和小于目标，跳过该数
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue; //j与上一个数相等，跳过该数
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;  //确定i与j之后，i、j与最小两数之后大于目标，退出循环
                }
                if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;   //确定i与j之后，i、j与最大两数之和小于目标，跳过该数
                }
                int left = j + 1, right = length - 1;    //确定两个数之后，对剩余空间从两端收缩
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        q.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;     //跳过相同的左端数
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;    //跳过相同的右端数
                    }
                    else if (sum < target) {
                        left++;     //和小于目标，左端移动
                    }
                    else {
                        right--;    //和大于目标，右端移动
                    }
                }
            }
        }
        return q;
    }

};