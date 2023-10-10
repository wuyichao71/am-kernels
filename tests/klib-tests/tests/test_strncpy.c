#include "trap.h"

#define N 32

char src[N];
char dst[N];

void check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(dst[i] == val + i - l);
  }
}

void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(dst[i] == val);
  }
}

void reset_all() {
  int i;
  for (i = 0; i < N; i ++) {
    src[i] = i + 1;
    dst[i] = i + 33;
  }
}

void test_strncpy() {
  int l, n;
  for (l = 0; l < N; l++) {
    for (n = 0; n < N; n++) {
      reset_all();
      src[l] = '\0';
      strncpy(dst, src, n);
      if (n <= l)
      {
        check_seq(0, n, src[0]);
      }
      else
      {
        check_seq(0, l, src[0]);
        check_eq(l, n, 0);
      }
        check_seq(n, N, n + 33);
      /* check_seq(n, N, n + 33); */
    }
  }
}

int main()
{
  test_strncpy();
}
