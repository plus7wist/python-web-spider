#include <stdio.h>

int main()
{
  freopen("pro/index.html", "w", stdout);

  const int MAX_VOL = 4;
  const int MAX_PRO = 4054;
  const int PP_VOL = 1000;
  
  for (int vi = 1; vi <= MAX_VOL; ++vi) {
    printf("<h3>%d-%d</h3>\n", vi * PP_VOL, (vi + 1) * PP_VOL - 1);
    printf("<p>");
    for (int pi = vi * PP_VOL; pi <= MAX_PRO && pi < (vi + 1) * PP_VOL; ++pi) {
      printf("<a href=\"r%dk/pro%d.html\">%d</a> ", vi, pi, pi);
    }
    printf("</p>\n");
  }
  
  return 0;
}
