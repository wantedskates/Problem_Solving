// Brute force method

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define space " " ;
#define newline "\n"
vector <int> make_collatz(int a);
bool exist(vector <int> v , int a);
int count(vector <int> v, int a);
int answer(vector <vector <int>> v);
bool all_same(vector <int> v);
int main()
{
int tt ; cin >> tt;
 while (tt--){
  int n; cin >> n;


  vector <vector <int >> collatzes ;
  vector <int> input;

  int y , count0 = 0;

// On
  for (int i=0; i<n; i++)
  {
    cin >> y;
    input.push_back(y);
    // check whether the special case in which all the input is zero and if so handle that
    if (input[i] == 0)
    {
      count0++;
    }
  }


 

 if (count0 == n)
 {
  cout << 0;

 }
  else
{



//  O (n.log a)
  //generating collatzes
  for (int i=0; i<n; i++)
  {


    //special case
    if (input[i] == 0)
    {
      continue;
    }
    // O (log a)
    collatzes.push_back(make_collatz(input[i]));

  }






int ans = answer(collatzes);

bool all_ssame = all_same(input); 

if ( !(all_ssame) && (ans == 0 )){
    // it is the case of the tail of 1s and 2s (i wonder whether there are other cases in which answer
    /* is zero and it is not all_same nor the tail of 1s and 2s 
    * this code is based upon the assumption that when the answer is 0 and not all same then 
    * the tails are 1s and 2s definetily 
    */ 
    int count1 =0 , count2 = 0; 
    for (int i =0; i<collatzes.size() ; i++){
        
        if (collatzes[i][collatzes[i].size()-1] == 1){
            count1++; 
        }
        else if (collatzes[i][collatzes[i].size()-1] == 2){
            count2++; 
        }
    }
    
    
    if (count1 > count2){
        
        for (int k=0; k<collatzes.size(); k++){
            if (collatzes[k][collatzes[k].size()-1] ==2){
                collatzes[k].push_back(1); 
            }
        }
    }
    else if (count2 > count1){
        
        for (int k=0; k<collatzes.size(); k++){
            if (collatzes[k][collatzes[k].size()-1] == 1){
                collatzes[k].push_back(2); 
            }
            
        }
    }
    else if (count1 == count2){
        for (int k=0; k<collatzes.size(); k++){
            
        
        if (collatzes[k][collatzes[k].size()-1] ==2){
                collatzes[k].push_back(1); 
            }
            
        }
        }
        
        
        
        ans = answer(collatzes); 
     cout << ans << newline; 
    }
    
     
    
    
    
    
    
    
    
    else {
        cout << ans << newline; 
    }
    
   
    
    
    
    
    
    
    
}


  


}

}











bool all_same(vector <int> v){
    
    bool x = true; 
    for (int i =0; i<v.size()-1; i++){
        if (v[i] != v[i+1]){
            x = false; 
            break; 
        }
    }
    
    return x; 
    
    
};

int answer(vector <vector <int>> v){
    
    int  s = v.size();


   vector <int> smallest = *min_element(v.begin() , v.end());




  int ans =0;

  bool flag = 1;
  for (int i=0; i<smallest.size(); i++)
  {


    int t = 0;
    for (int j=0; j<s; j++)
    {



      bool e = exist(v[j],smallest[i]);
      if (e == false)
      {
        break;
      }
      else
      {
        t++;
      }
      if (t== s)
      {
        flag =0;
        for (int k=0; k<s; k++)
        {

          ans += count(v[k],smallest[i]);
        }


        break;
      }

    }

    if (flag == 0)
    {
      break;
    }

  }


return ans; 
    
    
    
};

int count(vector <int> v, int a)
{
  int x =0;
  for (int i : v)
  {

    if (i == a)
    {
      break;
    }
    x++;
  }

  return x;
};
vector <int> make_collatz(int a)
{

  vector <int> v;
  v.push_back(a);
  while(a!=1 && a!=2)
  {
    if (a%2 ==0)
    {
      a/=2;



    }
    else
    {
      a++;
    }

    v.push_back(a);
  }

  return v;


};
bool exist(vector <int> v , int a)
{
  bool x =0;
  for (int i : v)
  {
    if (i == a)
    {
      x = 1;
      break;
    }
  }

  return x;
};
