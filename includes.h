#ifndef INCLUDES_H
#define INCLUDES_H 


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>
#include  <stdlib.h>


void gd_putstr(char *str);
int gd_atoi(char *str);


#define VRAI 1
#define FAUX 0
typedef int BOOLEAN;





typedef struct my_lst {
    int nbr;
    struct my_lst *next;
} type_lst;

#endif
