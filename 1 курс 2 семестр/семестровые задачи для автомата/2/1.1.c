#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_and_replace(char *source, char *pattern, char *replacement, char *result) {

    unsigned int patternLength = strlen(pattern), replacementLength = strlen(replacement);

    char *tail = source; char *temp = result; char *next = strstr(tail, pattern);
    while(next != NULL) { int k = next - tail; if (tail[k + patternLength] == '+' || tail[k + patternLength] == '-' || tail[k + patternLength] == '/' || tail[k + patternLength] == '*' || tail[k + patternLength] == ')') {
      if (tail[k - 1] == '+' || tail[k - 1] == '-' || tail[k - 1] == '/' ||
          tail[k - 1] == '*' || tail[k - 1] == '(') {
            strncpy(result, tail, next - tail);
            strcpy(result += next - tail, replacement);
            result = result + replacementLength;
            tail = next + patternLength;
            next = strstr(tail, pattern);
            } else {
                strncpy(result, tail, 1);
                next = strstr(&next[1], pattern);}} else {strncpy(result, tail, 1);
            next = strstr(&next[1], pattern);}}strcpy(result, tail);strcpy(source, temp);}

int main() {
    int W = 512;
    char oldstr[W], newstr[W], numb_array[W][W], ids_array[W][W];
    int lines_count;
    int left = 1, right = 0;
    unsigned int oldstrlen, realstr;
    FILE *input, *output;
    output = fopen("output.txt", "w");
    input = fopen("input.txt", "r");
    fscanf(input, "%i", &lines_count);
    for(int i = 0; i < lines_count; i++) {
        fscanf(input, "%s", &ids_array[i][W]);
        fscanf(input, "%s", &numb_array[i][W]);
    } fscanf(input, "%s", oldstr); oldstrlen = strlen(oldstr) - 1;
    if(oldstr[0] == '(') {
        int i = 1;
        while ((oldstr[i] <= 'z' && oldstr[i] >= 'a') || (oldstr[i] >= '0' && oldstr[i] <= '9') ||
               (oldstr[i] <= 'Z' && oldstr[i] >= 'A') || oldstr[i] == '_') {
            i++;
            if (oldstr[i] == '+' || oldstr[i] == '-' || oldstr[i] == '/' || oldstr[i] == '*') {
                i++;
                if (oldstr[i] == '(') {
                    left++;
                    i++;
                }
                else {
                    while ((oldstr[i] <= 'z' && oldstr[i] >= 'a') || (oldstr[i] >= '0' && oldstr[i] <= '9') ||
                           (oldstr[i] <= 'Z' && oldstr[i] >= 'A') || oldstr[i] == '_') {
                        i++;
                        while (oldstr[i] == ')' && right < left) {
                            i++;
                            right++;
                            if (oldstr[i] != 0 && oldstr[i] != ')') {
                                fprintf(output, "INCORRECT\n");
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
    else for(int i = 0; ((oldstr[i] <= 'z' && oldstr[i] >= 'a') || (oldstr[i] >= '0' && oldstr[i] <= '9') ||
                         (oldstr[i] <= 'Z' && oldstr[i] >= 'A') || oldstr[i] == '_') && oldstr[i] != 0 ; i++) {
            realstr = i;
        }

    if(right == left) {
        for(int i = 0; i < lines_count; i++) {
            find_and_replace(oldstr, &ids_array[i][W], &numb_array[i][W], newstr);
        }
        fprintf(output, "%s\n", newstr);
        exit(0);
    }

    if(oldstrlen == realstr) {
        for(int i = 0; i < lines_count; i++) {
            if (strstr(oldstr, &ids_array[i][W]) != NULL && strlen(&ids_array[i][W]) == strlen(oldstr)) {
                strcpy(newstr, &numb_array[i][W]);
                lines_count = 0;
            }}
        if(lines_count != 0) {
            strcpy(newstr, oldstr);
        }
    } else {
        fprintf(output, "INCORRECT\n");
        exit(0);
    }
    fprintf(output, "%s\n", newstr);
    fclose(input);
    fclose(output);
    return 0;
}
