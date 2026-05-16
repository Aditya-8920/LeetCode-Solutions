class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans(nums.size());
        int s= 0;
        int e= nums.size()-1;

        for(int i= 0; i< nums.size(); i++){
            if(nums[i] == 0){
                ans[s]= nums[i];
                s++;
            }
            else if(nums[i]== 2){
                ans[e]= nums[i];
                e--;
            }
        }
        for(int i= s; i<=e; i++){//0's daalne ke baad ans ko increment kiya tha and 2's daalne ke baad 2's ko decrement kiya tha -> that's why including s and e kyuki unme 1 hi aana chahiye
            ans[i] = 1;
        }
        nums= ans;
    }
};