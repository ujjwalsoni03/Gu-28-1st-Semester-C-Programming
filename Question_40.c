#include <stdio.h>
#include <string.h>
void reorderString(char *s) {
 int len = strlen(s);
 char result[100]; // Assuming the input will not exceed 100 characters
 int resultIndex = 0;
 // First pass: Select characters with an interval of 2 from the start
 for (int i = 1; i < len; i += 2) {
 result[resultIndex++] = s[i];
 }
 // Second pass: Select characters with an interval of 2 from the end
 for (int i = len - 2; i >= 0; i -= 2) {
 result[resultIndex++] = s[i];
 }
 // Null-terminate the result string
 result[resultIndex] = '\0';
 
 // Print the reordered string
 printf("%s\n", result);
}
int main() {
 char s[100];
 scanf("%s", s);
 reorderString(s);
 return 0;
}