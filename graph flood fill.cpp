class Solution {
    private:
    void DFS(int row,int col,vector<vector<int>> &ans,
     vector<vector<int>> &image,int newcolor,int delrow[],int delcol[],
     int inicolor)
     {
      ans[row][col]=newcolor;int n=image.size();
      int m=image[0].size();
      for(int i=0;i<4;i++){
          int nrow=row+delrow[i];
          int ncol=col+delcol[i];
          if(nrow>=0 &&ncol>=0 &&ncol<m &&nrow<n
          &&image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor){
              DFS(nrow,ncol,ans,image,newcolor,delrow,delcol,inicolor);
          }
      }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {//----------color hi newcolor   hn----------------
        int inicolor=image[sr][sc];
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> ans=image;
        DFS(sr,sc,ans,image,color,delrow,delcol,inicolor);
        return ans;
    }
};