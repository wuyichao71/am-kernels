#include "trap.h"
/* #include <stdio.h> */
#include <limits.h>
int data[] = {
  0, 
  INT_MAX / 17, 
  INT_MAX, 
  INT_MIN, 
  INT_MIN + 1,
  UINT_MAX / 17, 
  INT_MAX / 17, 
  UINT_MAX,
};
char *out[] = {
  "0 is always 0\n",
  "126322567 is always 126322567\n",
  "2147483647 is always 2147483647\n",
  "-2147483648 is always -2147483648\n",
  "-2147483647 is always -2147483647\n",
  "252645135 is always 252645135\n",
  "126322567 is always 126322567\n",
  "-1 is always -1\n",
};

char *out_hh[] = {
  "0 is always 0\n",
  "-121 is always -121\n",
  "-1 is always -1\n",
  "0 is always 0\n",
  "1 is always 1\n",
  "15 is always 15\n",
  "-121 is always -121\n",
  "-1 is always -1\n",
};
char *out_h[] = {
  "0 is always 0\n",
  "-30841 is always -30841\n",
  "-1 is always -1\n",
  "0 is always 0\n",
  "1 is always 1\n",
  "3855 is always 3855\n",
  "-30841 is always -30841\n",
  "-1 is always -1\n",  
};
char *out_l[] = {
  "0 is always 0\n",
  "126322567 is always 126322567\n",
  "2147483647 is always 2147483647\n",
  "2147483648 is always 2147483648\n",
  "2147483649 is always 2147483649\n",
  "252645135 is always 252645135\n",
  "126322567 is always 126322567\n",
  "4294967295 is always 4294967295\n",
};
char *out_ll[] = {
  "0 is always 0\n",
  "126322567 is always 126322567\n",
  "2147483647 is always 2147483647\n", 
  "2147483648 is always 2147483648\n", 
  "2147483649 is always 2147483649\n", 
  "252645135 is always 252645135\n",
  "126322567 is always 126322567\n",
  "4294967295 is always 4294967295\n",
};

char buf[128];


int main()
{
  for (int i = 0; i < sizeof(data) / sizeof(int); i++)
  {
    sprintf(buf, "%d %s %s %d\n", data[i], "is", "always", data[i]);
    printf(buf, "%d %s %s %d\n", data[i], "is", "always", data[i]);
    check(strcmp(buf, out[i]) == 0);

    sprintf(buf, "%hhd %s %s %hhd\n", data[i], "is", "always", data[i]);
    printf(buf, "%hhd %s %s %hhd\n", data[i], "is", "always", data[i]);
    check(strcmp(buf, out_hh[i]) == 0);

    sprintf(buf, "%hd %s %s %hd\n", data[i], "is", "always", data[i]);
    printf(buf, "%hd %s %s %hd\n", data[i], "is", "always", data[i]);
    check(strcmp(buf, out_h[i]) == 0);

    sprintf(buf, "%ld %s %s %ld\n", data[i], "is", "always", data[i]);
    printf(buf, "%ld %s %s %ld\n", data[i], "is", "always", data[i]);
    check(strcmp(buf, out_l[i]) == 0);

    sprintf(buf, "%lld %s %s %lld\n", data[i], "is", "always", data[i]);
    printf(buf, "%lld %s %s %lld\n", data[i], "is", "always", data[i]);
    check(strcmp(buf, out_ll[i]) == 0);
  }

  sprintf(buf, "%s\n", "Hello, world!");
  printf(buf, "%s\n", "Hello, world!");
  check(strcmp(buf, "Hello, world!\n") == 0);

  sprintf(buf, "%10s\n", "Hello, world!");
  printf(buf, "%10s\n", "Hello, world!");
  check(strcmp(buf, "Hello, world!\n") == 0);

  sprintf(buf, "%20s\n", "Hello, world!");
  printf(buf, "%20s\n", "Hello, world!");
  check(strcmp(buf, "       Hello, world!\n") == 0);

  sprintf(buf, "%-20s\n", "Hello, world!");
  printf(buf, "%-20s\n", "Hello, world!");
  check(strcmp(buf, "Hello, world!       \n") == 0);

  sprintf(buf, "%20.15s\n", "Hello, world!");
  printf(buf, "%20.15s\n", "Hello, world!");
  check(strcmp(buf, "       Hello, world!\n") == 0);

  sprintf(buf, "%20.10s\n", "Hello, world!");
  printf(buf, "%20.10s\n", "Hello, world!");
  check(strcmp(buf, "          Hello, wor\n") == 0);

  sprintf(buf, "%-20.10s\n", "Hello, world!");
  printf(buf, "%-20.10s\n", "Hello, world!");
  check(strcmp(buf, "Hello, wor          \n") == 0);

  sprintf(buf, "%-20.30s\n", "Hello, world!");
  printf(buf, "%-20.30s\n", "Hello, world!");
  check(strcmp(buf, "Hello, world!       \n") == 0);

  sprintf(buf, "%20.0s\n", "Hello, world!");
  printf(buf, "%20.0s\n", "Hello, world!");
  check(strcmp(buf, "                    \n") == 0);

  int num = 123456789;
  sprintf(buf, "%4d\n", num);
  printf(buf, "%4d\n", num);
  check(strcmp(buf, "123456789\n") == 0);

  sprintf(buf, "%15d\n", num);
  printf(buf, "%15d\n", num);
  check(strcmp(buf, "      123456789\n") == 0);

  sprintf(buf, "%20.15d\n", num);
  printf(buf, "%20.15d\n", num);
  check(strcmp(buf, "     000000123456789\n") == 0);

  sprintf(buf, "%-20.15d\n", num);
  printf(buf, "%-20.15d\n", num);
  check(strcmp(buf, "000000123456789     \n") == 0);

  sprintf(buf, "%- 20.15d\n", num);
  printf(buf, "%- 20.15d\n", num);
  check(strcmp(buf, " 000000123456789    \n") == 0);

  sprintf(buf, "%+20.15d\n", num);
  printf(buf, "%+20.15d\n", num);
  check(strcmp(buf, "    +000000123456789\n") == 0);
  /* for(char *cp = buf; *cp; cp++) */
  /*   putch(*cp); */

  return 0;
}
