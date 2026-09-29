

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



vector<long long> Filler(string s);
vector <long long> FillerPos (string s);
long long  Lex (char a , long long ar[26]);
bool range(long long x, long long min, long long max);
long long Sum(string s, long long a[26]);
bool surrounded (string s, string i);

int main ()
{
  // part 1 : taking in the input and the array of prices
  string input, alphabet = "abcdefghijklmnopqrstuvwxyz";
  cin >> input;
  long long arr[26] ;
  for (int i=0; i<26; i++)
  {
    cin >> arr[i];
  }


  // special case
  bool AllQ = true;
  for (char u : input)
  {
    if (u != '?')
    {
      AllQ = false;
      break;
    }
  }
  if (AllQ)
  {
    input.replace(0,input.size(),input.size(),'a');
  }
  else
  {
    // part 1 : fill amountQ and posQ vectors

    vector <long long> amountQ = Filler(input);
    vector <long long> posQ = FillerPos(input);




    // part 2 : fill the NiceLetters vector

    int n = posQ.size();
    vector <char> NiceLetters;
    int v1=0, v2=0;
    char c1 , c2;
    bool suffix, tail;
    string sub;

    for (int i=0; i<n ; i++)
    {
      suffix = false;
      tail = false;

      sub = input.substr(posQ[i],amountQ[i]);

      if (posQ[i] == 0)
      {
        suffix = true;
      }
      else if ((input.size() - amountQ[i]) == posQ[i])
      {
        tail = true;
      } // deciding whether the substring is a tail or a suffix or not either

      if (suffix)
      {
        c1 = input[amountQ[i]];
        int vc1 = Lex(c1,arr);
        for (int j =0; j<26 ;j++)
        {
          bool Range = range(arr[j],vc1,vc1);
          if (Range)
          {
            NiceLetters.push_back(alphabet[j]);
            break;
          }
        }

      }
      else if (tail)
      {
        int z = input.size() - amountQ[i];
        c1 = input[z-1];
        int vc1 = Lex(c1,arr);
        for (int j =0; j<26 ;j++)
        {
          bool Range = range(arr[j],vc1,vc1);
          if (Range)
          {
            NiceLetters.push_back(alphabet[j]);
            break;
          }
        }


      }
      else
      {
        c1 = input[posQ[i]-1];
        c2 = input[posQ[i] + amountQ[i] ]; //d

        v1 = Lex(c1,arr);
        v2 = Lex(c2,arr);
        int m = min(v1,v2);
        int M = max(v1,v2);

        for (int j =0; j<26 ;j++)
        {
          bool Range = range(arr[j],m,M);
          if (Range)
          {
            NiceLetters.push_back(alphabet[j]);
            break;
          }
        }

      }







    }


    //part 3 : Replacing
    for (int i=0; i<n; i++)
    {
      input.replace(posQ[i],amountQ[i],amountQ[i],NiceLetters[i]);
    }









  }



  //part 4 : calculate the sum

  long long answer = Sum(input,arr);

  // part 5 : printing out

  cout << answer << endl << input << endl;




}



bool range(long long x, long long min, long long max)
{
  if ((x>=min) && (x<=max))
  {
    return true;
  }
  else
  {
    return false;
  }
};


vector<long long> Filler(string s)
{
  vector <long long> v;
  bool Question;
  int c =0;
  for (int i=0; i<s.size(); i++)
  {

    char u = s[i];
    if (u == '?')
    {
      Question = true;

    }
    else
    {
      Question = false;
    }

    if (Question)
    {
      c++;
      if (i == s.size()-1)
      {
        v.push_back(c);
      }
    }

    else
    {
      if (c>0)
      {
        v.push_back(c);
        c=0;
      }
      else
      {
        c =0;
      }
    }
  } // filling the amountQ vector

  return v;

};
vector <long long> FillerPos (string s)
{
  vector <long long> v; long long c=0;
  bool Question;
  for (int i=0; i<s.size(); i++)
  {
    char u = s[i];

    if (u == '?')
    {
      Question = true;
    }
    else
    {
      Question = false;
    }


    if (Question)
    {
      c++;
      if (c==1)
      {
        v.push_back(i);
      }
    }
    else
    {
      c=0;
    }


  }

  return v;
};
long long Lex (char a , long long ar[26])
{

  string alpha = "abcdefghijklmnopqrstuvwxyz";
  int pos = alpha.find(a);
  int x = ar[pos];
  return x;
};
long long Sum(string s, long long a[26])
{
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  vector <int> lexPos;
  for (int i=0; i<s.size(); i++)
  {

      auto pos = alphabet.find(s[i]);
      lexPos.push_back(pos);


  } // creating the lexPos vector


  long long tempSum=0, x=0;

  for (int i=0; i<lexPos.size()-1; i++)
  {
    tempSum = max(a[lexPos[i]],a[lexPos[i+1]]) - min(a[lexPos[i]],a[lexPos[i+1]]) ;
    x += tempSum;


  } // calculating the sum


  return x;

};
