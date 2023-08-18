// problem statement: we are given a range [l,r] and we have to find the prime numbers in this range
// constraints: 1 <= l <= r <= 10^12 and r-l <= 10^6

// solution: we will use segmented sieve to solve this problem

// 1) we will first find the prime numbers from 1 to sqrt(r) using normal sieve, we will store these prime numbers in a vector
// 2) then we will create a boolean array of size r-l+1 and initialize it with true
// 3) then we will iterate over the prime numbers vector and mark all the multiples of prime numbers as false in the boolean array
// 4) then we will iterate over the boolean array and print the prime numbers

#include <bits/stdc++.h>
using namespace std;

bool is_prime[1000001];
vector <int> primes;

void sieve() {

    int maxN = 1e6;

    for (int i = 2; i <= maxN; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*i <= maxN; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                is_prime[j] = false; // not a prime
            }

            primes.push_back(i);
        }
    }
}

void SegmentedSieve(long long L, long long R) {
    bool is_prime[R-L+1];

    for (int i = 0; i <= R-L; i++) is_prime[i] = true;

    for (auto pr: primes) {
        int first_multiple = (L/pr)*pr;
        if (first_multiple < L) first_multiple += pr;

        for (int j = max(first_multiple, (int) pr*pr); j <= R; j += pr) {
            is_prime[j-L] = false;
        }
    }

    // getting all the primes

    for (int i = 0; i <= R-L; i++) {
        if (is_prime[i]) cout << i+L << " ";
    }
}