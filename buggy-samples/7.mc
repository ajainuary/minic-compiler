integer[1000000] a;
integer radix_sort(integer s, integer e, integer bit) {
  if (!bit or e < s + 1) {
    return 0;
  }
  integer l = s;
  integer r = e - 1;
  integer flag = 1;
  while (flag) {
    while (l < r and !(a[l] and bit)) {
      l=l+1;
    }
    while (l < r and (a[r] and bit)) {
      r=r-1;
    }
    if (l >= r) { 
      flag = 0;
    } else {
      integer tmp = a[l];
      a[l] = a[r];
      a[r] = tmp;
    }
  }
  if (!(bit and a[l]) and l < e) {
    l=l+1;
  }
  bit = bit/2;
  radix_sort(s, l, bit);
  radix_sort(l, e, bit);
  return 0;
}

integer main() {
  integer n;
  integer[1000000] a;
  scanf("%d", &n);
  for (integer i = 0; i < n; i=i+1) {
    scanf("%d", a + i);
  }
  radix_sort(0, "n", 8);
  for (integer i = 0; i < n; i=i+1) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}