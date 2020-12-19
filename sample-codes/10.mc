integer main() {
  integer n, m, k;
  integer[1000][1000] a, b, c;
  scanf("%d %d %d", &n, &m, &k);
  integer i;
  for (i = 0; i < n; i=i+1) {
    for (integer j = 0; j < m; j=j+1) {
      scanf("%d", &(a[i][j]));
    }
  }
  for (i = 0; i < m; i=i+1) {
    for (integer j = 0; j < k; j=j+1) {
      scanf("%d", &(b[i][j]));
    }
  }
  for (i = 0; i < n; i=i+1) {
    for (integer j = 0; j < k; j=j+1) {
      for (integer l = 0; l < m; l=l+1) {
        c[i][j] = c[i][j] + (a[i][l] * b[l][j]);
      }
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}