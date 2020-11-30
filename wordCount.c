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
    //for (j = 0; j < 60000; j++)//��������Խṹ������ķ���
	//{
	//	store[j].num=0;
		//printf("how��%d\n",store[n].num);
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
        //det=(all>='a'&& all<='z')&&(all>='A'&& all<='Z');��һ��det�ķ��� 
        det=isalpha(all);
        if(det||all=='-')
        {
            mark=1;//����ʼ��¼ 
            temp[i]=all;
            i++;
            //printf("3hi\n");debug use
            //puts(temp);debug use
		}
        else if(!det && mark==1)
        {
            numofvocabs++;//�ܴʻ�������һ 
            temp[i]='\0';
            mark=0;
            i=0;
            //printf("how��%d\n",store[n].num);debug use
            //printf("2hi\n");debug use
			//puts(temp);debug use
            //printf("b");debug use
            for(j=0;j<n+1;j++)//��Ϊn��ʼΪ0���ʳ�ʼ����Ϊn+1  �ж��Ƿ��ظ��Ĳ��� 
            {
                if(!strcmp(store[j].word, temp))
                        {
                            k=0;
                            store[j].num++;
                            //printf("1hi\n");debug use
                            //printf("how��%4d\n",sizeof(store[n].num));debug use
                            //printf("%d",store[j].num);debug use
                            break;
                        }
                        else
                        {
                                k=1;
                                //printf("hi\n");//debug�� 
                        }
						
            }
            if(k==1)//�����ظ���temp������ݴ��ȥstore.word 
            {

				for (j=0;j<60;j++)//can try to read the length of temp
            	{
            	    //printf("%s\n",temp[j]);debug use
            	    store[n].word[j]=NULL;
                	store[n].word[j]=temp[j];//store first, not compare yet
                	//printf("how��%d\n",store[j].num);debug use
                	//printf("%s",store[n].word);debug use
            	}
                store[n].num++;
				n++;
                //printf("������%d\n",store[n].num);debug use
                //printf("how��%16d\n",sizeof(store[n].num));debug use
                
                for(j=0;j<60;j++)//��temp������� 
                {
                    temp[j]=NULL;
                }
            }
        }

    }
    Vocab tmp;//ð������ 
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
	
    /*int x,y;//ð�� 
    for(x = 0;x < n;x ++){
        for(y = x+1;y < n;y ++){
            if(store[y].num > store[x].num){
                Vocab temp1 = store[x];
                store[x] = store[y];
                store[y] = temp1;
            }
        }
    }//*/

    /*int x=0, y=0;//���� 
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

	/*Vocab tmpa;  //ð�ݷ���ʹ��memset�������и��ƣ� 
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
	/*Vocab tmpa[15000],tmpb[15000];//ʹ��c�����Դ���qsort() 
	memcpy(tmpa,store,15000);
	memcpy(tmpb,store+15000,15000);
	cmp(tmpa,tmpb);			
	qsort(store,n,sizeof(store),cmp);//*/
    FILE *fp2=NULL;
    fp2=fopen("output.txt","w+");
    if(!fp2)
    {
        printf("\n�� output.txtʧ��");
        exit(0);
    }
    int a;
    for(a=3;a<n+3;a++) //ǰ���������յ����ϣ��ʴ�a=3��ʼѭ�� 
    {
        fprintf(fp2,"����: %24s\t   ��Ƶ: %d\n", store[a].word, store[a].num);
        //printf("����: %24s\t   ��Ƶ: %d\n", store[a].word, store[a].num);
    }
    fprintf(fp2,"��ͬ�ĵ��ʸ�����%d\n",n);
	fprintf(fp2,"�ܵ��ʸ�����%d\n",numofvocabs);
    fclose(fp2);
    finish = clock() ;
    printf("��ͬ�ĵ��ʸ�����%d\n",n);
	printf("�ܵ��ʸ�����%d\n",numofvocabs);
	printf("�������!\n����ʱ��Ϊ %fs\n", (float) (finish - start) / CLOCKS_PER_SEC) ;
	return 0; 

}

/*int cmp( const void *a ,const void *b)

{
	struct Vocab *aa = (Vocab *)a;
	struct Vocab *bb = (Vocab *)b;
	return aa->num > bb->num ? 1 : -1;
}//*/

