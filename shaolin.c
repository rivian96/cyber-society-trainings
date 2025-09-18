#include<stdio.h>
#include <string.h>

// Modified win() function to print the contents of a bash script
void win() {
    printf("Executing and printing the contents of script.sh:\n");
    FILE *file = fopen("banner.sh", "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error: banner not found in the current directory.\n");
    }
}

void vuln_func(char *input) {
    char buffer[256];
    strcpy(buffer, input);  // Vulnerable strcpy
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Entering the vulnerable function...\n");
        vuln_func(argv[1]);
        printf("Vulnerable function exited.\n");
    } else {
        printf("Please provide an argument to overflow the buffer.\n");
    }
    return 0;
}