#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool compareString(string L, string N)
{
  // O(n + m)
  // Space O(m)
  unordered_set<char> n_char;
  for (int j = 0; j < N.size(); j++)
  {
    n_char.insert(N[j]);
  }

  for (int i = 0; i < L.size(); i++)
  {
    unordered_set<char>::iterator itr = n_char.find(L[i]);
    if(itr == n_char.end())
      return false;
  }
  return true;

}

int main()
{
  string L = "i love u", N = "World is a lovely place. u";
  cout<<compareString(L,N);
  return 0;
}
