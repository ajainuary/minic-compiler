integer gcd(integer x, integer y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x mod y);
}
integer main() {
  integer count = 0;
  for (integer i = 1; i < 10001; i=i+1) {
    for (integer j = i + 1; j < 10001; j=j+1) {
      if (gcd(j) == 1 and (i mod 2 == 0 or j mod 2 == 0)) {
        integer a = (j * j) - (i * i), b = 2 * i * j,
                      c = (i * i) + (j * j);
        for (integer k = 1; k * c < 100000001; k=k+1) {
          printf("%lld %lld %lld\n", k * a, k * b, k * c);
          count = count + 1;
        }
      }
    }
  }
  printf("Count: %lld\n", count);
  return 0;
}