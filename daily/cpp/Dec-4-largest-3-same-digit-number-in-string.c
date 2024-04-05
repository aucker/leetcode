#pragma GCC optimize("O3", "unroll-loops")

char* largestGoodInteger(char* num) {
  int count = 0;
  char prev = num[0], maxd = ' ';
  for (register int i = 0; num[i] != '\0'; i++) {
    char c = num[i];
    if (c == prev)
      count++;
    else
      count = 1;
    if (count == 3 && c > maxd) maxd = c;
    prev = c;
  }

  if (maxd == ' ') return "";
  char* res = malloc(4);
  memset(res, maxd, 3);
  res[3] = '\0';
  return res;
}
