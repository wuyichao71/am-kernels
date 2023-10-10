#include "trap.h"

#define N 32

uint8_t src[N];
uint8_t dst[N];

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
}

void check_cmp(uint8_t *A, uint8_t *B, int n, int code)
{
  int dif;
  for (int i = 0; i < N; i++)
  {
    dif = A[i] - B[i];
    if (dif != 0 || i >= n)
      break;
  }

  if (dif < 0)
    assert(code < 0);
  else if (dif > 0)
    assert(code > 0);
  else
    assert(code == 0);
}

void test_memcmp() {
  int i;
  for (i = 0; i < N; i++) {
    for (int n = 0; n < N; n++)
    {
      reset_all();
      src[i] = i / 2;
      int code;

      code = memcmp(src, dst, n);
      check_cmp(src, dst, n, code);

      code = memcmp(dst, src, n);
      check_cmp(dst, src, n, code);
    }
  }
}

int main()
{
  test_memcmp();
}
