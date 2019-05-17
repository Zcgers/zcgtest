//
//  学生管理系统.c
//  算法程序
//
//  Created by 朱晨光 on 2019/5/17.
//  Copyright © 2019 朱晨光. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<coion.h>
#include<Windows.h>


typedef struct student {
    char name[20];
    double chinese;
    double english;
    double math;
    double sum;
    char number[20];
    char cla[20];
    struct student *next;
}STU;

typedef struct studentac {
    char name[20];
    char sex[10];
    char zh[10];
    char mm[10];
    struct studentac *next;
}STUAC;

typedef struct teachar {
    char name[20];
    char sex[20];
    char zh[20];
    char mm[20];
    char kemu[20];
    struct teacher *next;
}TEA;

STUAC * readac();
void creatstuac();
void saveac(STUAC *head);
void stulog(STUAC *head);
void student();
void creattea();
void tealog(TEA *head);
void savetea(TEA *head);
void teacher();
TEA *readtea();
void add();
void change(STU *head);
void del(STU *head);
void jiaoshizi(char s[]);
void printfstu(STU *head);
void printtea();
STU * readstu();
void savestu(STU*p, STU *head);
void search(STU *head);
void sortstu(STU *head);
void stuzi(char s[],STUAC *headss);
void zhaohui(STUAC *head);
void printlb(STU *head);


void teacher() {
    while (1) {
        char s;
        char k;
        system("cls");
        char ch[100];
        TEA *teahead = NULL;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t********************************\n\n");
        printf("\t\t\t\t\t 教师端 \t\t\t\t\t\n\n");
        printf("\t\t\t\t--------------------------------\t\t\t\t\n\n");
        printf("\t\t\t\t*\t1 教师注册\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t*\t2.教师登陆\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t*\t3.返回主界面\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t********************************\t\t\t\t\n\n");
        printf("\t\t\t\t请根据界面选择1/2/3选项\t\t\t\t\n\n");
        
        scanf("%s", ch);
        if (strlen(ch) != 1) {
            printf("Error");
            printf("输入错误请检查输入......\n按回车键返回......\n");
            s = getch();
            printf("请稍后......");
            Sleep(1000);
        }
        else {
            k = ch[0];
            switch (k)
            {
                case '1':creattea();
                    break;
                case '2':teahead = readtea();
                    if (teahead != NULL)
                        tealog(teahead);
                    break;
                case '3':return;
                    
                default:
                    
                    printf("输入错误请检查输入......\n按回车键返回......\n");
                    s = getch();
                    printf("\n请稍后....");
                    Sleep(1000);
            }
        }
    }
}
void creattea() {
    system("cls");
    FILE *fp;
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        if (fp = fopen("教师账号.txt", "r") == NULL) {
            fp = fopen("教师账号.txt", "w");
            TEA *head, *p = NULL;//创建头尾指针
            head = (TEA *)malloc(sizeof(TEA));
            p = head;
            int i = 0;
            printf("\n\n\n\n\n");
            
            while (1) {
                printf("\t\n*请输入教师姓名:");
                scanf("%s", p->name);
                getchar();
                for (i = 0; i < strlen(p->name); i++) {
                    if ((p->name[i]) >= '0' && (p->name[i]) <= '9') {
                        printf("姓名不能带有数字.....");
                        printf("请按任意键继续......");
                        getch();
                        break;
                    }
                    
                }
                if (i == strlen(p->name)) {
                    break;
                }
            }
            printf("\n\t*请输入性别:");
            scanf("%s", p->sex);
            getchar();
            printf("\n\t*请输入登陆用户名:");
            scanf("%s", p->zh);
            getchar();
            
            
            
            printf("\n\t*请输入登陆密码:");
            int n = 0;
            char ch;
            while ((ch = getch()) != '\r') {
                if (ch == '\b'&& n > 0) {
                    printf("\b \b");
                    n--;
                }
                else if (ch != '\b') {
                    p->mm[n++] = ch;
                    printf("*");
                }
            }
            p->mm[n] = '\0';
            p->next = NULL;
            fclose(fp);
            savetea(head);
            printf("\t*恭喜您！ 注册成功！\n");
            printf("按任意键返回");
            getch();
            return;
        }
        else {
            TEA *head;
            head = readtea();
            TEA*p, *q = NULL;
            p = head;
            while (p != NULL) {
                q = p;
                p = p->next;
            }
            p = (TEA*)malloc(sizeof(TEA));
            int i = 0;
            printf("\n\n\n\n\n");
            
            while (1) {
                printf("\t\n*请输入教师姓名:");
                scanf("%s", p->name);
                getchar();
                for (i = 0; i < strlen(p->name); i++) {
                    if ((p->name[i]) >= '0' && (p->name[i]) <= '9') {
                        printf("\n姓名不能带有数字.....");
                        printf("\n请按任意键继续......");
                        getch();
                        break;
                    }
                    
                }
                if (i == strlen(p->name)) {
                    break;
                }
            }
            printf("*请输入教师性别:");
            scanf("%s", p->sex);
            getchar();
            printf("*请输入执教科目:");
            scanf("%s", p->kemu);
            getchar();
            printf("*请输入登陆用户名:");
            scanf("%s", p->zh);
            getchar();
            printf("*请输入登录密码:");
            int n = 0;
            char ch;
            while ((ch = getch()) != '\r') {
                if (ch == '\b' && n > 0) {
                    printf("\b \b");
                    n--;
                }
                else if (ch != '\b') {
                    p->mm[n++] = ch;
                    printf("*");
                }
            }
            p->mm[n] = '\0';
            q->next = p;
            p->next = NULL;
            savetea(head);
            printf("\n恭喜您注册成功！！！\n");
            printf("按任意键返回......\n");
            getch();
            return;
        }
    }
}
void savetea(TEA*head) {
    FILE *fp;//文件指针，打开文件
    fp = fopen("教师账号.txt", "w");
    TEA*p;//头指针
    p = head;
    while (p != NULL) {
        fwrite(p, sizeof(TEA), 1, fp);//写入
        p = p->next;
    }
    fclose(fp);//关闭
}
void tealog(TEA*head) {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t*********教师登陆页面*********");
        char zh[20];
        char mm[20];
        printf("\n\n\t\t\t\t\t请输入登陆用户名：");
        scanf("%s", zh);
        getchar();
        printf("\n\t\t\t\t\t请输入密码：");
        int n = 0;
        char ch;
        while ((ch = getch()) != '\r') {
            if (ch == '\b' && n > 0) {
                printf("\b \b");
                n--;
            }
            else if (ch != '\b') {
                mm[n++] = ch;
                printf("*");
            }
        }
        mm[n] = '\0';
        TEA *p;
        p = head;
        while (p != NULL) {
            if (strcmp(zh, p->zh) == 0 && strcmp(mm, p->mm) == 0) {
                printf("\n\t\t\t\t\t登陆成功......\n");
                printf("\t\t\t\t\t正在进入教师管理界面，请稍等......");
                Sleep(1000);
                jiaoshizi(p->name);
                break;
            }
            else {
                p = p->next;
            }
        }
        if (p == NULL) {
            printf("\n\t\t\t登陆失败！\n");
            printf("\t\t\t账号或密码错误，或未注册账号......\n");
            printf("\t\t\t按任意键返回......\n");
            getch();
            return;
        }
    }
}
void jiaoshizi(char s[]) {
    while (1) {
        system("cls");
        STU *head = NULL;
        char ch;
        printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
        if ((ch = getch()) != '\r') {
            return;
        }
        if ((ch = getch()) == '\r') {
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t******************************\n");
            printf("\t\t\t\t\t*\t%s老师欢迎你！   *\n", s);
            printf("\t\t\t\t\t\t*---------------*\n");
            printf("\t\t\t\t\t*\t1.添加学生           *\n");
            printf("\t\t\t\t\t*\t2.删除学生           *\n");
            printf("\t\t\t\t\t*\t3.修改学生信息学生   *\n");
            printf("\t\t\t\t\t*\t4.查找学生           *\n");
            printf("\t\t\t\t\t*\t5.查看学生信息       *\n");
            printf("\t\t\t\t\t*\t6.排序学生           *\n");
            printf("\t\t\t\t\t*\t7.查看教师信息       *\n");
            printf("\t\t\t\t\t*\t8.找回学生密码           *\n");
            printf("\t\t\t\t\t*\t9.退出登陆           *\n");
            printf("\t\t\t\t\t******************************\n");
            printf("\t请你选择你想要进行的操作：");
            char ch[100];
            char d;
            scanf("%s", ch);
            if (strlen(ch) != 1) {
                printf("Error");
                printf("输入错误请检查输入......\n按回车键返回......\n");
                d = getch();
                printf("\n请稍后....");
                Sleep(1000);
            }
            else {
                char k = ch[0];
                switch (k) {
                    case '1': {
                        add();
                        break;
                    }
                    case '2': {
                        head = readstu();
                        if (head != NULL) {
                            del(head);//删除函数
                            break;
                        }
                    }
                    case '3': {
                        head = readstu();
                        if (head != NULL) {
                            change(head);//改变函数
                            break;
                        }
                    }
                    case '4': {
                        head = readstu();
                        if (head != NULL) {
                            search(head);
                            break;
                        }
                    }
                    case '5': {
                        head = readstu();
                        if (head != NULL) {
                            printfstu(head);
                            break;
                        }
                    }
                    case '6': {
                        head = readstu();
                        if (head != NULL) {
                            sortstu(head);
                            break;
                        }
                    }
                    case '7': {
                        printtea(head);
                        break;
                    }
                    case '8': {
                        head = readac();
                        if (head != NULL) {
                            zhaohui(head);
                            break;
                        }
                    }
                    case '9': return;
                        
                    default:
                        
                        printf("输入错误请检查输入......\n按回车键返回......\n");
                        d = getch();
                        printf("\n请稍后....");
                        Sleep(1000);
                }
            }
        }
    }
}
void printtea() {
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        system("cls");
        printf("*******教师信息*******\n");
        printf("教师姓名 性别 执教科目\n");
        TEA *head;
        head = readtea();
        while (head != NULL) {
            printf("%s %s %s\n", head->name, head->sex, head->kemu);
            head = head->next;
        }
        printf("请按任意键返回.....");
        getch();
        return;
    }
}
TEA *readtea() {
    FILE *fp;
    fp = fopen("教师账号.txt", "r");
    rewind(fp);
    TEA *head, *p, *q = NULL;
    head = (TEA *)malloc(sizeof(TEA));
    q = p = head;
    while (!feof(fp)) {
        if (fread(p, sizeof(TEA), 1, fp) != 1)
            break;
        p->next = (TEA*)malloc(sizeof(TEA));
        q = p;
        p = p->next;
    }
    free(p);
    q->next = NULL;
    fclose(fp);
    return head;
}

void student() {
    while (1) {
        system("cls");
        char ch[100];
        char s;
        STUAC*stuachead = NULL;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t********************************\n\n");
        printf("\t\t\t\t\t 学生端 \t\t\t\t\t\n\n");
        printf("\t\t\t\t--------------------------------\t\t\t\t\n\n");
        printf("\t\t\t\t*\t1.学生注册\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t*\t2.学生登陆\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t*\t3.返回主界面\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t********************************\t\t\t\t\n\n");
        printf("\t\t\t\t请根据界面选择1/2/3选项\t\t\t\t\n\n");
        
        scanf("%s", ch);
        if (strlen(ch) != 1) {
            printf("Error");
            printf("输入错误请检查输入......\n按回车键返回......\n");
            s = getch();
            printf("请等待.......");
            Sleep(1000);
        }
        else {
            char k = ch[0];
            switch (k)
            {
                case '1':creatstuac();
                    break;
                case '2':stuachead = readac();
                    if (stuachead != NULL)
                        stulog(stuachead);
                    break;
                case '3':return;
                default:
                    
                    printf("输入错误请检查输入......\n按回车键返回......\n");
                    s = getch();
                    printf("\n请稍后....");
                    Sleep(1000);
            }
        }
    }
}
void creatstuac()
{
    system("cls");
    FILE *fp;
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        if (fp = fopen("学生账号.txt", "r") == NULL) {
            fp = fopen("学生账号.txt", "w");
            STUAC *head,*p1, *p = NULL;
            head = (STUAC *)malloc(sizeof(STUAC));
            p = head;
            p1 = head;
            int i = 0;
            printf("\n\n\n\n\n");
            while (1) {
                printf("\t\n*请输入学生姓名:");
                scanf("%s", p->name);
                getchar();
                for (i = 0; i < strlen(p->name); i++) {
                    if ((p->name[i]) >= '0' && (p->name[i]) <= '9') {
                        printf("姓名不能带有数字.....");
                        printf("请按任意键继续......");
                        getch();
                        break;
                    }
                    
                }
                if (i == strlen(p->name)) {
                    break;
                }
                
            }
            printf("\n*请输入性别：\n");
            scanf("%s", p->sex);
            getchar();
            char f[20];
            
            while (1) {
                int c = 0;
                printf("*请输入账号：");
                scanf("%s", f);
                getchar();
                while (p1 != NULL) {
                    if (strcmp(f, p1->zh) == 0) {
                        printf("账号已被注册，请重试.....\n");
                        c++;
                        break;
                    }
                    else {
                        p1 = p1->next;
                    }
                }
                
                if (c == 0) {
                    //gets(p->zh);
                    strcpy(p->zh, f);
                    break;
                }
            }
            printf("*请输入登陆密码：\n");
            int n = 0;
            char ch;
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b' && n > 0)
                {
                    printf("\b \b");   // 空格+\b 是为了覆盖掉原来的字符
                    n--;
                }
                else if (ch != '\b')
                {
                    p->mm[n++] = ch;
                    printf("*");
                }
            }
            p->mm[n] = '\0';
            p->next = NULL;
            fclose(fp);
            saveac(head);
            printf("\n恭喜您！注册成功！\n");
            printf("按任意键返回......");
            getch();
            return;
        }
        else
        {
            STUAC *head;
            head = readac();
            STUAC *p,*p1, *q = NULL;
            p = head;
            p1 = head;
            while (p != NULL)
            {
                q = p;
                p = p->next;
            }
            p = (STUAC *)malloc(sizeof(STUAC));
            //p1 = (STUAC *)malloc(sizeof(STUAC));
            printf("\n\n\n\n\n");
            int i = 0;
            while (1) {
                printf("\n*请输入学生姓名:");
                scanf("%s", p->name);
                getchar();
                for (i = 0; i < strlen(p->name); i++) {
                    if ((p->name[i]) >= '0' && (p->name[i]) <= '9') {
                        printf("\n姓名不能带有数字.....");
                        printf("\n请按任意键继续......");
                        getch();
                        break;
                    }
                    
                }
                if (i == strlen(p->name)) {
                    break;
                }
            }
            printf("*请输入性别：");
            scanf("%s", p->sex);
            getchar();
            
            char f[20];
            
            while (1) {
                int c = 0;
                printf("*请输入账号：");
                scanf("%s", f);
                getchar();
                while (p1 != NULL) {
                    if (strcmp(f, p1->zh) == 0) {
                        printf("账号已被注册，请重试.....\n");
                        c++;
                        break;
                    }
                    else {
                        p1 = p1->next;
                    }
                }
                
                if (c == 0) {
                    strcpy(p->zh,f);
                    //gets(p1->zh);
                    break;
                }
            }
            printf("*请输入登陆密码：");
            int n = 0;
            char ch;
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b' && n > 0)
                {
                    printf("\b \b");   // 空格+\b 是为了覆盖掉原来的字符
                    n--;
                }
                else if (ch != '\b')
                {
                    p->mm[n++] = ch;
                    printf("*");
                }
            }
            p->mm[n] = '\0';
            q->next = p;
            p->next = NULL;
            saveac(head);
            printf("\n恭喜您！注册成功！\n");
            printf("按任意键返回......");
            getch();
            return;
        }
    }
}
void mmxg(char s[],STUAC *head) {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        printf("\n\n\n\n\n");
        printf("\t\t\t\t***********%s同学你好！***********\n\n\n\n", s);
        STUAC *head = readac();
        STUAC *p = head;
        char mm1[20];
        char u[20];
        printf("\t\t\t\t\t请输入您原来的密码：");
        
        scanf("%s", mm1);
        getchar();
        while (p != NULL) {
            if (strcmp(s, p->name) == 0 && strcmp(mm1, p->mm) == 0) {
                printf("\t\t\t\t\t请输入您修改后的密码：");
                scanf("%s", u);
                getchar();
                strcpy(p->mm, u);
                saveac(head);
                printf("\t\t\t\t\t修改成功.....");
                printf("\t\t\t\t\t请稍等");
                Sleep(1000);
                return;
            }
            else {
                p = p->next;
            }
        }
        
        if (p == NULL) {
            printf("\t\t\t\t\t错误......");
            return;
        }
        
        return;
    }
}
void savestu(STU*p, STU*head) {
    FILE *fp;
    fp = fopen("class1.txt", "a+");
    STU*p1 = (STU*)malloc(sizeof(STU));
    p1 = head;
    while (1) {
        p1 = p1->next;
        if (p1->next == NULL) {
            break;
        }
    }
    p1->next = p;
    p->next = NULL;
    fprintf(fp, "%s %s %s %lf %lf %lf", p->name, p->number, p->cla, p->chinese, p->math, p->english);
    fclose(fp);
}
void saveac(STUAC*head) {
    FILE *fp;
    fp = fopen("学生账号.txt", "w");
    STUAC *p, *q;
    p = head;
    while (p != NULL)
    {
        fwrite(p, sizeof(STUAC), 1, fp);
        p = p->next;
    }
    fclose(fp);
    
    
}

void stulog(STUAC*head) {
    system("cls");
    char w;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((w = getch()) != '\r') {
        return;
    }
    if ((w = getch()) == '\r') {
        printf("\n\n\n\n\n");
        printf("\t\t\t\t**********学生登陆页面**********\n\n");
        printf("\t\t\t\t--------------------------------\n\n");
        char zh[20];
        char mm[20];
        printf("\t\t\t\t请输入用户名：");
        scanf("%s", zh);
        getchar();
        printf("\t\t\t\t请输入密码：");
        int n = 0;
        char ch;
        while ((ch = getch()) != '\r') {
            if (ch == '\b' && n > 0) {
                printf("\b \b");
                n--;
            }
            else if (ch != '\b') {
                mm[n++] = ch;
                printf("*");
            }
        }
        mm[n] = '\0';
        STUAC *p;
        p = head;
        while (p != NULL) {
            if (strcmp(zh, p->zh) == 0 && strcmp(mm, p->mm) == 0) {
                printf("\n\t\t\t\t登陆成功.....\n");
                printf("\t\t\t\t正在进入学生管理界面....\n");
                Sleep(1000);
                
                stuzi(p->name,head);
                break;
            }
            else {
                p = p->next;
            }
            /*if (strcmp(mm, p->mm) != 0) {
             printf("\n\t\t\t\t密码不对.....\n");
             Sleep(2000);
             return;
             }*/
            
            
        }
        if (p == NULL) {
            printf("\n\t\t\t登陆失败!\n");
            printf("\t\t\t账号或密码错误，或未注册账号....");
            printf("\t\t\t请按任意键返回.....");
            getch();
            return;
        }
    }
}
STU *readstu() {
    
    int i;
    
    char ch;
    
    FILE *fp;
    
    fp = fopen("class1.txt", "r+");
    
    STU *phead = (STU*)malloc(sizeof(STU));
    
    
    
    
    STU *p = phead;
    
    if (fp == NULL) {
        
        printf("error\n");
        
        getch();
        
    }
    else {
        
        
        
        while (!feof(fp)) {
            
            STU *pnew = (STU*)malloc(sizeof(STU));
            
            fscanf(fp, "%s", pnew->name);
            
            fgetc(fp);
            
            fscanf(fp, "%s", pnew->number);
            
            fgetc(fp);
            
            fscanf(fp, "%s", pnew->cla);
            
            fgetc(fp);
            
            fscanf(fp, "%lf", &pnew->chinese);
            
            
            fscanf(fp, "%lf", &pnew->math);
            
            fscanf(fp, "%lf", &pnew->english);
            
            pnew->sum = pnew->chinese + pnew->math + pnew->english;
            
            
            pnew->next = NULL;
            
            p->next = pnew;
            
            p = pnew;
            
        }
        
    }
    
    fclose(fp);
    
    return phead->next;
}
STUAC *readac() {
    FILE *fp;
    fp = fopen("学生账号.txt", "r");
    STUAC *head, *p, *q = NULL;
    head = (STUAC*)malloc(sizeof(STUAC));
    p = q = head;
    while (!feof(fp)) {
        if (fread(p, sizeof(STUAC), 1, fp) != 1)
            break;
        p->next = (STUAC*)malloc(sizeof(STUAC));
        q = p;
        p = q->next;
    }
    free(p);
    q->next = NULL;
    fclose(fp);
    return head;
    
}
void printfstu(STU *head) {
    system("cls");
    char ch;
    STU* p;
    int count = 0;
    p = head;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        char cla[20];
        if (p == NULL) {
            printf("输入班级错误......\n");
            printf("按任意键返回...");
            getch();
            return;
        }
        
        printf("请输入你想要查询的班级：");
        scanf("%s", cla);
        getchar();
        printf("\t\t学生姓名 学生学号 班级 语文成绩 数学成绩 英语成绩 总分\n");
        while (p != NULL) {
            if (strcmp(cla, p->cla) == 0) {
                printf("\t\t%-8s %-8s %-8s %-8.3lf %-8.3lf %-8.3lf %8lf\n", p->name, p->number, p->cla, p->chinese, p->math, p->english, p->sum);
                count++;
                p = p->next;
            }
            else {
                p = p->next;
            }
        }
        printf("共计%d个同学", count);
        printf("请按任意键返回.....");
        getch();
        return;
    }
}
void stuzi(char y[],STUAC *headss) {
    system("cls");
    STUAC *heads = headss;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    char w;
    if ((w = getch()) != '\r') {
        return;
    }
    if ((w = getch()) == '\r') {
        while (1) {
            STUAC *head = NULL;
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t***********%s同学你好！***********\n\n\n\n", y);
            
            char ch[100];
            char k;
            char s;
            printf("\t\t\t\t\t1.查看成绩\n");
            printf("\t\t\t\t\t2.密码修改\n");
            printf("\t\t\t\t\t3.退出登陆\n");
            
            printf("\n\t\t\t\t\t请输入选择：");
            scanf("%s", ch);
            if (strlen(ch) != 1) {
                printf("Error");
                printf("输入错误请检查输入......\n按回车键返回......\n");
                s = getch();
                printf("请等待.......");
                Sleep(1000);
            }
            else {
                char k = ch[0];
                switch (k)
                {
                    case '1': {
                        system("cls");
                        STU *head, *p;
                        char number[20];
                        printf("请输入学号：");
                        scanf("%s", number);
                        getchar();
                        head = readstu();
                        p = head;
                        while (p != NULL) {
                            if (strcmp(number, p->number) == 0 && strcmp(y, p->name) == 0) {
                                printf("\n\n学生学号:%-8s \t\t\n\n语文成绩:%-8.3lf \t\t\n数学成绩:%-8.3lf \t\t\n英语成绩:%-8.3lf \t\t\n总分:%-8.3lf", p->number, p->chinese, p->math, p->english, p->sum);
                                printf("按任意键返回......");
                                getch();
                                break;
                            }
                            else {
                                p = p->next;
                            }
                        }
                        if (p == NULL) {
                            printf("查询失败\n");
                            printf("该学号不存在....");
                            printf("按任意键返回.....");
                            getch();
                        }
                        break;
                    }
                    case '2':mmxg(y,heads);
                        break;
                    case '3': return;
                        
                    default:
                        
                        printf("输入错误请检查输入......\n按回车键返回......\n");
                        s = getch();
                        printf("\n请稍后....");
                        Sleep(1000);
                }
            }
        }
    }
}
//教师实现对学生的增添该查功能*******
void del(STU *head) {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        FILE *fp;
        system("cls");
        char name[20];
        char number[20];
        STU *p = head;
        STU *ptemp = (STU*)malloc(sizeof(STU));
        ptemp = head;
        printf("\n\n\n\n\n");
        while (1) {
            printf("\t\n*请输入学生姓名:");
            scanf("%s", name);
            getchar();
            int i;
            for (i = 0; i < strlen(name); i++) {
                if ((name[i]) >= '0' && (name[i]) <= '9') {
                    printf("\n姓名不能带有数字.....");
                    printf("\n请按任意键继续......");
                    getch();
                    break;
                }
                
            }
            if (i == strlen(name)) {
                break;
            }
        }
        printf("*请输入学生学号：");
        scanf("%s", number);
        STU *q = NULL;
        
        while (p != NULL) {
            if (strcmp(name, p->name) == 0 && strcmp(number, p->number) == 0) {
                if (p == head) {
                    head = p->next;
                    free(p);
                    
                    printf("*删除成功！！！！\n");
                    printf("请按任意键返回......");
                    fp = fopen("class1.txt", "w");
                    while (ptemp != NULL) {
                        fprintf(fp, "%s %s %s %lf %lf %lf", ptemp->name, ptemp->number, ptemp->cla, ptemp->chinese, ptemp->math, ptemp->english);
                        ptemp = ptemp->next;
                    }
                    fclose(fp);
                    getch();
                    return;
                }
                else {
                    q->next = p->next;
                    free(p);
                    //savestu(head);
                    printf("删除成功\n");
                    printf("按任意键返回");
                    fp = fopen("class1.txt", "w");
                    while (ptemp != NULL) {
                        fprintf(fp, "%s %s %s %lf %lf %lf", ptemp->name, ptemp->number, ptemp->cla, ptemp->chinese, ptemp->math, ptemp->english);
                        ptemp = ptemp->next;
                    }
                    fclose(fp);
                    getch();
                    return;
                }
                
            }
            else {
                q = p;
                p = p->next;
            }
        }
        
        
        
        if (p == NULL) {
            printf("*未找到该学生\n");
            printf("按任意键返回......");
            getch();
            return;
        }
    }
}
void search(STU *head) {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        char name[20];
        char number[20];
        STU *p = head;
        printf("\n\n\n\n\n");
        while (1) {
            printf("\t\n*请输入学生姓名:");
            scanf("%s", name);
            getchar();
            int i;
            for (i = 0; i < strlen(name); i++) {
                if ((name[i]) >= '0' && (name[i]) <= '9') {
                    printf("\n姓名不能带有数字.....");
                    printf("\n请按任意键继续......");
                    getch();
                    break;
                }
                
            }
            if (i == strlen(name)) {
                break;
            }
        }
        printf("*请输入要查找学生学号：");
        scanf("%s", number);
        getchar();
        while (p != NULL) {
            if (strcmp(name, p->name) == 0 && strcmp(number, p->number) == 0) {
                printf("该学生信息：\n");
                printf("学生姓名：%s\n", p->name);
                printf("学生学号：%s\n", p->number);
                printf("语文成绩：%.3lf\n", p->chinese);
                printf("数学成绩：%.3f\n", p->math);
                printf("英语成绩：%.3f\n", p->english);
                printf("总成绩：%.3f\n", p->sum);
                printf("按任意键返回：");
                getch();
                return;
            }
            else {
                p = p->next;
            }
        }
        if (p == NULL) {
            printf("未查找到该学生......\n");
            printf("按任意键返回...");
            getch();
            return;
        }
    }
}
void add() {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        FILE *fp;
        if (fp = fopen("class1.txt", "r") == NULL) {
            fp = fopen("class1.txt", "w");
            STU *head, *p;
            p = head = (STU *)malloc(sizeof(STU));
            printf("\n\n\n\n\n\n");
            while (1) {
                printf("\t\n*请输入学生姓名:");
                scanf("%s", p->name);
                getchar();
                int i;
                for (i = 0; i < strlen(p->name); i++) {
                    if ((p->name[i]) >= '0' && (p->name[i]) <= '9') {
                        printf("\n姓名不能带有数字.....");
                        printf("\n请按任意键继续......");
                        getch();
                        break;
                    }
                    
                }
                if (i == strlen(p->name)) {
                    break;
                }
            }
            printf("*请输入学生学号：");
            scanf("%s", p->number);
            getchar();
            printf("*请输入学生班级：");
            scanf("%s", p->cla);
            getchar();
            printf("*请输入学生语文成绩：");
            scanf("%lf", &p->chinese);
            getchar();
            printf("*请输入学生数学成绩：");
            scanf("%lf", &p->math);
            getchar();
            printf("*请输入学生英语成绩：");
            scanf("%lf", &p->english);
            getchar();
            p->sum = p->chinese + p->math + p->english;
            p->next = NULL;
            fclose(fp);
            savestu(head, p);
            printf("添加成功！！\n");
            printf("请按任意键返回......");
            getch();
            return;
        }
        else {
            STU*head, *p, *q = NULL;
            head = readstu();
            p = head;
            while (p != NULL) {
                q = p;
                p = p->next;
            }
            p = (STU*)malloc(sizeof(STU));
            printf("\n\n\n\n\n\n");
            while (1) {
                printf("\t\n*请输入学生姓名:");
                scanf("%s", p->name);
                getchar();
                int i;
                for (i = 0; i < strlen(p->name); i++) {
                    if ((p->name[i]) >= '0' && (p->name[i]) <= '9') {
                        printf("\n姓名不能带有数字.....");
                        printf("\n请按任意键继续......");
                        getch();
                        break;
                    }
                    
                }
                if (i == strlen(p->name)) {
                    break;
                }
            }
            printf("*请输入学生学号：");
            scanf("%s", p->number);
            getchar();
            printf("*请输入学生班级：");
            scanf("%s", p->cla);
            getchar();
            printf("*请输入学生语文成绩：");
            scanf("%lf", &p->chinese);
            getchar();
            printf("*请输入学生数学成绩：");
            scanf("%lf", &p->math);
            getchar();
            printf("*请输入学生英语成绩：");
            scanf("%lf", &p->english);
            getchar();
            
            p->sum = p->chinese + p->math + p->english;
            q->next = p;
            p->next = NULL;
            savestu(p, head);
            printf("添加成功！！！\n");
            printf("请按任意键返回....");
            getch();
            return;
        }
    }
}
void print(STU *head) {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        STU *p = head;
        int count = 0;
        printf("\t\t学生姓名 学生学号 语文成绩 数学成绩 英语成绩 总成绩\n");
        while (p != NULL) {
            printf("\t\t%-8s %-8s %-8.3lf %-8.3lf %-8.3lf %-8.3lf", p->name, p->number, p->chinese, p->math, p->english, p->sum);
            count++;
            p = p->next;
        }
        printf("\t\t共计%d名学生\n", count);
        printf("\t\t请按任意键返回");
        getch();
        return;
    }
}
void change(STU *head) {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        char name[20];
        char number[20];
        STU *p = head;
        printf("\n\n\n\n\n");
        while (1) {
            printf("\t\n*请输入修改的学生姓名:");
            scanf("%s", name);
            getchar();
            int i;
            for (i = 0; i < strlen(name); i++) {
                if ((name[i]) >= '0' && (name[i]) <= '9') {
                    printf("\n姓名不能带有数字.....");
                    printf("\n请按任意键继续......");
                    getch();
                    break;
                }
                
            }
            if (i == strlen(name)) {
                break;
            }
        }
        printf("*请输入要修改学生学号：");
        scanf("%s", number);
        getchar();
        while (p != NULL) {
            if (strcmp(name, p->name) == 0 && strcmp(number, p->number) == 0) {
                printf("该学生信息为:\n");
                printf("学生姓名：%s\n", p->name);
                printf("学生学号：%s\n", p->number);
                printf("语文成绩：%.3lf 数学成绩：%.3lf 英语成绩：%.3lf 总成绩：%.3lf\n", p->chinese, p->math, p->english, p->sum);
                char km[20];
                printf("请输入要修改的科目：");
                scanf("%s", km);
                getchar();
                if (strcmp(km, "语文") == 0) {
                    printf("请输入修改后的成绩：");
                    scanf("%lf", &p->chinese);
                    getchar();
                    p->sum = p->chinese + p->math + p->english;
                    printf("\n修改成功！！！\n");
                    savestu(p, head);
                    printf("按任意键返回：");
                    getchar();
                    return;
                }
                if (strcmp(km, "数学") == 0) {
                    printf("请输入修改后的成绩：");
                    scanf("%lf", &p->math);
                    getchar();
                    p->sum = p->chinese + p->math + p->english;
                    printf("\n修改成功！！！\n");
                    savestu(p, head);
                    printf("按任意键返回：");
                    getchar();
                    return;
                }
                if (strcmp(km, "英语") == 0)
                {
                    printf("请输入修改后的成绩：");
                    scanf("%lf", &p->english); getchar();
                    p->sum = p->chinese + p->english + p->math;
                    printf("\n修改成功!!!\n");
                    savestu(p, head);
                    printf("按任意键返回......");
                    getch();
                    return;
                }
            }
            else {
                p = p->next;
            }
        }
        if (p == NULL) {
            printf("\n未找到该学生的信息......");
            printf("\n按任意键返回。");
            getch();
            return;
        }
    }
}
void zhaohui(STUAC *head) {
    system("cls");
    char ch;
    printf("温馨提示：如果误点请任意键返回上一步;否则双击回车继续：\n");
    if ((ch = getch()) != '\r') {
        return;
    }
    if ((ch = getch()) == '\r') {
        STUAC *p = head;
        printf("\n\n\n\n\t\t\t\t\t请输入姓名：");
        char name[20];
        char zh[20];
        scanf("%s", name);
        printf("\t\t\t\t\t请输入账号：");
        scanf("%s", zh);
        while (p != NULL) {
            if (strcmp(name, p->name) == 0 && strcmp(zh, p->zh) == 0) {
                printf("\n\t\t\t\t\t查找成功.....\n");
                Sleep(1000);
                printf("\t\t\t\t\t密码：%s", p->mm);
                printf("\n\t\t\t\t\t按任意键返回：");
                getch();
                break;
            }
            else {
                p = p->next;
            }
            
        }
        if (p == NULL) {
            printf("\n\t\t\t查询失败!\n");
            printf("\t\t\t账号或姓名错误，或未注册账号....");
            printf("\t\t\t请按任意键返回.....");
            getch();
            return;
        }
    }
}
void sortstu(STU *head) {
    int count = 0;
    STU *p;
    p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    int i, j;
    STU *q;
    q = p = head;
    STU *l = NULL;
    double t;
    char s[20];
    for (i = 0; i < count; i++) {
        l = p;
        q = p;
        for (j = i + 1; j<count; j++, q = q->next)
        {
            if (l->sum < q->next->sum)
                l = q->next;
        }
        if (l != p) {
            t = l->chinese; l->chinese = p->chinese; p->chinese = t;
            t = l->math; l->math = p->math; p->math = t;
            t = l->english; l->english = p->english; p->english = t;
            t = l->sum; l->sum = p->sum; p->sum = t;
            strcpy(s, l->name); strcpy(l->name, p->name); strcpy(p->name, s);
            strcpy(s, l->number); strcpy(l->number, p->number); strcpy(p->number, s);
        }
        p = p->next;
    }
    printlb(head);
    printf("排序完成\n");
    printf("请按任意键返回......");
    getch();
    return;
}
//疑问
void printlb(STU *head) {
    system("cls");
    char cla[20];
    printf("请输入您想要查找的班级：");
    scanf("%s", cla);
    getchar();
    STU *p = head;
    if (p == NULL) {
        printf("输入班级错误......\n");
        printf("按任意键返回...");
        getch();
        return;
    }
    
    printf("\n\t\t\t排序如下(由成绩大小由高到底)：\n");
    
    printf("\t\t\t\t*姓名  学号   班级   总分   语文成绩   数学成绩   英语成绩*");
    printf("\t\t\t\t\t\t\t\t******************************************************");
    while (p != NULL) {
        if (strcmp(cla, p->cla) == 0) {
            printf("\n\t\t\t\t*%s %s %s %lf %lf %lf %lf*\n", p->name, p->number, p->cla, p->sum, p->chinese, p->math, p->english);
        }
        p = p->next;
    }
    return;
}


int main() {
    
    system("color fc");
    
    while (1) {
        system("cls");
        char ch[100];
        char s;
        char k;
        
        printf("\n\n\n\n\n\n");
        printf("\t\t\t\t********************************\n\n");
        printf("\t\t\t\t\t 学生管理系统 \t\t\t\t\t\n\n");
        printf("\t\t\t\t--------------------------------\t\t\t\t\n\n");
        printf("\t\t\t\t*\t1.学生端\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t*\t2.教师端\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t*\t3.退出管理系统\t*\t\t\t\t\t\n\n");
        printf("\t\t\t\t********************************\t\t\t\t\n\n");
        printf("\t\t\t\t请根据界面选择1/2/3选项\t\t\t\t\n\n");
        
        scanf("%s", ch);
        if (strlen(ch) != 1) {
            printf("Error");
            printf("输入错误请检查输入......\n按回车键返回......\n");
            s = getch();
            printf("请等待.......");
            Sleep(1000);
        }
        else {
            char k = ch[0];
            switch (k) {
                case '1':student();
                    break;
                case '2':teacher();
                    break;
                case '3':exit(0);
                default:
                    
                    printf("输入错误请检查输入......\n按回车键返回......\n");
                    s = getch();
                    printf("\n请稍后....");
                    Sleep(1000);
            }
        }
    }
    system("pause");
    return 0;
}
