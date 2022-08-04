#include <bits/stdc++.h>
#define ll long long
class Solution {
public:
    int mirrorReflection(int p, int q) {
          ll hits_length = (p*q)/__gcd(p,q);
          ll no_of_times_hit = hits_length/q;
          if(no_of_times_hit % 2==0) return 2;
          else if(hits_length % (2*p) != 0) return 1;
          else return 0;
    }
};