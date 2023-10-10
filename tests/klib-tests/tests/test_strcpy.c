#include "klibtest.h"

void test_strcpy() {
  int l, r;
  char *cdata = (char *)data;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      if (r + l + 1 <= N)
      {
        reset();
        data[l] = '\0';
        strcpy(cdata + r, cdata);
        check_seq(0, l, 1); 
        check_eq(l, l + 1, 0);
        check_seq(l + 1, r, l + 2); 
        check_seq(r, r + l, *data);
        check_eq(r + l, r + l + 1, 0);
        check_seq(r + l + 1, N, r + l + 2);
      }
    }
  }
}

int main()
{
  test_strcpy();
}
