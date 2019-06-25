//
// Created by DB_BOY on 2019/6/14.
// 联合体
//
#include "c_2.h"

//联合体（共用体）
//不同类型的变量共同占用一段内存（相互覆盖），联合变量任何时刻只有一个成员存在，节省内存
//联合体变量的大小=最大的成员所占的字节数
union values {
    int x;
    int y;
    double z;
};

void union_test() {
    union values v;
    v.x = 90;
    v.y = 20;
    v.z =23.222;
    printf("%d,%d,%lf\n",v.x,v.y,v.z);

}


//枚举是一种限定值，保证取值安全性
enum week{
	Monday ,// 0,
	Tuesday ,// 1,
	Wednesday ,// 2,
	Thursday ,// 3,
	Friday ,// 4,
	Saturday ,// 5,
	Sunday ,// 6
};

void enum_test(){
    enum week w = Monday;
    printf("%#x, %d\n",&w,w);
}



