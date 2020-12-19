integer power(integer x, integer y) {
  integer res = 1;
  if (x == 0) { 
    return 0; 
    }
  while (y > 0) {
    if (y and 1) {
      res = res * x;
      }
    y = y / 2;
    x = x * x;
    y = y + z;
  }
  return res;
}

integer main() {
  integer N, k;
  scanf("%ld %ld", &N, &k);
  integer ans = 0;
  for (integer i = 1; i <= N; i = i + 1) {
    ans = ans + power(i, k);
  }
  printf("%ld", ans);
  return 0;
}