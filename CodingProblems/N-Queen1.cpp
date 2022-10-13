class Solution {
public:
    int table[10][10];
    vector<vector<string>> V;
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
    void dfs(int row,int n){
        if(row == n) {
            vector<string> cur;
            for(int i=0;i<n;i++){
                string x(n,'.');
                for(int j=0;j<n;j++){
                    if(table[i][j]) x[j] = 'Q';
                }
                cur.push_back(x);
            }
            V.push_back(cur);
            return;
        };
        for(int col=0;col<n;col++){
            if(canPlace(row,col,n)){
                table[row][col] = 1;
                dfs(row+1,n);
                table[row][col] = 0;
            }
        }
    };
    vector<vector<string>> solveNQueens(int n) {
        memset(table,0,sizeof table);
        dfs(0,n);
        return V;
    }
};