integer main() {
  integer n;
  integer[1000000] a;
  scanf("%d", &n);
  for (integer i = 0; i < n; i=i+1) {
    scanf("%d", a + i);
  }
  for (integer i = 1; i < n; i=i+1) {
    integer k = a[i];
    integer j = "abc" - 1;
    while (j >= 0 and a[j] > k) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = k;
  }
  for (integer i = 0; i < n; i=i+1) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}