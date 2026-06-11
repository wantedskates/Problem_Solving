// elegant solution using Metadata
// proved in codeforces 
#include <iostream>
#include <vector>
using namespace std;
void solve();
int main()
{
  int t; cin >> t;
  while (t--)
  {
    solve();
  }


}
void solve()
{

  int r , c , k ;
  cin >> r >> c  >> k;

  char input[r][c];
  for (int i=0; i<r; i++)
  {
    for (int j=0; j<c ; j++)
    {
      cin >> input[i][j];
    }
  }

 
  
  // creating cou first fully padded andthe purpose of creating the vector of metadata padded is to not deal with boundary cases 
  //because writing code for such cases
  // is highly error-prone 

  
  vector <vector <int>> cou(r+k,vector<int> (c+k,0));
  // add k zeros for each inner vector
  for (int i=0; i<cou.size(); i++)
  {
    cou[i].insert(cou[i].end(),k,0);
  }
  // add k vectors of zeros to cou
  vector <int> zeros (cou[0].size(),0);

  cou.insert(cou.end(),k,zeros);





  // filling the data of cou
  for (int i=k  ; i<cou.size(); i++ )
  {
    for (int j=k ; j<cou[0].size(); j++ )
    {
      if (i-k<r && j-k<c)
      {
        if (input[i-k][j-k] == 'g')
        {
          cou [i][j]++;
        }
      }

      cou[i][j] += cou[i-1][j] + cou[i][j-1] - cou[i-1][j-1];
    }
  }


  // G : all gold 
  int G = cou[cou.size() -1][cou[0].size()-1];

  


  










 //getting the answer
  int ans=0;
  for (int i=0; i<r; i++)
  {
    for (int j=0; j<c; j++)
    {
      if (input[i][j] != '.')
      {
        continue;
      }

      int I = i+k , J  = j+k;


      int t = cou[(I+k-1)][(J+k-1)];

      int x = cou[ I-k ][ J-k];
      int y = cou[ I-k][ (J+k-1)];
      int z = cou[ (I+k-1)] [  J-k];


      int l = t - y - z + x;




      ans = max(ans,(G-l));













    }
  }



  cout << ans << "\n";

};
