
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <fcntl.h>
#define _BSD_SOURCE  1
#define _SVID_SOURCE 1
#define MAX_LINE 100
#define MAX_PATH 2000
// various colors for our use
#define COLOR_YELLO "\x1B[33m"
#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1b[92m"
#define COLOR_BLUE "\x1b[94m"
#define COLOR_DEF "\x1B[0m"
#define COLOR_CYAN "\x1b[96m"
// global variables
char *input;
char *foruse;
char *foruse1;
char *arg[20];
char direc_name[MAX_PATH];
int flag=0;
int agruments;
int doinbackground;


/// This file basically contains all the imports which are necessary
