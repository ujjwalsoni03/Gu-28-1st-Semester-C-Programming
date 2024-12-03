#include <stdio.h>
void display_binary(int header) {
 for (int i = 7; i >= 0; i--) {
 printf("%d", (header >> i) & 1);
 }
 printf("\n");
}
int main() {
 int header;
 scanf("%d", &header);
 header ^= (1 << 0);
 header |= (1 << 1);
 printf("New Header in Decimal: %d\n", header);
 printf("New Header in Binary: ");
 display_binary(header);
 header &= ~(1 << 2);
 printf("New Header after clearing encryption status: %d\n", header);
 printf("New Header in Binary: ");
 display_binary(header);
 if ((header >> 3) & 1) {
printf("Error Detected: Yes\n");
 } else {
 printf("Error Detected: No\n");
 }
 int shifted_header = header << 1;
 printf("Header after Left Shift by 1 Bit: %d\n", shifted_header);
 printf("New Header in Binary: ");
 display_binary(shifted_header);
 return 0;
}