//Leetcode 709: To Lower Case

class Solution {
    public String toLowerCase(String str) {
        String res = "";
        
        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            res += Character.isLetter(c) && (int)c <= 90 ? (char)((int)c + 32) : c;
        }
        
        return res;
    }
}
