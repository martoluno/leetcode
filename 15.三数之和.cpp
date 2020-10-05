class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> q;
        sort(nums.begin(),nums.end());
        int length=nums.size();
        for(int i=0;i<length-2;i++){
			//如果i与上一个数相等，则跳过（去重
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
			
			//如果i与最小两数之和大于零，则数组内不存在可以等于零的三数，退出
            if(nums[i]+nums[i+1]+nums[i+2]>0){
                break;
            }
			
			//如果i与最大两数之和小于零，则i与数组内剩余数之和不可能等于零，跳过该数
            if(nums[i]+nums[length-2]+nums[length-1]<0){
                continue;
            }
			
			//剪枝过后，对剩余数从两端开始，找到和为零的两数
            int left=i+1,right=length-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    q.push_back({nums[i],nums[left],nums[right]});
					
					//左端去重
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    left++;
					
					//右端去重
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    right--;
                }
                else if(sum>0){
                    right--;	//和若大于零，去掉最大的
                }
                else{
                    left++;		//和若小于零，去掉最小的
                }
            }
        }
        return q;
    }
};