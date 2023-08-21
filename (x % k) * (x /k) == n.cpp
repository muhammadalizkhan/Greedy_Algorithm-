#include<iostream>
using namespace std;
int minValue(int x, int y){
   return (x > y)?y:x;
}
int getX(int n, int k) {
   int x = INT_MAX;
   for (int rem = k - 1; rem > 0; rem--) {
      if (n % rem == 0)
         x = minValue(x, rem + (n / rem) * k);
   }
   return x;
}
int main() {
   int n = 4, k = 6;
   cout << "The minimum value of x: " << getX(n, k);
}
