#include <stdio.h>

int main() {
    
    FILE *file;
    file = fopen("commands.txt", "r"); //opens file
    
    int num_threads = 0; //holds number of threads
    char buffer[30]; //holds first line
    int dummy = 0;
    char dummys[2];

    if (file == NULL )
    {
        perror("Error opeNing file");
        return 1;
    }

    if(fgets(buffer, sizeof(buffer), file) != NULL) {

        if(sscanf(buffer,"%49[^,],%d,%d", dummys, &num_threads, &dummy))
            printf("Running %d threads", num_threads);
        
    }


    return 0;
}