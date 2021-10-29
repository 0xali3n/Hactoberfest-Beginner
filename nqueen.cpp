#include<iostream>
#include<vector>

using namespace std;




bool isSafeToPlaceQueen(vector<vector<bool>> &boxes, int row, int col)
{
    vector<vector<int>> Qdir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    for (int d = 0; d < Qdir.size(); d++)
    {
        for (int rad = 1; rad <= boxes.size(); rad++)
        {
            int r = row + rad * Qdir[d][0];
            int c = col + rad * Qdir[d][1];

            if (r >= 0 && c >= 0 && r < boxes.size() && c < boxes.size())
            {
                if (boxes[r][c])
                    return false;
            }
            else
                break;
        }
    }

    return true;
}
 


int Nqueen_01(vector<vector<bool>> &boxes, int tnq, int idx, string ans)
{ //qpsf : queen place so far, tnq: total no of queen
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        if (isSafeToPlaceQueen(boxes, x, y))
        {
            boxes[x][y] = true;
            count += Nqueen_01(boxes, tnq - 1, i + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            boxes[x][y] = false;
        }
    }
    return count;
}

vector<bool> RowA;
vector<bool> ColA;
vector<bool> diag;
vector<bool> adiag;

int nqueen02(int n, int m,int tnq, int idx, string ans)
{
    if(tnq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<m*n;i++)
    {
       int x=i/m;
       int y=i%m;
      
      if(!RowA[x] && !ColA[y] && !diag[x-y+m-1] && !adiag[x+y])
      {
          RowA[x]=true;
          ColA[y]=true;
          diag[x-y+m-1]=true;
          adiag[x+y]=true;

          count+=nqueen02(n,m,tnq-1,i+1,ans+"(" + to_string(x) + ", " + to_string(y) + ") ");

          RowA[x]=false;
          ColA[y]=false;
          diag[x-y+m-1]=false;
          adiag[x+y]=false;
      }
    }

      return count;

    }
      
      int nqueen_rooms(int n,int m, int tnq, int r,string ans) //m is rooms, n is houses, r to shift to next row 
      {
          if(r==n || tnq==0)
          {
              if(tnq==0)
               {
                 cout<<ans<<endl;
                 return 1;
                }
              return 0;
          }
           int count=0;
           for(int i=0;i<m;i++)
           {
               int x=r;
               int y=i;

       if(!RowA[x] && !ColA[y] && !diag[x-y+m-1] && !adiag[x+y])
      {
          RowA[x]=true;
          ColA[y]=true;
          diag[x-y+m-1]=true;
          adiag[x+y]=true;

          count+=nqueen_rooms(n,m,tnq-1,r+1,ans+"(" + to_string(x) + ", " + to_string(y) + ") ");

          RowA[x]=false;
          ColA[y]=false;
          diag[x-y+m-1]=false;
          adiag[x+y]=false;
        }
               
           }
           return count;
      }

      int nqueen_subseq(int n,int m, int tnq, int r,string ans) //m is rooms, n is houses, r to shift to next row 
      {
          if(r==n || tnq==0)
          {
              if(tnq==0)
               {
                 cout<<ans<<endl;
                 return 1;
                }
              return 0;
          }
           int count=0;
    for(int i=0;i<m;i++)
    {
      int x=r;
      int y=i;

       if(!RowA[x] && !ColA[y] && !diag[x-y+m-1] && !adiag[x+y])
      {
          RowA[x]=true;
          ColA[y]=true;
          diag[x-y+m-1]=true;
          adiag[x+y]=true;

          count+=nqueen_rooms(n,m,tnq-1,r+1,ans+"(" + to_string(x) + ", " + to_string(y) + ") ");

          RowA[x]=false;
          ColA[y]=false;
          diag[x-y+m-1]=false;
          adiag[x+y]=false;
        }
               
     }

     count+=nqueen_rooms(n,m,tnq,r+1,ans);
           return count;
      }

int rowA_=0;
int colA_=0;
int diag_=0;
int adiag_=0;        
int nqueen_bits(int n,int m, int tq, int idx, string ans)
{
    if(tq==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<m*n;i++)
    {
      int x=i/m;
      int y=i%m;

      if(!(rowA_&(1<<x)) && !(colA_&(1<<y)) && !(diag_&(1<<(x-y+m-1))) && !(adiag_&(1<<(x+y))))
      {
          rowA_^=(1<<x);
          colA_^=(1<<y);
          diag_^=(1<<(x-y+m-1));
          adiag_^=(1<<(x+y));

          count+=nqueen_bits(n,m,tq-1,i+1,ans+"(" + to_string(x) + ", " + to_string(y) + ") ");
         
         rowA_^=(1<<x);
          colA_^=(1<<y);
          diag_^=(1<<(x-y+m-1));
          adiag_^=(1<<(x+y));

      }
    }
    return count;


}

int main()
{
   vector<vector<bool>> box(4,vector<bool>(4,false));
    int n=4;
    int m=4;
    RowA.resize(n, false);
    ColA.resize(m, false);
    diag.resize(n + m - 1, false);
    adiag.resize(n + m - 1, false);
    //cout<<Nqueen_01(box, 4,0,"");

   //  cout<<nqueen02(4,4,4,0,"");

  // cout<<nqueen_rooms(4,4,4,0,"");

  //cout<<nqueen_subseq(4,4,4,0,"");

  cout<<nqueen_bits(4,4,4,0,"");

     return 0;  
}