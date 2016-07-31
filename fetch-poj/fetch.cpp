#include <stdlib.h>
#include <stdio.h>

char get_url[1024];

int main()
{
  for (int i = 1000; i <= 4054; ++i) {
    sprintf(get_url,
      "wget -q http://poj.org/problem?id=%d", i);
    printf("%s\n", get_url);
    system(get_url);
  }
  return 0;
}
