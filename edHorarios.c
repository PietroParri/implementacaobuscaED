//PIETRO BORGES PARRI GRR20204445

#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include<conio.h>

#define NULL 0

int size=0;

//structs
struct t_time{
int h;
int m;
int s;
};

struct t_timetable{
    struct t_time key;
    struct t_timetable *next;
    char *num;
};struct t_timetable *first,*last;


void main(){
}

int time_cmp(struct t_time h1, struct t_time h2){

    if ((h1.h) > (h2.h)){
        return 1;

    }
    else if ((h2.h) > (h1.h)){
        return -1;
    }
    else if((h1.h) == (h2.h)){

        if(h1.m > h2.m){
            return 1;
        }
        else if(h2.m > h1.m){
            return -1;
        }
        else if(h1.m == h2.m){

            if(h1.s > h2.s){
                return 1;
            }
            else if(h2.s > h1.s){
                return -1;
            }
            else{return 0;}
        }
    }
}

void put(struct t_time key, char * num){

    int n = contains(key);
        if(n == 1){
            struct t_timetable *p;
            p = malloc(sizeof(struct t_timetable));
            p->key = key;
            p->num = num;
            p->next = NULL;

            if(size == 0){
                first=p;
                last=p;
            }
            else{
                last->next = p;
                last = p;
            }
        size++;
        }
}

int contains(struct t_time key){
    struct t_timetable *p;
    int i = 0;
    int aux = 0;
    p = first;

    for(i=0;i<size;i++){

        if (time_cmp( p->key, key) != 0 ){
        aux = 1;
        p = p->next;
        }
            if(aux == 0){
                return 0;
            }else{
                    return 1;
            }
    }

}

