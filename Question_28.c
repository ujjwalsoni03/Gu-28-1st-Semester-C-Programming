#include <stdio.h>
void getInputArray(int arr[], int n) {
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
}
int maxProductSubarray(int arr[], int n) {
 int currentMax = arr[0];
 int currentMin = arr[0];
 int result = arr[0];
for (int i = 1; i < n; i++) {
 if (arr[i] < 0) {
 int temp = currentMax;
 currentMax = currentMin;
 currentMin = temp;
 }
 currentMax = arr[i] > arr[i] * currentMax ? arr[i] : arr[i] * currentMax;
 currentMin = arr[i] < arr[i] * currentMin ? arr[i] : arr[i] * currentMin;
 result = result > currentMax ? result : currentMax;
 }
 return result;
}
int main() {
 int n;
 scanf("%d", &n);
 int arr[n];
 getInputArray(arr, n);
 int result = maxProductSubarray(arr, n);
 printf("%d\n", result);
return 0;
}