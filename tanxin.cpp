#若干贪心题目
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sum=1;
        int flag=0;
        for(int i=1;i<nums.size();i++){
            if((flag==0||flag==-1)&&nums[i] > nums[i - 1]){
                sum++;
                flag=1;
            }
            else if((flag==0||flag==1)&&nums[i] < nums[i - 1]){
                sum++;
                flag=-1;
            }
        }
    return sum;
    }
};




class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0; // 记录当前能够走到的最远位置
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // 如果当前位置 i 已经超过了之前能达到的最远距离，说明前面卡住了，根本走不到这里
            if (i > max_reach) {
                return false;
            }

            // 在当前位置，计算从这里起跳能达到的新最远位置，并与之前的最远位置取最大值
            max_reach = max(max_reach, i + nums[i]);

            // 如果最远距离已经能覆盖或者超过最后一个位置了，直接成功！
            if (max_reach >= n - 1) {
                return true;
            }
        }

        return false;
    }
};
