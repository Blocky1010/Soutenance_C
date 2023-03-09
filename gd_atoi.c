#include <stdio.h>
#include <unistd.h>


/*void gd_putnbr(int nb){
    write(1,&nb,1);
}*/

void gd_putchar(char c){
    write(1, &c, 1);
}

int gd_atoi(char *str){
    int i = 0;
    int ret = 0;
    int neg = 1;
    int nb;

    while (str[i]){
        if (str[i] >= 48 && str[i] <= 57)
            break;
        else if (str[i] == 43 || str[i] == 45)
            break;
        i++;
    }
    if (str[i] == 43 || str[i] == 45){
        if (str[i] == 45)
            neg = -1;
        i++;
    }
    while(str[i]){
        nb = str[i] - 48;
        ret = ret*10 + nb;
        i++;
        printf("%i \n",ret);
    }
    return(ret*neg);

}

int main(void){
    int nb = gd_atoi("-5000");
    printf("%i \n",nb);
    
}
