integer main() {
  integer n;
  integer[1000000] a;
  scanf("%d", &n);
  integer i;
  for (i = 0; i < n; i=i+1) {
    scanf("%d", a + i);
  }
  for (i = 1; i < n; i=i+1) {
    integer k = a[i];
    integer j = i - 1;
    while (j >= 0 and a[j] > k) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = k;
  }
  for (i = 0; i < n; i=i+1) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}