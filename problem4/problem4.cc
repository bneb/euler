#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace euler {

bool is_palindrome(string s) {
  int li = 0;
  int ri = s.size()-1;

  while (li < ri) {
    if (s[li] != s[ri]) {
      return false;
    }

    li++;
    ri--;
  }

  return true;
}

string greatest_product_palindrome(int digits) {
  int min_fac = round(pow(10, digits-1));
  int max_fac = round(pow(10, digits) - 1);
  int max_value = max_fac*max_fac;

  for (int n=max_value; n>=9; n--) {
    string s = to_string(n);
    if (!is_palindrome(s))  continue;

    for (int fac1=max_fac; fac1>=min_fac; fac1--) {
       if ((n%fac1) != 0) continue;

       int fac2 = n/fac1;
       if (fac2 <= max_fac) {
         return to_string(fac1) + " x " + to_string(fac2) + " = " + s;
       }
    }
  }

  return "not found";
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the number to bound our loop
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int digits = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  string result = euler::greatest_product_palindrome(digits);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

