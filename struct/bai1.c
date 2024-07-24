#include <stdio.h>
#include <string.h>
struct Student{
    char name[50];
    char id[10];
    int age;
};
int main(){
    struct Student kv;
    kv.age=4;
    strcpy(kv.name,"kevin");
    strcpy(kv.id,"124");
    printf("age:%d\n",kv.age);
    printf("name:%s\n",kv.name);
    printf("id:%s\n",kv.id);

}