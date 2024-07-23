#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_output(char **map, void (*callback)(char **))
{

    // Flush the standard output buffer
    fflush(stdout);

    char *buffer = (char *)malloc(sizeof(char) * 1024);
    // Clear the buffer used to capture the output of the function being tested
    memset(buffer, 0, 1024);

    // Redirect the output to a file
    int saved_stdout = dup(STDOUT_FILENO);
    int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);
    dup2(output_fd, STDOUT_FILENO);
    close(output_fd);

    // Call the function to be tested
    callback(map);

    // Restore the original output
    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Open the output file and check its contents
    FILE *fp = fopen("output.txt", "r");
    fgets(buffer, 1024, fp);
    fclose(fp);

    // Delete the output file
    remove("output.txt");
    return buffer;
}