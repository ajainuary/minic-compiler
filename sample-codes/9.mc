integer main() {
  integer n, m;
  integer[1000][1000] a, b, c;
  scanf("%d %d", &n, &m);
  integer i;
  for (i = 0; i < n; i=i+1) {
    for (integer j = 0; j < m; j=j+1) {
      scanf("%d", &(a[i][j]));
    }
  }
  for (i = 0; i < n; i=i+1) {
    for (integer j = 0; j < m; j=j+1) {
      scanf("%d", &(b[i][j]));
    }
  }
  for (i = 0; i < n; i=i+1) {
    for (integer j = 0; j < m; j=j+1) {
      c[i][j] = a[i][j] + b[i][j];
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}