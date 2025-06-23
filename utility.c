#include "myshell.h"

char **split(char *line, char *delim) {
    int size = 100;
    char **commands = malloc(size * sizeof(char *));
    char *command = NULL;
    int i = 0;
    command = strtok(line, delim);
    
    while (command != NULL) {
        commands[i] = command;
        i++;
        command = strtok(NULL, delim);
    }
    commands[i] = NULL;
    return commands;
}

void remove_spaces(char *s) {
    const char *d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int process_line(char *args[], char *line[]) {
    int i = 0;
    args[i] = strtok(*line, " ");

    if (args[i] == NULL) {
        return 1;
    }

    while (args[i] != NULL) {
        args[++i] = strtok(NULL, " ");
    }

    return 1;
}

void remove_endOfLine(char line[]) {
    int i = 0;
    while (line[i] != '\n')
        i++;
    line[i] = '\0';
}

int list_environ(void) {
    char **env = environ;
    while (*env) fprintf(stdout, "%s\n", *env++);
    return 0;
}

void lsh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "simple shell: expected argument to \"cd\"\n");
    } 
    else {
        if (chdir(args[1]) != 0) {
            perror("simple shell");
        } else {
            printf("the directory has been changed successfully \n");
        }
    }
}
