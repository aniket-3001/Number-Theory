// problem statement: you will be given Q queries, in each of which you would be given a number N, and you need to give the prime factorization of N

// solution: we will use a sieve, but this time we will store the smallest prime factor of each number

int is_prime[1000001];

void sieve() {
    int maxN = 1e6;

    for (int i = 1; i <= maxN; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i*i <= maxN; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                if (is_prime[j] == 1) {
                    is_prime[j] = i;
                }
            }
        }
    }
}

int main() {
    sieve();
    int n;
    cin >> n;

    while (n != 1) {
        cout << is_prime[n] << " ";
        n /= is_prime[n];
    }
    
    cout << endl;
    return 0;
}
