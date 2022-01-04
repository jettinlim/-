//75. Sort Colors 
//https://leetcode.com/problems/sort-colors/

public class Solution {
    public void SortColors(int[] nums) {
        
        int red = nums.Count(n => n==0);
        int white = nums.Count(n => n==1);
        int blue = nums.Count(n => n==2);
        
        for(int i = 0; i < red + white + blue; i++){
            if(i < red){
                nums[i] = 0;
            }
            else if(i < red + white){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }
        }
    }
}
