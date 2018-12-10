#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
struct stat st;
char dirvar[50];

void directoryquery(){
  DIR *d;
  struct dirent *dir;
  
  d = opendir(".");
  if (d){
    while ((dir = readdir(d)) != NULL) {
      printf("%s", "FILE NAME: ");
      printf("%s\n", dir->d_name);
      printf("\t%s", "FILE SIZE: ");
      stat(dir->d_name, &st);
      printf("%d\n\n", st.st_size);
    }
    closedir(d);
  }   
}

void controller(char* command){
  char dir[4];
  strcpy(dir, "dir");

  char input[16];
  strcpy(input, command);
  if (strcmp(input,dir) == 0){
    directoryquery();
  }
}

void cd (char* newdirectory){
}

int main (){
  int i;
  DIR *d;
  struct dirent *dir;
  strcpy(dirvar, ".");
  d = opendir(dirvar);
  while(1){
    printf(">");
    char command[16];
    scanf("%s", command);
    controller(command);
  }
  return 0;
}


