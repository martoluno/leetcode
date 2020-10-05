class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> q;
        if (nums.size() < 4) {
            return q;
        }
        sort(nums.begin(), nums.end());  //����������С��������
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;   //i����һ������ȣ���������
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;  //i����С����֮�ʹ���Ŀ�꣬˵���������ü������ԣ��˳�ѭ��
            }
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;  //i���������֮��С��Ŀ�꣬��������
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue; //j����һ������ȣ���������
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;  //ȷ��i��j֮��i��j����С����֮�����Ŀ�꣬�˳�ѭ��
                }
                if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;   //ȷ��i��j֮��i��j���������֮��С��Ŀ�꣬��������
                }
                int left = j + 1, right = length - 1;    //ȷ��������֮�󣬶�ʣ��ռ����������
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        q.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;     //������ͬ�������
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;    //������ͬ���Ҷ���
                    }
                    else if (sum < target) {
                        left++;     //��С��Ŀ�꣬����ƶ�
                    }
                    else {
                        right--;    //�ʹ���Ŀ�꣬�Ҷ��ƶ�
                    }
                }
            }
        }
        return q;
    }

};