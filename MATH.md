## Sieve of Eratosthenes

1. best way to find primes.

```cpp
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
```

2. [Not special no](https://leetcode.com/contest/weekly-contest-408/) find numbers in given range [l,r] which only have 2 factors , 1 and other number (not number itself)., eg 4 => facotrs 1, 2

- sol: such numbers are square of prime num
- eg: 9 => factors 1, 3
- eg: 25 => factors 1, 5
- find prime no up to sqrt(r) (using sieve of eratosthens) because num >sqrt are not going to be special
- and then check if it exits in range,

```cpp
int nonSpecialCount(int l, int r) {
    // Calculate the limit up to which we need to find prime numbers
    int lim = (int)(sqrt(r));

    // Create a boolean array to mark primes up to lim using Sieve of Eratosthenes
    vector<bool> v(lim + 1, true);
    v[0] = v[1] = false; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes to mark non-prime numbers
    for (int i = 2; i * i <= lim; i++) {
        if (v[i]) {
            for (int j = i * i; j <= lim; j += i) {
                v[j] = false;
            }
        }
    }

    // Count special numbers in the range [l, r]
    int cnt = 0;
    for (int i = 2; i <= lim; i++) {
        if (v[i]) {
            int square = i * i;
            if (square >= l && square <= r) {
                cnt++;
            }
        }
    }
    // Total numbers in the range [l, r]
    int totalCount = r - l + 1;
    // Calculate non-special numbers
    return totalCount - cnt;
}
```

3. MODULO OPERATIONS:

- 1. (a+b)%c = ((a%c)+(b%c))%c
- 2. (a*b)%c = ((a%c)*(b%c))%c
- 3. (a-b)%c = ((a%c)-(b%c)+c)%c
- 4. (a/b)%c = ((a%c)?(b%c))%c

4.  Divisors of a number:

```cpp
void printDivisorsOptimal(int n){
    cout << "The Divisors of " << n << " are:" << endl;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i)
                cout << n / i << " ";
        }
    cout << "\n";
}
```

5. Binray Exponencitaion

```cpp
int power(int x, int y, int p) {
    // Initialize result
    int res = 1;

    // Update x if it is more than or equal to p
    x = x % p;

    // In case x is divisible by p
    if (x == 0)
        return 0;

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main() {
    // Find 9^5 mod 1000000007
    std::cout << power(9, 5, 1000000007) << std::endl;
    return 0;
}
```

6. Prime Factorization & Divisors

```cpp
using namespace std;

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    // n must be odd at this point. So we can skip one
    // element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    // This condition is to handle the case when n is a
    // prime number greater than 2
    if (n > 2) {
        cout << n;
    }
}
// Test the function
int main()
{
    primeFactors(315);
    return 0;
}
```
