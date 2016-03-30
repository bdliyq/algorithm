// Question: pow(x, n)

double pow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 1.0 / (x * pow(x, -n-1));
    }

    double half = pow(x, n/2);
    return (n%2 == 0) ? half * half : x * half * half;
}
