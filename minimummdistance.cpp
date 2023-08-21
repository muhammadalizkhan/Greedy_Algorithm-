
#include <bits/stdc++.h>
using namespace std;
bool canGenerateResult(int mid, int arr[], int n, int k) {
   int pos = arr[0];
   int elements = 1;
   for (int i=1; i<n; i++){
      if (arr[i] - pos >= mid){
         pos = arr[i];
         elements++;
         if (elements == k)
         return true;
      }
   }
   return 0;
}
int maxMinDist(int arr[], int n, int k) {
   sort(arr,arr+n);
   int res = -1;
   int left = arr[0], right = arr[n-1];
   while (left < right){
      int mid = (left + right)/2;
      if (canGenerateResult(mid, arr, n, k)){
         res = max(res, mid);
         left = mid + 1;
      }
      else
         right = mid;
   }
   return res;
}
int main() {
   int arr[] = {3, 5, 6, 9, 1, 8};
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 3;
   cout<<"The maximized minimum distance is : "<<maxMinDist(arr, n, k);
   return 0;
}
