integer[101] a;

void permute(integer s, integer n) {
  if (s == 1) {
    for (integer i = 0; i < n; i=i+1) {
      printf("%d ", a[i]);
    }
    printf("\n");
  } else {
    for (integer i = 0; i < s; i=i+1) {
      permute(s - 1, n);
      integer tmp = a[(s mod 2 == 0) ? i : 0];
      a[(s mod 2 == 0) ? i : 0] = a[s-1];
      a[s-1] = tmp;
    }
  }
}

integer main() {
  integer n;
  scanf("%d", &n);
  for (integer i = 0; i < n; i=i+1) {
    a[i] = i + 1;
  }
  permute(n, n);
  return 0;
}