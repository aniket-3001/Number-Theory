// Euclid's Division Lemma:
// for positive integers A and B, there exist integers q and r such that A = B*q + r where 0 <= r < B

// N1 = mod*q1 + r1
// N2 = mod*q2 + r2

// (N1 + N2) % mod = (mod*q1 + r1 + mod*q2 + r2) % mod
//                 = (r1 + r2) % mod
//                 = ((N1 % mod) + (N2 % mod)) % mod

// modulo-arithmetic:
// (a+b) % n = ((a % n) + (b % n)) % n
// (a*b) % n = ((a % n)*(b % n)) % n

// Euclidian algorithm to calculate GCD of A and B
// gcd(A, B) = {A (B = 0), gcd(B, A % B) otherwise}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}
