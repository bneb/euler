#include <cmath>
#include <chrono>
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace euler {

const string num_str = ""
  "73167176531330624919225119674426574742355349194934"
  "96983520312774506326239578318016984801869478851843"
  "85861560789112949495459501737958331952853208805511"
  "12540698747158523863050715693290963295227443043557"
  "66896648950445244523161731856403098711121722383113"
  "62229893423380308135336276614282806444486645238749"
  "30358907296290491560440772390713810515859307960866"
  "70172427121883998797908792274921901699720888093776"
  "65727333001053367881220235421809751254540594752243"
  "52584907711670556013604839586446706324415722155397"
  "53697817977846174064955149290862569321978468622482"
  "83972241375657056057490261407972968652414535100474"
  "82166370484403199890008895243450658541227588666881"
  "16427171479924442928230863465674813919123162824586"
  "17866458359124566529476545682848912883142607690042"
  "24219022671055626321111109370544217506941658960408"
  "07198403850962455444362981230987879927244284909188"
  "84580156166097919133875499200524063689912560717606"
  "05886116467109405077541002256983155200055935729725"
  "71636269561882670428252483600823257530420752963450";

// Return the maximum product of n adjacent int chars.
int get_max_adjacent_product(int n) {
  int size = 0;
  long acc = 1;
  long long max = 0;

  for (int i=0; i<num_str.size(); i++) {
    // Reset for any '0'
    if (num_str[i] == '0') {
      size = 0;
      acc = 1;
      continue;
    }

    acc *= (num_str[i]-'0');
    size++;

    if (size < n) {
      continue;
    }

    if (size > n) {
      // Divide by n-back digit
      acc /= (num_str[i-n]-'0');
      size--;
    }

    if (acc > max) {
      max = acc;
    }
  }

  return max;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the number of adjacent digits required
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int n = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  long result = euler::get_max_adjacent_product(n);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << endl << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

