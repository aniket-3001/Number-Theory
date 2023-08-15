// calculating a^n in O(logn) time

int power(int a, int n) {
    int res = 1;

    while (n > 0) {
        if (n % 2 == 0) {
            a *= a;
            n /= 2;
        } 
        
        else {
            res *= a;
            n--;
        }
    }
}