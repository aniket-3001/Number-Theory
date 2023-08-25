// used when we need to answer Q queries (say a million) and N is like 1e6 or 1e7
// T.C: O(NloglogN + QlogN) (for Q queries, where Q denotes the number of queries)
// S.C: O(N)

bool is_prime[1000001];

void sieve() {
    int maxN = 1e6;

    for (int i = 2; i <= maxN; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i*i <= maxN; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                is_prime[j] = false; // not a prime
            }
        }
    }
}

