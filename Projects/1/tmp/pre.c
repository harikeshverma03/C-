#include <stdio.h>

char getcustomchar() {
  char c = getchar();
  while (c == ' ' || c == '\n') {
    c = getchar();
  }
  return c;
}

int main() {
  char array_of_strings[10][10] = {}, ch;
  int arr[10] = {};
  int count = 0;
  ch = getcustomchar();
  do {
    array_of_strings[count][0] = ch;
    scanf(" %s", array_of_strings[count] + 1);
    scanf("%d", &arr[count]);
    count++;
    ch = getcustomchar();
  } while (ch != EOF && count < 11);

  for (int i = 0; i < count; i++) {
		if(arr[i] < 10) continue;
		printf("%s\n", array_of_strings[i]);
  }
  return 0;
}
