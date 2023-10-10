#include "klibtest.h"

void reset_src(char *src)
{
  for (int i = 0; i < N; i++)
    src[i] = i + 1;
}

void test_strcat() {
  int l, r;
  char *dst = (char *)data;
  char src[N] = {};
  for (l = 0; l < N; l++) {
    for (r = 0; r < N; r++) {
      if (l + r + 1 <= N)
      {
        reset();
        reset_src(src);
        src[r] = '\0';
        dst[l] = '\0';
        strcat(dst, src);
        check_seq(0, l, 1); 
        check_seq(l, l + r, 1);
        check_eq(l + r, l + r + 1, 0);
        check_seq(l + r + 1, N, l + r + 2);
      }
    }
  }
}

int main()
{
  test_strcat();
}
