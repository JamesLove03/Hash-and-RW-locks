#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/hash.c"
#include "src/rwlock.c"

#define MAX_LINE 256

void Sorter(const char *operation, const char *name, int value) {
    printf("Sorter() called with: [%s], [%s], [%d]\n",
           operation, name, value);
}




int main() {
    
    FILE *inpfile, *outputfile;
    inpfile = fopen("commands.txt", "r"); //opens file
    outputfile = fopen("output.txt", "w");
    
    int num_threads = 0; //holds number of threads
    char buffer[MAX_LINE]; //holds first line
    int dummy = 0;
    char dummys[2];
    int line_num = 0;

    if ((inpfile == NULL) || (outputfile == NULL))
    {
        perror("Error opening file(s)");
        return 1;
    }


    if(fgets(buffer, sizeof(buffer), inpfile) != NULL) {

        if(sscanf(buffer,"%49[^,],%d,%d", dummys, &num_threads, &dummy))
            fprintf(outputfile, "Running %d threads", num_threads);
        
    }


    buffer[strcspn(buffer, "\n")] = 0;
    line_num++;


    while (fgets(buffer, sizeof(buffer), inpfile) != NULL) {
        char *op = NULL, *name = NULL;
        char *token;
        int value = 0;

        // Strip newline
        buffer[strcspn(buffer, "\n")] = 0;
        line_num++;

        // Tokenize the line
        token = strtok(buffer, ",");
        if (token) op = token;

        token = strtok(NULL, ",");
        if (token) name = token;

        token = strtok(NULL, ",");
        if (token) value = atoi(token);

        if (op && name) {
            Sorter(op, name, value); // Call your function
        } else {
            printf("Invalid line format at line %d.\n", line_num + 1);
        }
    }
    


    return 0;
}



