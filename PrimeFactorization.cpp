// if  N is a composite number, then N has a prime factor less than or equal to sqrt(N)

unordered_map <int, int> primeFactors(int n) {
    unordered_map <int, int> mp;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;

            while (n % i == 0) {
                cnt++;
                n /= i;
            }

            mp[i] = cnt;
        }
    }
}