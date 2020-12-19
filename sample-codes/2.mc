
integer main() {
  integer N;
  scanf("%lld", &N);
  for (integer i = 2; i <= N / 2; i=i+1) {
    if (N mod i == 0) {
      printf("Not Prime\n");
      return 0;
    }
  }
  printf("Prime\n");
  return 0;
}