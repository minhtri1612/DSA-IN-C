#include <stdio.h>
#include <string.h>
typedef struct{
    char name[50];
    char id[10];
    int age;
}Student;

void print(Student hsinh);
int main(){
    Student kv;
    kv.age=4;
    strcpy(kv.name,"kevin");
    strcpy(kv.id,"124");
    print(kv);
}

void print(Student hsinh){
    printf("age:%d\n",hsinh.age);
    printf("name:%s\n",hsinh.name);
    printf("id:%s\n",hsinh.id);
}
