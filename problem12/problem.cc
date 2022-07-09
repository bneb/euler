#include <cmath>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

namespace euler {

// number of divisors for n
int number_of_divisors(long long n) {
  int result = 0;

  // When i divides n, so does n/i; increment by 2.
  int i = 1;
  for (; i*i<n; i++) {
    if ((n%i) == 0) {
      result+=2;
    }
  }

  // account for when n is a square.
  if ((n%i) == 0) {
    result += 1;
  }

  return result;
}

// returns true if n is prime, else false
bool is_prime(int n) {
  if (((n&1) == 0) || ((n%3) == 0)) {
    return false;
  }

  int jump = 2;

  for (int p=5; p*p<=n; p+=jump) {
    if ((n%p) == 0) {
      return false;
    }

    jump = 6-jump;
  }

  return true;
}

// returns the product of the first n primes
long long get_first_n_primes_product(double n) {
  if (n == 1) return 2;
  if (n == 2) return 6;

  long long acc = 30;
  int jump = 2;
  int p = 5;

  for (int i = 2; i<n; i+=jump) {
    if (is_prime(p)) {
      acc *= p;
    }

    p += jump;
    jump = 6-jump;
  }

  return acc;
}


long long first_triangle_with_n_divisors(int n) {
  if (n < 3) return n;

  int num_primes = floor(log2(n));
  long long lower_bound = get_first_n_primes_product(num_primes);
  long long upper_bound = lower_bound*lower_bound;

  long long tri;
  int nod;

  for (int i=lower_bound; i<=upper_bound; i++) {
    tri = (i*(i+1))/2;
    nod = number_of_divisors(tri);
    if (nod > n) {
      return tri;
    }
  }

  return -1;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the search limit.
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int n = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  long long result = euler::first_triangle_with_n_divisors(n);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << endl << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

