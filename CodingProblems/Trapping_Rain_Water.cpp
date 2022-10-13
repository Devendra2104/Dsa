class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int water = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            if(h[i] < h[j]) i=j;
        }
        int top = 0;
        for(int j=0;j<i;j++){
            if(h[j] < top) water += top-h[j];
            else top = h[j];
        }
        top = 0;
        for(int j=n-1;j>i;j--){
            if(h[j] < top) water += top-h[j];
            else top = h[j];
        }
        return water;
    }
};