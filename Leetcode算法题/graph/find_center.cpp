//https://leetcode.com/problems/find-center-of-star-graph/

//Leetcode 1791: Find center of star graph      1/8/2021      time&space:O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};
