//
// Created by DB_BOY on 2019/5/22.
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "unistd.h"

//1.基本数据类型
//int short long float double char
/*
int %d
short %d
long %ld
float %f
double %lf
char %c
%x 十六进制
%o 八进制
%s 字符串
*/
void println(char *string) {

    printf("\n%s\n", string);
}

void change(int *p) {
    *p = 300;
}

/**
 *基础练习
 */
void common1() {
    println("1.基本数据类型");
    int i = 1;
    printf("%d\n", i);

    float f = 23.3;
    printf("%f\n", f);

    //基本数据类型所占的字节数
    printf("int占%d字节\n", sizeof(int));
    printf("char占%d字节\n", sizeof(char));
    printf("float占%d字节\n", sizeof(float));

    println("-------循环打印");
    //循环
    int n = 0;
    for (; n < 10; n++) {
        printf("%d\t", n);
    }

    println("2.输入输出函数");
    printf("请输入一个整数：");
    //赋值
    scanf("%d", &i);  //控制台输入，&取地址符
    //打印
    printf("i的值为：%d\n", i);

    println("-------指针");
    i = 90;
    //指针变量，创建一个int类型的指针
    int *p = &i; //p的值就是i这个变量的内存地址
    printf("%#x\n", p);

    f = 89.5f;
    //创建一个float类型的指针
    float *fp = &f;
    printf("%#x\n", fp);


    println("-------变量名，对内存空间上的一段数据的抽象");
    i = 90;
    //创建一个int类型的指针

    *p = &i;
    //输出地址
    printf("p的地址：%#x\n", &p);
    printf("i的地址：%#x\n", &i);

    printf("i的值为：%d\n", i);
    //间接赋值 i = 200;

    //对p存的地址指向的变量进行操作
    //*p = 200;
    change(&i);  // int *p = &i;
    printf("change赋值。i的值为：%d\n", i);

    println("-------模拟游戏");
    int time = 6;
    printf("time:%#x\n", &time);
    while (time > 0) {
        time--;
        printf("游戏时间剩余%d秒\n", time);
        //睡眠
        sleep(1);
    }
}


//------------------------------------------------------------------------------

int msg(char *msg, char *title) {
//    MessageBox(0, msg, title, 0);
    printf("%s, %s\n", msg, title);
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

//int div(int a, int b) {
//    return a - b;
//}

void msg1(int(*func_p)(int a, int b), int m, int n) {
    printf("执行一段代码...\n");
    printf("执行回调函数...\n");
    int r = func_p(m, n);
    printf("执行结果：%d\n", r);
}

//案例：用随机数生成一个数组，写一个函数查找最小的值，并返回最小数的地址，在主函数中打印出来
int *getMinPointer(int ids[], int len) {
    printf("len: %d\n", len);
    int i = 0;
    int *p = &ids[0];
    for (; i < len; i++) {
        printf("%d,%d \t", ids[i], *p);
        if (ids[i] < *p) {
            p = &ids[i];
        }
    }
    return p;
}


/**
 * 指针练习
 */
void pointer() {

    println("1. 指针基本练习");
    int i = 89;
    int *p = &i;
    double j = 78.9;
    //赋值为double类型变量的地址
    p = &j;
    printf("double size:%d\n", sizeof(double));
    printf("%#x,%lf\n", p, *p); //想通过4字节读取8字节变量的值，是不行的

    println("2.NULL空指针");
    *p = NULL;

    //空指针的默认值为0
    printf("空指针地址 %#x\n", p);
    //访问内存地址0x000000操作系统不允许
    //操作系统不允许访问
    printf("%d\n", *p);

    println("3.多级指针（二级指针）");
//指针保存的是变量的地址，保存的这个变量还可以是一个指针变量
//动态内存分配给二维数组
    int a = 50;
    //p1上保存的a的地址
    int *p1 = &a;

    //p2上保存的p1的地址
    int **p2 = &p1;

    //int*** p3 = &p2;

    printf("&a:%#x, p1:%#x , p2:%#x\n", &a, p1, p2);
    printf("a:%d, *p1:%d , **p2:%d\n", a, *p1, **p2);

    println("通过指针改变a， **p2 = 90; ");
    **p2 = 90;

    printf("%d\n", a);

    println("4.指针的运算");
    //指针的运算，一般在数组遍历时才有意义，基于数组在内存中线性排列的方式
    //数组在内存中连续存储
    int ids[] = {78, 90, 23, 65, 19};
    //数组变量名：ids就是数组的首地址
    printf("ids %#x\n", ids);
    printf("&ids %#x\n", &ids);
    printf("&ids[0] %#x\n", &ids[0]);
    printf("指针变量");
    *p = ids;
    printf("*p： %d\n", *p);

    printf("指针的加法");
    p++; //p++向前移动sizeof(数据类型)个字节
    printf("p的值:%#x\n", p);
    //p--;
    printf("%d\n", *p);


    println("5.通过指针给数组赋值");
    int uids[5];
    //高级写法
    //int
    i = 0;
    for (; i < 5; i++) {
        uids[i] = i;
        printf(": %d\n", uids[i]);
    }
    //早些版本的写法
//    *p = uids;
//    printf("p: %#x\n", p);
//    i = 0; //i是数组元素的值
//    for (; p < uids + 5; p++,i++) {
//        *p = i;
//        i++;
//        printf("*p: %#x\n", *p);
//    }

    println("6.函数指针");
    //msg();
    printf("msg: %#x\n", msg);
    printf("&msg %#x\n", &msg);
    //函数指针
    //函数返回值类型，函数指针的名称，函数的参数列表
    int (*fun_p)(char *msg, char *title) = msg;
    fun_p("消息内容", "标题");



//msg函数需要传递一个函数指针参数
//类似于我们Java中的回调函数


    //加法
    //int(*func_p)(int a, int b) = add;
    msg1(add, 30, 20);
//    减法
    msg1(minus, 50, 10);
    ids[10];
    i = 0;
    //初始化随机数发生器，设置种子，种子不一样，随机数才不一样
    //当前时间作为种子 有符号 int -xx - > +xx
    srand((unsigned) time(NULL));
    for (; i < 10; i++) {
        //100范围内
        ids[i] = rand() % 100;
        printf("%d\t", ids[i]);
    }
    printf("\n");

    p = getMinPointer(ids, sizeof(ids) / sizeof(int));
    printf("%#x , %d\n", p, *p);
}

//------------------------------------------------------
/**
 * 结构体，字符串
 */
void malloc_str() {

//    int *p = malloc(1024 * 1024 * 10 * sizeof(int));
//    free(p);

    int len = 5;

    int *p = malloc(len * sizeof(int));// * sizeof(int));
    srand((unsigned) time(NULL));
    int i = 0;
    for (; i < len; i++) {
        p[i] = rand() % 100;
        printf("p%d: %d ,%#x ,\n", i + 1, p[i], &p[i]);
    }
    free(p);

    println("---");
//     i = 0;
//    p = realloc(p,sizeof(int));
//    for (; i < len+10 ; i++) {
//        p[i] = rand() % 100;
//        printf("p%d: %d ,%#x ,\n", i + 1, p[i], &p[i]);
//    }
//    free(p);

    p = NULL;

    println("---");
    p = calloc(len, sizeof(int));
    i = 0;
    for (; i < len + 10; i++) {
        p[i] = rand() % 100;
        printf("p%d: %d ,%#x ,\n", i + 1, p[i], &p[i]);
    }
    free(p);

    //字符数组可以被修改
    println("---------字符串练习---------");
    println("---------字符串练习---------");
    char str[] = {'h', 'e', 'l', 'l', 'o'};
    printf("%s \n", str);
    str[0] = 'd';
    printf("%s \n", str);

    char *str1 = "hello, world";
    printf("%s \n", str1);
/*

    //字符指针不能修改
    str1[0] = 'q';
    printf("%s \n",str1);

    //字符指针不能修改
    str1 +=1;
    *str1 = 'y';
    printf("%s \n",str1);

*/


    //指针加法，截取字符串

    str1 += 2;
    while (*str1) {
        printf("%c", *str1);
        str1++;
    }
    println("");

//    string.h
    char dest[50];
    char *a = "--hello,";
    char *b = " world--";
    strcpy(dest, a);
    printf("%s \n", dest);
    strcpy(dest, b);
    printf("%s \n", dest);


    a = "find string";
    char *index = strchr(a, 'd');
    if (index) {
        printf("index:  %d\n", (index - a));
    }

    //查找字符串
    index = strstr(a, "ing");
    if (index) {
        printf("index:  %d\n", (index - a));
    }
}


//------------------------------
//----------结构体---------------
//------------------------------

typedef struct people {
    char *name;
    int age;

};

void struct_t() {

    //声明赋值
    struct people p = {"db_boy",18};
    printf("%s,%d \n",p.name,p.age);

    //先声明后赋值
    struct people p1;
    p1.name= "db_boy_gin";
    p1.age = 19;

    printf("%s,%d \n",p1.name,p1.age);

}


