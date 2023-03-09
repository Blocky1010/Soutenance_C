#include <unistd.h>
#include <stdio.h>

int gd_strlen(char *str){
    int i;
    

    i = 0;
    

    while(str[i] != '\0'){
                
        i++;
    }
    return(i);
}
int gd_putstr(char *str){
    int i;
    i = 
    gd_strlen(str) ;
    write(1, str, i);

}
int main (void){
    int nb_put;
    nb_put = gd_putstr("Coucou");
    printf("%i\n", nb_put);
    return(1);
}
