/**************************************
	双指针 
	对数组头尾用p0，p2两个指针
	由题目要求得，p0交换0，p2交换2
***************************************/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p0=0,p2=n-1;
        for(int i=0;i<n;i++){
		
			//对i指向2的情况，将其与p2交换，但是不排除i原本指向2的情况
			//若单纯交换一次之后，i指向下一位，则会使2被留在前面
			//所以持续交换，直到i不为2时
            while(p2>i && nums[i]==2){
                swap(nums[i],nums[p2]);
                p2--;
            }
			
			//若i指向0，则正常的与p0交换即可
            if(nums[i]==0){
                swap(nums[i],nums[p0]);
                p0++;
            }
        }
    }
};