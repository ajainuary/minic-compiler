integer notPrime[10000000];

integer main() {
  integer N;
  scanf("%lld", &N);
  for (integer i = 2; i < N; i = i+1) {
    if (notPrime[i] != 0) {
      ans = i+1;
      for (integer j = 1; i * j < N; j=j+1) {
        notPrime[i * j] = 1;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}