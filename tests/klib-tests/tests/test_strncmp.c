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
    dst[i] = i + 1;
  }
  dst[N/2] = '\0';
}

void check_ncmp(char *A, char *B, int n, int code)
{
  int dif;
  for (int i = 0; i < N; i++)
  {
    dif = A[i] - B[i];
    if (A[i] == '\0' || B[i] == '\0' || dif != 0 || i >= n)
      break;
  }

  if (dif < 0)
    assert(code < 0);
  else if (dif > 0)
    assert(code > 0);
  else
    assert(code == 0);
}

void test_strncmp() {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i != j)
      {
        for (int n = 0; n < N; n++)
        {
          reset_all();
          src[i] = '\0';
          src[j] = (i + j) / 2;
          int code;

          code = strncmp(src, dst, n);
          check_ncmp(src, dst, n, code);

          code = strncmp(dst, src, n);
          check_ncmp(dst, src, n, code);
        }
      }
    }
  }
}

int main()
{
  test_strncmp();
}
