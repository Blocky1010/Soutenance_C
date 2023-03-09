#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int gd_double_strlen(const char *s1, const char *s2){
    int i;
    int len;
    int j;

    i = 0;
    j = 0;

    while(s1[i])         
        i++;
    
    while(s2[j])
        j++;
    

    len = (i + j);

    return(len);
}


char *join_to_string(char const *s1, char const *s2){
    int len_total;
    int p;
    
    len_total = gd_double_strlen(s1, s2);
    char *ret = (char*)malloc(sizeof(char) *len_total+1);

    if (ret == NULL)
        return NULL;
    ret[len_total+1] = '\0';
    len_total = 0;
    while(s1[len_total]){
        ret[len_total] = s1[len_total];
        len_total++;
    }
    p = 0;
    while(s2[p]){
        ret[len_total] = s2[p];
        p++;
        len_total++;
    }

    return(ret);
}

int main(void){
    char *s1 = "hello";
    char *s2 = "world";
    char *dub;

    dub = join_to_string(s1, s2);
    printf("%s\n",dub);
    free(dub);

}