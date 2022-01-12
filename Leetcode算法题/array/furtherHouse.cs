//2078. Two Furthest Houses With Different Colors

public class Solution {
    public int MaxDistance(int[] colors) {
        
        int max = 1;
        Dictionary<int, int> color_index = new Dictionary<int, int>();
        
        for(int i = 0; i < colors.Length; i++){      
            if(!color_index.ContainsKey(colors[i])){
                color_index.Add(colors[i], i);
            }
            
            compareDistance(ref max, color_index, colors[i], i);
        }
        
        
        return max;
    }
    
    public void compareDistance(ref int max, Dictionary<int, int> color_index, int currentColor, int currentIndex){
        int tempMax = 0;
        
        foreach(KeyValuePair<int, int> entry in color_index){
            if(entry.Key != currentColor){
                int distance = currentIndex - entry.Value;
                tempMax = distance > tempMax ? distance : tempMax; 
            }
        }
        
        max = tempMax > max ? tempMax : max;
    }
}
