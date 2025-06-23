#include "myshell.h"

int read_line(char *line[], char *args[], char *outputfile) {
    char *ret = fgets(*line, MAX_CHAR, stdin);
    remove_endOfLine(*line);
    char **commands = split(*line, ">");
    
    ret = process_line(args, line);
    
    if (commands[1] != NULL) {
        strcpy(outputfile, commands[1]);
        remove_spaces(outputfile);
    }
    
    if (strcmp(*line, "exit") == 0 || strcmp(*line, "quit") == 0) {
        return 0;
    }

    if (strcmp(*line, "clr") == 0) {
        system("clear");
        return -1;
    }

    if (strncmp(*line, "cd", 2) == 0) {
        lsh_cd(args);
        return -1;
    }
    
    if (strcmp(args[0], "myshell")==0) {
        char *name;
        strcpy(name, args[1]);
        FILE *bat = popen(name, "w");
        pclose(bat);
        return -1;
    }
    
    if (!strcmp(*line, "environ")) {
        if (list_environ() == 0) {
            return -1;
        } else {
            perror("Simple shell");
        }
    }

    if (!strcmp(args[0], "pause")) {
        getpass("Paused\npress <Enter> key to continue");
        return -1;
    }
    
    if (strcmp(*line, "help") == 0) {
        printf("\nHelp for our <<Simple Shell>>\n i Type a command to run it.\n ii The builtin commands are :\n   1.  ls [optional]       : List files in the current directory or <directory> .\n   2.  dir [optional]      : List files in the current directory or <directory> .\n   3.  myshell <directory> : take command from files.\n   4.  echo <comment>      : Echo the <comment> to standard output.\n   5.  cd <directory>      : change current directory to <directory> . \n   6.  clr                 : clears your screen if this is possible.\n   7.  cat                 : concatenate files and print on the standard output.\n   8.  pwd                 : print name of current/working directory.\n   9.  pause               : wait for signal.\n   10. environ             : List all environment strings. \n   11. help                : run this command , and provide info about shell.\n   12. quit                : Leave Simple Shell.\n   13. exit                : Leave Simple Shell.\n");
        return -1;
    }

    return 1;
}

int main() {
    char *args[MAX_WORD];
    char *line = (char*) malloc((MAX_CHAR+1)*sizeof(char));
    char outputfile[MAX_CHAR];
    int finish = 0;
    char *user = getenv("USER");
    char hostname[1024];
    
    gethostname(hostname, 1024);
    printf("Welcome to Simple Shell\n");
    
    while (!finish) {
        char cwd[1024];
        outputfile[0] = '\0';
        getcwd(cwd, sizeof(cwd));
        
        printf("\n[");
        printf(user);
        printf("@");
        printf(hostname);
        printf("] ");
        printf(" %s $ ", cwd);
        
        int check_line = read_line(&line, args, outputfile);
        
        if (check_line == 0) {
            finish = 1;
            printf("\nLeaving ..\n");
            exit(0);
        } 
        else if (check_line == -1) {
            continue;
        }
        else {
            if (strcmp(line, "") == 0) {
                fprintf(stderr, "shell: Expected command\n");
            }
            else if (strcmp(line, "quit") == 0) {
                exit(0);
            } 
            else {
                pid_t pid;
                int err;
                pid = fork();

                if (pid == -1) {
                    perror("simple shell");
                } 
                else if (pid == 0) {
                    if (outputfile[0] != '\0') {
                        int fd = open(outputfile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
                        dup2(fd, 1);
                        dup2(fd, 2);
                        close(fd);
                    }
                    execvp(args[0], args);
                    perror("execvp failed");
                    exit(1);
                } 
                else {
                    waitpid(pid, &err, 0);
                }
            }
        }
    }
    free(line);
    return 0;
}
