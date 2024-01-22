class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat;
        vector<int> answer;
        sort(nums.begin(),nums.end());
        int total =nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                repeat = nums[i];
                nums[i] = 0;
            }
            total+=nums[i];
          
        }
        int shouldBe = n*(n+1)/2;
        int missing = shouldBe - total;
        answer.push_back(repeat);
        answer.push_back(missing);
        return answer;
    }
};
