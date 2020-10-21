/**
 * 双指针法
 * 若两指针指向字符相等，则i，j同时加一；若不相等，则比较j及j-1，若此时相等，则视为长按
 */
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(j<typed.size()){
            if(name[i]==typed[j]){
                i++,j++;
            }
            else if(j>0 && typed[j]==typed[j-1]){
                j++;
            }
            else
                return false;
        }
        return i==name.size();
    }
};