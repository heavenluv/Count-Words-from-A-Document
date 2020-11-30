#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vocab
{
    char word[60];
    int num;
} Vocab;
void main()
{
    int size;
    char all;
    char temp[60]="";
    int mark=0, i=0, j=0;
    int n=0, m=0;
    int numofvocabs=0;
    int k=0;
    int det=0;
    Vocab store[28000];
    memset(store, 0, sizeof(store));
    FILE *fp1=NULL;
    clock_t start, finish ;
    start = clock() ;
    fp1=fopen("input.txt","rb");
    //for (j = 0; j < 60000; j++)//最初用来对结构体清零的方法
	//{
	//	store[j].num=0;
		//printf("how：%d\n",store[n].num);
	//}
	
    while (!feof(fp1))
    {
        all=tolower(fgetc(fp1));
        if(all==39)
		{ 
			//printf("hi"); debug use
			continue;
		}
        //printf("4hi\n");debug use
        //det=(all>='a'&& all<='z')&&(all>='A'&& all<='Z');另一种det的方法 
        det=isalpha(all);
        if(det||all=='-')
        {
            mark=1;//代表开始记录 
            temp[i]=all;
            i++;
            //printf("3hi\n");debug use
            //puts(temp);debug use
		}
        else if(!det && mark==1)
        {
            numofvocabs++;//总词汇数量加一 
            temp[i]='\0';
            mark=0;
            i=0;
            //printf("how：%d\n",store[n].num);debug use
            //printf("2hi\n");debug use
			//puts(temp);debug use
            //printf("b");debug use
            for(j=0;j<n+1;j++)//因为n初始为0，故初始条件为n+1  判断是否重复的部分 
            {
                if(!strcmp(store[j].word, temp))
                        {
                            k=0;
                            store[j].num++;
                            //printf("1hi\n");debug use
                            //printf("how：%4d\n",sizeof(store[n].num));debug use
                            //printf("%d",store[j].num);debug use
                            break;
                        }
                        else
                        {
                                k=1;
                                //printf("hi\n");//debug用 
                        }
						
            }
            if(k==1)//若无重复将temp里的数据存进去store.word 
            {

				for (j=0;j<60;j++)//can try to read the length of temp
            	{
            	    //printf("%s\n",temp[j]);debug use
            	    store[n].word[j]=NULL;
                	store[n].word[j]=temp[j];//store first, not compare yet
                	//printf("how：%d\n",store[j].num);debug use
                	//printf("%s",store[n].word);debug use
            	}
                store[n].num++;
				n++;
                //printf("个数：%d\n",store[n].num);debug use
                //printf("how：%16d\n",sizeof(store[n].num));debug use
                
                for(j=0;j<60;j++)//对temp进行清空 
                {
                    temp[j]=NULL;
                }
            }
        }

    }
    Vocab tmp;//冒泡排序 
	Vocab* p=store;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			if( (p+j)->num > (p+j+1)->num)
			{
				tmp=*(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1)= tmp;
			}
		}
	}
	
    /*int x,y;//冒泡 
    for(x = 0;x < n;x ++){
        for(y = x+1;y < n;y ++){
            if(store[y].num > store[x].num){
                Vocab temp1 = store[x];
                store[x] = store[y];
                store[y] = temp1;
            }
        }
    }//*/

    /*int x=0, y=0;//插入 
    char tmp[60];
    for (x = 1; x < n; x++) {
        if (store[x].num < store[x-1].num) {
            for (j=0;j<n ;j++) {
            tmp[x] = store[x].word[j];}
            for (y = x - 1; y >= 0 && store[y].num > store[y].num; y--)
                {
                    for (j=0;j<60;j++){
                    store[y+1] = store[y];}
                }
            for (j=0;j<60;j++){
            store[y+1].word[j] = tmp[y];}
        }
    }//*/

	/*Vocab tmpa;  //冒泡法（使用memset（）进行复制） 
	for (i = 0; i < n; i++)
	{
	    for (j = 0; j < n - i; j++)
	    {
	        if (store[j].num<store[j + 1].num)
	        {
	            memcpy(&tmpa, &store[j], sizeof(store));
	            memcpy(&store[j], &store[j + 1], sizeof(store));
	            memcpy(&store[j + 1], &tmpa, sizeof(store));
	        }
	    }
	}	//*/
	/*Vocab tmpa[15000],tmpb[15000];//使用c语言自带的qsort() 
	memcpy(tmpa,store,15000);
	memcpy(tmpb,store+15000,15000);
	cmp(tmpa,tmpb);			
	qsort(store,n,sizeof(store),cmp);//*/
    FILE *fp2=NULL;
    fp2=fopen("output.txt","w+");
    if(!fp2)
    {
        printf("\n打开 output.txt失败");
        exit(0);
    }
    int a;
    for(a=3;a<n+3;a++) //前面有三个空的资料，故从a=3开始循环 
    {
        fprintf(fp2,"单词: %24s\t   词频: %d\n", store[a].word, store[a].num);
        //printf("单词: %24s\t   词频: %d\n", store[a].word, store[a].num);
    }
    fprintf(fp2,"不同的单词个数：%d\n",n);
	fprintf(fp2,"总单词个数：%d\n",numofvocabs);
    fclose(fp2);
    finish = clock() ;
    printf("不同的单词个数：%d\n",n);
	printf("总单词个数：%d\n",numofvocabs);
	printf("分析完毕!\n运行时长为 %fs\n", (float) (finish - start) / CLOCKS_PER_SEC) ;
	return 0; 

}

/*int cmp( const void *a ,const void *b)

{
	struct Vocab *aa = (Vocab *)a;
	struct Vocab *bb = (Vocab *)b;
	return aa->num > bb->num ? 1 : -1;
}//*/

