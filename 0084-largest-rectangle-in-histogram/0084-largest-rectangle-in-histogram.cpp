class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector <int> left (n , 0) ;
        vector <int> right (n , 0) ;
        stack <int> s ;

        // for right boundary
        for (int i = n-1 ; i>=0 ; i--) {
            while (s.size()>0 && heights[s.top()]>=heights[i]) {
                s.pop() ;
            }
            if(s.empty()) {
                right[i] = n ;
            }
            else {
                right[i] = s.top() ;
            }
            s.push(i) ;
        }

        while(!s.empty()) {
            s.pop() ;
        }

        // for left boundary
        for (int i = 0 ; i<n ; i++) {
            while (s.size()>0 && heights[i]<=heights[s.top()]) {
                s.pop() ;
            }
            if(s.empty()) {
                left[i] = -1 ;
            }
            else {
                left[i] = s.top() ;
            }
            s.push(i) ;
        }
 
        int area = 0 ;
        for (int i=0 ; i<n ; i++) {
            int maxArea = heights[i] * (right[i] - left[i] - 1) ;
            area = max (area , maxArea) ;
        }
        return area ;
    }
};