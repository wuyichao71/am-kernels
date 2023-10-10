#include "klibtest.h"

void test_strlen() {
  int r;
  char *src = (char *)data;
  for (r = 0; r < N; r++) {
    reset();
    src[r] = '\0';
    assert(strlen(src) == r);
  }
}

int main()
{
  test_strlen();
}
