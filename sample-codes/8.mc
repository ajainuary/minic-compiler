integer[100000] a;
integer[100000] L;
integer[100000] R;
integer merge(integer[100000] arr, integer l, integer mid, integer r) {
  integer n1 = mid - l + 1;
  integer n2 = r - mid;
  for (integer i = 0; i < n1; i=i+1) {
    L[i] = arr[l + i];
  }
  for (integer j = 0; j < n2; j=j+1) {
    R[j] = arr[mid + j + 1];
  }
  integer leftp = 0;
  integer rightp = 0;
  integer index = l;
  while (leftp < n1 and rightp < n2) {
    if (L[leftp] < R[rightp]) {
      arr[index] = L[leftp];
      leftp=leftp+1;
    } else {
      arr[index] = R[rightp];
      rightp=rightp+1;
    }
    index=index+1;
  }
  while (leftp < n1) {
    arr[index] = L[leftp];
    leftp=leftp+1;
    index=index+1;
  }
  while (rightp < n2) {
    arr[index] = R[rightp];
    rightp=rightp+1;
    index=index+1;
  }
  return 0;
}
integer merge_sort(integer[100000] arr, integer l, integer r) {
  if (l < r) {
    integer mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
  }
  return 0;
}

integer main() {
  integer n;
  scanf("%d", &n);
  integer i;
  for (i = 0; i < n; i=i+1) {
    scanf("%d", a + i);
  }
  merge_sort(a, 0, n - 1);
  for (i = 0; i < n; i=i+1) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}