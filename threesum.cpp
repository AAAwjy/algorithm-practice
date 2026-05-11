class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());   //排序
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                break;
            }// 优化：既然排过序，如果第一个数就大于0，后面加起来肯定也大于0。
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }// 去重：如果这个数和上一个一样，直接跳过，避免结果重复。
            unordered_set<int> set;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+2&&nums[j]==nums[j-1]&&nums[j-1]==nums[j-2]){
                    continue;
                }//j去重
                int c=-nums[i]-nums[j];
                if(set.find(c)!=set.end()){
                    result.push_back({nums[i],nums[j],c});
                    set.erase(c);//防止出现重复的nums[j]时 重复输出一个元组
                }
                else
                set.insert(nums[j]);
            }
        }
    return result;
    }
};



