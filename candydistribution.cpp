#include <bits/stdc++.h>
using n
amespace std;
int solve(vector<int> A){
   int n, sum = 0, ans = 0;
   n = A.size();
   for (int i = 0; i < n; i++)
      sum += A[i];
   if (sum % n != 0)
      return -1;
   else{
      sum /= n;
      for (int i = 0; i < n; i++)
         if (A[i] > sum)
            ans++;
      return ans;
   }
}
int main(){
   vector<int> A = { 4, 5, 2, 5 };
   cout << solve(A) << endl;
}
