#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int processArray(int array[], int len) {
  /*
   * Do not make any changes outside this function.
   *
   * Modify this function to process `array` as indicated
   * in the question. At the end, return the length of the
   * array.
   *
   * Do not print anything in this function
   * Do not write anything to the standard output
   *
   * Submit this entire program (not just this function)
   * as your answer
   */
    int *b = (int *)malloc(len * sizeof(int));
    int i = 0, j = 0;
    int cnt = 0;
    while(i < len) {
        if(i == len-1) {
            b[j++] = array[i++];
            break;
        }
        if(array[i]%2 == 1 && array[i+1]%2 == 1) {
            cnt=0;
            while(array[i]%2 == 1){
                cnt++;
                i++;
                if(i == len)
                    break;
            }
            b[j++] = cnt;
            cnt = 0;
        } else {
            b[j++] = array[i++];
        }
    }
    int k;
    /** copying our modified array to the original array **/
    for(k=0; k < j; k++) {
        array[k] = b[k];
    }
    /** modified length of our array **/
    len = j;
    return len;
}

int main() {

  int *array;
  int len = 0, maxsize = 1024, i, input, new_len;
  int result;
  array = (int *)malloc(maxsize*sizeof(int));
  while(scanf("%d", &input) == 1) {
    if (input < 0) break; /* Stop when a negative number is entered */
    array[len++] = input;
    if (len == maxsize) { /* array is full. increase size */
      maxsize *= 2;
      array = (int *)realloc(array, maxsize*sizeof(int));
    }
  }
  new_len = processArray(array, len);
  for(i=0; i<new_len; i++)
    printf("%d\n", array[i]);

  return 0;
}

