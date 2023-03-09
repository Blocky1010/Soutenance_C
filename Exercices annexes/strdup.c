#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//calculer la taille d une chaine de caractere
int gd_strlen(const char *str){
    int i;
    i = 0;

    while(str[i])           
        i++;
    return(i);
}

// function qui donne la valeur de la place d une variable
char *gd_strdup(const char *src){
    int len_src;

    len_src = gd_strlen(src);
    char *ret = (char*)malloc(sizeof(char) *len_src);

    if (ret == NULL)
        return NULL ;


    len_src = 0;
    while(src[len_src]){
        ret[len_src] = src[len_src];
        len_src++;
    }
    ret[len_src] = '\0';
    return(ret);
}

int main(void){
    char *str = "hello world";
    char *dup;

    dup = gd_strdup(str);
    printf("%s\n",dup);
    free(dup); //liberer la memoire de cette variable
}


    