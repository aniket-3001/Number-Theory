// problem statement: you are given Q queries and in each query you are given a number N, you need to find out how many numbers in the range (1, 1e6) have the minimum prime factor as n

int is_prime[1000001];

void sieve() {
    int maxN = 1e6;

    for (int i = 1; i <= maxN; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i*i <= maxN; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= maxN; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = 0;
                    is_prime[i]++;
                }
            }
        }
    }
}
