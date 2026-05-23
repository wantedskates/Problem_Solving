// naive solution without Metadata (prefix counter array) 
#include <iostream>
using namespace std;
// padded
char arr[510][510];
void solve();
int calc( int i , int j , int kk , int rr , int cc);
int main()
{
  // T denotes test cases 
  int T ; cin >> T ;
  while (T--)
  {
    solve();
  }
}
void solve()
{

  int rows, cols , k;




    cin >> rows >> cols>> k;

    int allGold =0;
    // take in the data and calculate allGold on the fly
    for (int i =1; i<=rows; i++ )
    {
      for (int j=1; j<=cols; j++)
      {
        cin >> arr[i][j];
        if (arr[i][j] == 'g')

          allGold++;

      }
    }




    // discover the cell in which we have the most remaining collectable gold
    int lostGold =0 , remaining_collectable_gold = 0 , x = 0;
    int flag = 1;
    for (int i=1; i<=rows; i++)
    {
      for (int j=1; j<=cols; j++)
      {
        if (arr[i][j] != '.')
        {
          continue;
        }

        lostGold = calc(i,j,k, rows, cols);
        
        // special case
        if (lostGold == 0)
        {
          x = allGold;
          flag = 0;
          break;
        }

        remaining_collectable_gold = allGold - lostGold;
        if (x < remaining_collectable_gold)
        {
          x = remaining_collectable_gold;
        }







      }
      if (flag == 0)
      {
        break;
      }







    }

    cout <<  x << "\n";
  }





int calc( int i , int j , int kk , int rr, int cc)
{




  int goldLost = 0;
  if (kk==1)
  {
    return goldLost;
  }
  else
  {
    int d = 2*kk - 1;

    int b = kk-1;

    int I = i + (-1 * b);
    int J = j + (-1 *b);

    // handle negative values
    if (I <0)
    {
      I = 0;
    }
    if (J<0)
    {
      J=0;
    }
    int old = J;

    for (int ii =0; ii<d; ii++, I++ , J = old)
    {
      for (int jj =0; jj<d; jj++ , J++)
      {
        if (I>rr || J> cc)
          continue; 

        if (arr[I][J] == 'g')
        {
          goldLost++;
        }
      }

    }

    return goldLost;
  }


};
