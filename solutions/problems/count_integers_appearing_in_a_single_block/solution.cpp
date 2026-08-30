class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> blockCount;
        for(int i= 0; i< nums.size(); i++){
            if(i== 0 || nums[i] != nums[i-1]){
                blockCount[nums[i]]++;
            }
        }

        int ans= 0;
        for(auto i: blockCount){
            if(i.second == 1){//agar 1 hi block hai
                ans++;//special hai
            }
        }

        return ans;
    }
};