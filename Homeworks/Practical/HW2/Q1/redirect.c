#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void write_data (FILE * stream, char * path)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    int n;
    char buf[1024];
    while ((n = fread(buf, 1, sizeof(buf), stream)) > 0) {
        if (write(fd, buf, n) != n) {
            perror("write");
            exit(1);
        }
    }
    if (ferror(stream)) {
        perror("fread");
        exit(1);
    }
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf(" Usage: %s <program> <file> <program arguments>\n"
                "* program: path to the program to execute.\n"
                "* file: path to the file to store the output.\n"
                "* program argument: arguments passed to program.\n", argv[0]);
        return 1;
    }
    // first check if program is executable
    // execute the program in new proccess
    // and redirect the output to the file
  FILE *output;
  char* command = malloc(sizeof(char) * (strlen(argv[1]) + strlen(argv[3]) + 2));
    sprintf(command, "%s %s", argv[1], argv[3]);
  if(fork()==0)
    { 
        output = popen(command, "r");
        if (!output)
        {
        fprintf (stderr,
                "incorrect parameters or too many files.\n");
        return EXIT_FAILURE;
        }
        output = popen(command, "r");
        write_data (output, argv[2]);
        if (pclose (output) != 0)
            {
            fprintf (stderr,
                    "Could not run program.\n");
            return EXIT_FAILURE;
            }
        return EXIT_SUCCESS;
    }
    else
    {
        wait(NULL);
        return EXIT_SUCCESS;
    }
  return 0;
  
}