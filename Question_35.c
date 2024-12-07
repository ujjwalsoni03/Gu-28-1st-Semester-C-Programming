#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
  
#define MAX_CHAR 26 
  
typedef struct { 
    char character; 
    int frequency; 
} CharFreq; 
  
void countFrequency(char *str, CharFreq **freq, int *size) { 
    int count[MAX_CHAR] = {0}; 
  
    for (int i = 0; str[i] != '\0'; i++) { 
        char c = tolower(str[i]); 
        if (isalpha(c)) { 
            count[c - 'a']++; 
        } 
    } 
  
    *size = 0; 
    for (int i = 0; i < MAX_CHAR; i++) { 
        if (count[i] > 0) { 
            (*size)++; 
        } 
    } 
  
    *freq = (CharFreq *)malloc(*size * sizeof(CharFreq)); 
  
    int index = 0; 
    for (int i = 0; i < MAX_CHAR; i++) { 
        if (count[i] > 0) { 
            (*freq)[index].character = i + 'a'; 
            (*freq)[index].frequency = count[i]; 
            index++; 
        } 
    } 
} 
  
int compare(const void *a, const void *b) { 
    CharFreq *freqA = (CharFreq *)a; 
    CharFreq *freqB = (CharFreq *)b; 
  
    if (freqB->frequency != freqA->frequency) { 
        return freqB->frequency - freqA->frequency; 
    } 
  
    return freqA->character - freqB->character; 
} 
  
int main() { 
    char *input = NULL; 
    size_t len = 0; 
    size_t read; 
  
    read = getline(&input, &len, stdin); 
    if (read == -1) { 
        printf("Error reading input.\n"); 
        return 1; 
    } 
  
    input[strcspn(input, "\n")] = '\0'; 
  
    CharFreq *freq = NULL; 
    int size = 0; 
  
    countFrequency(input, &freq, &size); 
  
    qsort(freq, size, sizeof(CharFreq), compare); 
  
    for (int i = 0; i < size; i++) { 
        printf("%c: %d\n", freq[i].character, freq[i].frequency); 
    } 
  
    free(input); 
    free(freq); 
  
    return 0;} 