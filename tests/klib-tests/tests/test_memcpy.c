#include "klibtest.h"

void test_memcpy() {
  int l, r;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      if (l >= r - l)
      {
        reset();
        memcpy(data + l, data, r - l);
        check_seq(0, l, 1); 
        check_seq(l, r, *data); 
        check_seq(r, N, r + 1);
      }
    }
  }
}

int main()
{
  test_memcpy();
}
