int Solution::cpFact(int x, int y) {

    while (__gcd(x, y) != 1) {
        x = x / __gcd(x, y);
    }
    return x;
}
