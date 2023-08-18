// problem statement: Given a range of size N and Q queries in the form of L and R, print the gcd of the whole array except for the range L to R.

// solution: gcd of 1st element till L-1th element and gcd of R+1th element till Nth element will give the gcd of the whole array except for the range L to R.
// answer of query would be gcd(gcd(1,2,3,....,L-1), gcd(R+1,R+2,....,N)) = gcd(g1, g2) where g1 = gcd(1,2,3,....,L-1) and g2 = gcd(R+1,R+2,....,N)
// for this, we will use a prefix and a suffix array

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int prefix[n + 1], suffix[n + 1];
    prefix[0] = suffix[n + 1] = 0;
    prefix[1] = arr[1];
    suffix[n] = arr[n];

    for (int i = 2; i <= n; i++)
        prefix[i] = __gcd(prefix[i - 1], arr[i]);

    for (int i = n - 1; i >= 1; i--)
        suffix[i] = __gcd(suffix[i + 1], arr[i]);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << __gcd(prefix[l - 1], suffix[r + 1]) << endl;
    }

    return 0;
}

// Time Complexity: O(N + Q*logN)