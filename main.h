#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF 100

extern char **environ;

char *_memset(char *s, char b, unsigned int n);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *, const char *, size_t);
char *_strtok(char *, const char *);
char *_strdup(const char *);
int _strcmp(const char *, const char *);
char *_strcpy(char *, const char *);
char *_strcat(char *, char *);
size_t _strlen(const char *);
char *searchfile(char **, char *);
char *_getenv(char **, const char *);
int _setenv(char **, const char *, const char *, int);
int check_env(char **, char *, int, const char *);
int _unsetenv(char **, const char *);
int split_args(char **, char **, int);
int exe_command(char **, char **, char *, int *);
int handle_args(char **, char **, char *, int *, int *);
int get_token(char **, char *, char *, int *);
int handle_and(char **, char **, char *, int *);
int handle_or(char **, char **, char *, int *, int *);
int prompt(char **, char *, int *);
int handle_cd(char **, char **);
void *_realloc(void *, unsigned int, unsigned int);
ssize_t _getline(char **, size_t *, FILE *);
void _setcwd(char **, char *);
int base_conv(char *, long, int);
void rev_string(char *);
void handle_err(char **, const char *, const char *);
int ret_stat(int *, int *);
void handle_env(char **);
void handle_exit(char **, char **, int *);


#endif /*MAIN_H*/
