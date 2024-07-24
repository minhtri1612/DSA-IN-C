#include <stdio.h>
#include <string.h>
typedef struct{
    char name[50];
    char id[10];
    int age;
}Student;

typedef struct Point{
    int x;
    int y;

} Point;

void print(Student hsinh);
int main(){
    Student kv;
    kv.age=4;
    strcpy(kv.name,"kevin");
    strcpy(kv.id,"124");
    print(kv);
    Point p1={3,4};
    Point p2={2,6};
    Point p3={1,5};
    printf("p1.x:%d\n",p1.x);
    printf("p1.y:%d\n",p1.y);

}

void print(Student hsinh){
    printf("age:%d\n",hsinh.age);
    printf("name:%s\n",hsinh.name);
    printf("id:%s\n",hsinh.id);
}
