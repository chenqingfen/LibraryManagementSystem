#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct book {   //保存图书信息->BOOK
    char no[20];
    char name[20];
    char author[50];
    int amount1;
    char cbs[50];
    char type[20];
    float price;
}BOOK;                                //BOOK是book型结构体  BOOKS是结构体数组
typedef struct{
    BOOK book[100];
    int len;
}BOOKS;


BOOKS s;//s是BOOKS型变量
BOOKS *p=&s;

void save(void);//保存图书信息
void add_book(void);//添加图书
void sale_book(void);//出售图书
void input_book(void);//添加新书
void inquire_book(void);//查询图书
void change_book(void);//修改图书信息

void inquire_book1(void);
void inquire_book2(void);
void inquire_book3(void);
void inquire_book4(void);

void delete_book(void);//删除图书
void increase_book(void);//图书进货
void sort_book(void);//排序
void sort1(void);
void sort2(void);
void sort3(void);	
void menu()/*自定义函数实现菜单功能*/
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|--------------------BOOK----------------------|\n");
	printf("\t\t|\t         1.售出图书                    |\n");
	printf("\t\t|\t         2.首次入库                    |\n");
	printf("\t\t|\t         3.新书入库                    |\n");
	printf("\t\t|\t         4.查询图书                    |\n");
	printf("\t\t|\t         5.删除图书                    |\n");
	printf("\t\t|\t         6.图书进货                    |\n");
	printf("\t\t|\t         7.图书排序                    |\n");
	printf("\t\t|\t         8.修改信息                    |\n");
	printf("\t\t|----------------------------------------------|\n\n");
	printf("\t\t\t\t请选择功能(0-7):");
}

void main()
{
    while(1){
		 int a;
        menu();
        scanf("%d",&a);
    switch (a) {
        case 1:sale_book();break;
        case 2:add_book();break;
        case 3:input_book();break;
        case 4:inquire_book();break;
        case 5:delete_book();break;
        case 6:increase_book();break;
        case 7:sort_book();break;
		case 8:change_book();break;
        default:printf("输入错误");break;
    }
}
}
	

void save()   //保存图书信息
{
    FILE *fp;
    int i;
    
    if((fp=fopen("book.txt","w+"))==NULL)//打开文件
    {
        printf("cannot open this file\n");
        return ;
    }
    
    
    for(i=0;i<p->len;i++)//往文件里写信息
        if(fwrite(&(p),sizeof(BOOK),1,fp)!=1)
            printf("file write error\n");
    fclose(fp);
}

void sale_book()
{
    FILE *fp;
    int i;
    int j;
	int k;
	int t;
	int a=0;
    char bianhao[20];
    printf("请输入图书编号");
    scanf("%s",bianhao);
    fp=fopen("book.txt", "r+");
    for (i=0; i<p->len; i++) {
        if(strcmp(bianhao, p->book[i].no)==0) {
            printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
			printf("是否确认售出此书？确认请按1，退出请按2\n");
            scanf("%d",&j);
            if (j==1) {
				printf("请输入出售数量");
				scanf("%d",&k);
				if(p->book[i].amount1<k){
					printf("库存不足，请重新输入");
				break;} 
				else if(p->book[i].amount1>=k){
					p->book[i].amount1-=k;
					printf("售出成功\n");}
					a=1;
				break;
			}
			else
				break;
            }
        else
		{ printf("没有对应图书，请检查编号是否输入正确\n");
		break;
		}

        
		}
	save();
	fclose(fp);
    //system("cls");
}


void add_book()   //第一次进书
{
	FILE *fp;
    fp=fopen("book.txt", "w+");
    int n;
    printf("请输入添加新书种类数量:");
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        printf("请输入编号:\n");
        scanf("%s",p->book[i].no);
        printf("请输入书名:\n");
        scanf("%s",p->book[i].name);
        printf("请输入作者:\n");
        scanf("%s",p->book[i].author);
        printf("请输入数量:\n");
        scanf("%d",&p->book[i].amount1);
        printf("请输入出版社名称:\n");
        scanf("%s",p->book[i].cbs);
        printf("请选择该书类别：1.人文 2.科学 3.历史\n");
        scanf("%s",p->book[i].type);
        printf("请输入价格:\n");
        scanf("%f",&p->book[i].price);
        p->len++;
        save();
		printf("保存成功\n");
    }
    system("cls");
}
void input_book()
{
    FILE *fp;
    int n;
    int i;
	int a=p->len;
    printf("请输入添加新书种类数量:");
    scanf("%d",&n);
    fp=fopen("book.txt", "a");
    for (i=p->len; i<a+n; i++) {
        printf("请输入编号:\n");
        scanf("%s",p->book[i].no);
        printf("请输入书名:\n");
        scanf("%s",p->book[i].name);
        printf("请输入作者:\n");
        scanf("%s",p->book[i].author);
        printf("请输入数量\n:");
        scanf("%d",&p->book[i].amount1);
        printf("请输入出版社名称\n:");
        scanf("%s",p->book[i].cbs);
        printf("请选择该书类别：1.人文 2.科学 3.历史\n");
        scanf("%s",p->book[i].type);
        printf("请输入价格:\n");
        scanf("%f",&p->book[i].price);
        p->len++;
        save();
		printf("保存成功");
    }
    fclose(fp);
    system("cls");
    
}




void inquire_book()
{

    printf("请选择查询方式：1.按编号查询 2.按书名查询 3.按作者查询 4.类别查询 5.返回上一级\n");
    for(;;)
    {
        
        switch (getchar()) {
        case '1':inquire_book1();break;
        case '2':inquire_book2();break;
        case '3':inquire_book3();break;
        case '4':inquire_book4();break;
        case '5':  system("cls");main();break;
        
    }
        
        
    }
}
void inquire_book1()
{
    FILE *fp;
    fp=fopen("book.txt", "r");
    char bianhao[20];
    int i;
	int j=0;
    printf("请输入查询编号");
    scanf("%s",bianhao);
    for (i=0; i<p->len; i++) {
        if (strcmp(bianhao,p->book[i].no)==0) {
            printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
			j=1;
            break;
        }
    }
    if(j==0) {
        printf("抱歉，没有这本书\n");
    }
    fclose(fp);
    
}
void inquire_book2()
{
    FILE *fp;
    int i;
	int j=0;
    fp=fopen("book.txt", "r");
    char shuming[20];
    printf("请输入查询书籍：");
    scanf("%s",shuming);
    for (i=0; i<p->len; i++) {
        if (strcmp(shuming, p->book[i].name)==0) { 
			printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
			j=1;
			break;
        }
    }
    if(j==0){
        printf("抱歉，没有这本书。\n");
	}
    fclose(fp);
    
}
void inquire_book3()
{
    FILE *fp;
    int i;
	int j=0;
    fp=fopen("book.txt", "r");
    char zuozhe[20];
    printf("请输入查询书籍的作者：");
    scanf("%s",zuozhe);
    for (i=0; i<p->len; i++) {
        if (strcmp(zuozhe, p->book[i].author)==0) {
            printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
			j=1;
			break;
        }
    }
    if(j==0) {
        printf("抱歉，没有这本书。\n");
    }
    fclose(fp);
}
void inquire_book4()
{
    FILE *fp;
    int i;
	int j=0;
    fp=fopen("book.txt", "r");
    char leibie[20];
    printf("请输入查询书籍的类别：");
    scanf("%s",leibie);
    for (i=0; i<p->len; i++) {
        if (strcmp(leibie, p->book[i].type)==0) {
            printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
			j=1;
        }
    }
    if(j==0) {
        printf("抱歉，没有该类别的书。\n");
    }
    fclose(fp);
}
void increase_book()
{
    FILE *fp;
    char bianhao[20];
    int i;
    int k,j;
	int a=0;
    fp=fopen("book.txt", "r+");
    printf("请输入进货图书编号");
    scanf("%s",bianhao);
    printf("请输入进货数量");
    scanf("%d",&k);
    for (i=0; i<p->len; i++) {
        if (strcmp(bianhao, p->book[i].no)==0) {
            printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
            printf("是否确认是该图书 确认按1 取消按2\n");
            scanf("%d",&j);
            if (j==1) {
                p->book[i].amount1+=k;
                printf("该书现有库存为%d\n",p->book[i].amount1);
				a=1;
            }
            else
                break;
        }
    }
    if(a==0) {
        printf("无对应书籍，请检查编号是否正确\n");
    }
    save();
    fclose(fp);
}
void delete_book()
{
    FILE *fp;
    char bianhao[20];
    int i,j,k;
    printf("请输入删除图书的编号");
    scanf("%s",bianhao);
    fp=fopen("book.txt", "r+");
    for (i=0; i<p->len; i++) {
        if (strcmp(bianhao, p->book[i].no)==0) {
            printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
            printf("是否确认是该图书 确认按1 取消按2\n");
            scanf("%d",&j);
            if (j==1) {
                for (k=i; k<p->len; k++) {
                    strcpy(p->book[k].no, p->book[k+1].no);
                    strcpy(p->book[k].name, p->book[k+1].name);
                    strcpy(p->book[k].author, p->book[k+1].author);
                    strcpy(p->book[k].cbs, p->book[k+1].cbs);
                    strcpy(p->book[k].type, p->book[k+1].type);
                    p->book[k].amount1=p->book[k+1].amount1;
                    p->book[k].price=p->book[k+1].price;
					p->len--;
                    save();
                    printf("删除成功\n");
					break;

                }
            }
            else
                break;
        }
    }
    fclose(fp);
}
void change_book()
{
	FILE *fp;
    char bianhao1[20];
	char bianhao2[20];
	char author[20];
	char name[20];
	char cbs[20];
	char type[20];
	int amount;
	float price;
    int i,j,a;
    printf("请输入修改图书的编号");
    scanf("%s",bianhao1);
    fp=fopen("book.txt", "r+");
    for (i=0; i<p->len; i++) {
        if (strcmp(bianhao1, p->book[i].no)==0) {
            printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
            printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[i].no,p->book[i].author,p->book[i].name,p->book[i].amount1,p->book[i].type,p->book[i].cbs,p->book[i].price);
            printf("是否确认是该图书 确认按1 取消按2\n");
            scanf("%d",&j);
            if (j==1) {
                printf("请选择要修改的信息1.编号2.作者3.书名4.数量5.出版社6.类别7.价格\n");
				scanf("%d",&a);
				if(a==1){
					printf("请输入修改后的编号\n");
					scanf("%s",bianhao2);
					strcpy(p->book[i].no,bianhao2);}
				else if(a==2){
					printf("请输入修改后的作者\n");
					scanf("%s",author);
					strcpy(p->book[i].author,author);}
				else if(a==3){
					printf("请输入修改后的书名\n");
					scanf("%s",name);
					strcpy(p->book[i].name,name);}
				else if(a==4){
					printf("请输入修改后的数量\n");
					scanf("%d",&amount);
					p->book[i].amount1=amount;}
				else if(a==5){
					printf("请输入修改后的出版社\n");
					scanf("%s",cbs);
					strcpy(p->book[i].cbs,cbs);}
				else if(a==6){
					printf(
					"请输入修改后的类别\n");
					scanf("%s",type);
					strcpy(p->book[i].type,type);
				}
				else if(a==7){
					printf("请输入修改后的价格\n");
					scanf("%d",&price);
					p->book[i].price=price;
            }
			}
            else
                break;
        }
    }
    fclose(fp);
}
void sort_book()
{
    int a;
    printf("请选择排序方式：1.按编号2.按书名3.按数量\n");
    scanf("%d",&a);
    switch (a) {
        case 1:sort1();break;
        case 2:sort2();break;
        case 3:sort3();break;
    }
}
void sort1()
{
    int i,k,a;
    FILE *fp;
    fp=fopen("book.txt", "w+");
    BOOK temp;
    for (i=0; i<p->len-1; i++) {
        for (int j=0; j<p->len-i-1; j++) {
            if (strcmp(p->book[i].no, p->book[i+1].no)>0) {
                temp=p->book[i];
                p->book[i]=p->book[i+1];
                p->book[i+1]=temp;
            }
        }
    }
    save();
    printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
    for (k=0; k<p->len; k++) {
        printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[k].no,p->book[k].author,p->book[k].name,p->book[k].amount1,p->book[k].type,p->book[k].cbs,p->book[k].price);
    }
	printf("按任意键退出");
	scanf("%d",&a);
    fclose(fp);
}
void sort2()
{
    int i,k,a;
    FILE *fp;
    fp=fopen("book.txt", "w+");
    BOOK temp;
    for (i=0; i<p->len-1; i++) {
        for (int j=0; j<p->len-i-1; j++) {
            if (strcmp(p->book[i].name, p->book[i+1].name)>0) {
                temp=p->book[i];
                p->book[i]=p->book[i+1];
                p->book[i+1]=temp;
            }
        }
    }
    save();
    printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
    for (k=0; k<p->len; k++) {
        printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[k].no,p->book[k].author,p->book[k].name,p->book[k].amount1,p->book[k].type,p->book[k].cbs,p->book[k].price);
    }
	printf("按任意键退出");
	scanf("%d",&a);
    fclose(fp);
}
void sort3()
{
    FILE *fp;
    int i,k,a;
    fp=fopen("book.txt", "w+");
    BOOK temp;
    for (i=0; i<p->len-1; i++) {
        for (int j=0; j<p->len-i-1; j++) {
            if (p->book[i].amount1<p->book[i+1].amount1) {
                temp=p->book[i];
                p->book[i]=p->book[i+1];
                p->book[i+1]=temp;
            }
        }
    }
    save();
    printf("编号\t作者\t书名\t数量\t类别\t出版社\t\t价格\n");
    for (k=0; k<p->len; k++) {
        printf("%s\t%s\t%s\t%d\t%s\t%s\t\t%.2f\n",p->book[k].no,p->book[k].author,p->book[k].name,p->book[k].amount1,p->book[k].type,p->book[k].cbs,p->book[k].price);
    }
	printf("按任意键退出");
	scanf("%d",&a);
    fclose(fp);
}
