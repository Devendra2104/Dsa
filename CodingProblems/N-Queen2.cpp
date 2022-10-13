class Solution {
public:
    int table[10][10];
    bool canPlace(int row, int col, int n){
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(row+i>=n or col+j>=n or row+i<0 or col+j<0) continue;
                if(table[row+i][col+j]) return false;
            }
        }
        for(int i=0;i<n;i++) if(table[row][i]) return false;
        for(int j=0;j<n;j++) if(table[j][col]) return false;
        int r=row; int c=col;
        while(r>=0 and c>=0){
            if(table[r][c]) return false;
            r--; c--;
        }
        r=row; c=col;
        while(c<n and r>=0){
            if(table[r][c]) return false;
            c++; r--;
        }
        r=row; c=col;
        while(r<n and c<n){
            if(table[r][c]) return false;
            r++; c++;
        }
        r=row; c=col;
        while(c>=0 and r<n){
            if(table[r][c]) return false;
            r++; c--;
        }
        return true;
    };
    int dfs(int row,int n){
        if(row == n) {
            return 1;
        };
        int ans = 0;
        for(int col=0;col<n;col++){
            if(canPlace(row,col,n)){
                table[row][col] = 1;
                ans += dfs(row+1,n);
                table[row][col] = 0;
            }
        }
        return ans;
    };
    int totalNQueens(int n) {
        memset(table,0,sizeof table);
        return dfs(0,n);
    }
};