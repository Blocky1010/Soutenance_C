#include "includes.h"
//utilisiation de quicksort
//création de 5 structure(pointeur sur structur)

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}



/*
*type_lst fonction(*type_lst, *type_lst)

    lst->nb=1
    lst->next=NULL

    lst2->nb = 2
    lst->next=Null

    lst->next=lst2
*/

int main(void){
    int array_int[5] = { 5, 6, 4, 2, 1};
    int i = 0;
    type_lst *lst;
    type_lst *lst2;
    type_lst *lst3;
    type_lst *lst4;
    type_lst *lst5;



    lst = (type_lst *)malloc(sizeof(lst));
    lst2 = (type_lst *)malloc(sizeof(lst2));
    lst3 = (type_lst *)malloc(sizeof(lst3));
    lst4 = (type_lst *)malloc(sizeof(lst4));
    lst5 = (type_lst *)malloc(sizeof(lst5));


    while (i < 5){
        qsort( array_int,5, sizeof(int),cmpfunc);
        printf("%i\n",array_int[i]);
        i ++;
    }

    lst->nbr = array_int[0];
    lst2->nbr = array_int[1];
    lst3->nbr = array_int[2];
    lst4->nbr = array_int[3];
    lst5->nbr = array_int[4];


    lst->next = lst2;
    lst2->next = lst3;
    lst3->next = lst4;
    lst4->next = lst5;
    lst5->next = NULL;
    

    while (lst) {
        printf("le nbr = %i\n", lst->nbr);
        lst = lst->next;
    }
   
}