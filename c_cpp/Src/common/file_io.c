//
// Created by DB_BOY on 2019/6/14.
//

#include "file_io.h"
#include "base.h"

void readFile() {
    printf("-----------------readFile\n");

    char *path = "test.txt";//注意路径

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("失败");
        return;
    }
    char buff[40];
    while (fgets(buff, 40, fp)) {
        printf("%s", buff);
    }
    fclose(fp);
}

/**
 * w 写
 * r 读
 * a 追加
 *
 * wb 写二进制文件
 */
void writeFile() {

    printf("\n-----------------writeFile\n");
    char *path = "test.txt";
    FILE *fp = fopen(path, "w");
    char *text = "测试测试测试测试测试测试测试\r\n测试测试测试";
    fputs(text, fp);
    fclose(fp);

    path = "test.txt";
    fp = fopen(path, "a+");
    text = "\n--------\n--------追加追加追加追加追加追加追加追加追加追加追加\r\n测试测试测试";
    fputs(text, fp);
    fclose(fp);
}

void writeBFile() {
    printf("-----------------writeBFile\n");
    char *path = "girl.png";
    char *path1 = "girl1.png";
    FILE *read_fp = fopen(path, "rb");
    FILE *write_fp = fopen(path1, "wb");

    int buff[30];
    int len = 0;
    while (len = (fread(buff, sizeof(int), 30, read_fp)) != 0) {

        fwrite(buff, sizeof(int), len, write_fp);
    }
    fclose(read_fp);
    fclose(write_fp);
}

void getFileSize() {
    printf("-----------------getFileSize\n");

    char *path = "girl.png";
    FILE *fp = fopen(path, "r");

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    printf("%d", filesize);
}