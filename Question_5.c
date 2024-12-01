#include <stdio.h>
float custom_sqrt(float number) {
 if (number <= 0) return 0;
 float guess = number / 2.0, epsilon = 0.00001;
 while ((guess * guess - number) > epsilon || (number - guess * guess) > epsilon) {
 guess = (guess + number / guess) / 2.0;
 }
 return guess;
}
int main() {
 int n;
 scanf("%d", &n);
if (n < 1 || n > 100) {
 return 1;
 }
 float arr[n], sum = 0.0, max, min, mean, stddev = 0.0;
 for (int i = 0; i < n; i++) {
 scanf("%f", &arr[i]);
 sum += arr[i];
 if (i == 0) {
 max = min = arr[i];
 } else {
 if (arr[i] > max) max = arr[i];
 if (arr[i] < min) min = arr[i];
 }
 }
 mean = sum / n;
 for (int i = 0; i < n; i++) {
 float diff = arr[i] - mean;
 stddev += diff * diff;
 }
 stddev = custom_sqrt(stddev / n);
printf("Average: %.2f\n", mean);
 printf("Maximum: %.2f\n", max);
 printf("Minimum: %.2f\n", min);
 printf("Standard Deviation: %.2f\n", stddev);
 return 0;
}
