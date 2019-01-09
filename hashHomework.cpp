#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
//存储444个姓氏
const char *name0[444]= {"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","zhe","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang","kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu","bai","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang","lu","wei","chang","ma","miao","feng","hua","fang","yu","ren","yuan","liu","feng","bao","shi","tang","fei","lian","cen","xue","lei","he","ni","tang","teng","yin","luo","bi","hao","wu","an","chang","le","yu","shi","fu","pi","bian","qi","kang","wu","yu","yuan","bu","gu","meng","ping","huang","he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di","mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang","xiong","ji","shu","qu","xiang","zhu","dong","liang","du","ruan","lan","min","xi","ji","ma","qiang","jia","lu","lou","wei","jiang","tong","yan","guo","mei","sheng","lin","diao","zhong","xu","qiu","luo","gao","xia","cai","tian","fan","hu","ling","huo","yu","wan","zhi","ke","zan","guan","lu","mo","jing","fang","qiu","miao","gan","jie","ying","zong","ding","xuan","bi","deng","yu","dan","hang","hong","bao","zhu","zuo","shi","cui","ji","niu","gong","cheng","ji","xing","hua","pei","lu","rong","weng","xun","yang","yu","hui","zhen","qu","jia","feng","rui","yi","chu","jin","ji","bing","mi","song","jing","duan","fu","wu","wu","jiao","ba","gong","mu","kui","shan","gu","che","hou","mi","peng","quan","xi","ban","yang","qiu","zhong","yi","gong","ning","chou","luan","bao","gan","dou","li","rong","zu","wu","fu","liu","jing","zhan","shu","long","ye","xing","si","shao","gao","li","ji","bo","yin","su","bai","huai","pu","tai","cong","e","suo","xian","ji","lai","zhuo","lin","tu","meng","chi","qiao","yin","yu","xu","nen","cang","shuang","wen","xin","dang","di","tan","gong","lao","pang","ji","shen","fu","du","ran","zai","li","yong","tuo","qu","sang","gui","pu","niu","shou","tong","bian","hu","yan","ji","jia","pu","shang","nong","wen","bie","zhuang","yan","chai","qu","yan","chong","mu","lian","ru","xi","huan","ai","yu","rong","xiang","gu","yi","shen","ge","liao","yu","zhong","ji","ji","heng","bu","du","geng","man","hong","kuang","guo","wen","kou","guang","lu","que","dong","ou","shu","wo","li","wei","yue","kui","long","shi","gong","she","nie","chao","gou","ao","rong","ling","zi","xin","han","na","jian","rao","kong","zeng","wu","sha","nie","yang","ju","xu","feng","chao","guan","kuai","xiang","cha","hou","jing","hong","you","zhu","quan","dai","gai","yi","huan","gong","zhang","du","jin","chu","yan","fa","ru","yan","tu","qin","gui","hai","yue","shuai","gou","kang","kuang","hou","you","qin","shang","mou","she","ji","bo","shang","mo","ha","qiao","da","nian","ai","yang","tong","yan","fu"}; //存储305个名字
//存储305个名
const char* name1[305] = {"wei","gang","yong","yi","jun","feng","qiang","jun","ping","bao","dong","wen","hui","li","ming","yong","jian","shi","guang","zhi","yi","xing","liang","hai","shan","ren","bo","ning","gui","fu","sheng","long","yuan","quan","guo","sheng","xue","xiang","cai","fa","wu","xin","li","qing","fei","bin","fu","shun","xin","zi","jie","tao","chang","cheng","kang","xing","guang","tian","da","an","yan","zhong","mao","jin","lin","you","jian","he","biao","bo","cheng","xian","jing","zhen","zhen","zhuang","hui","si","qun","hao","xin","bang","cheng","le","shao","gong","song","shan","hou","qing","lei","min","you","yu","he","zhe","jiang","chao","hao","liang","zheng","qian","heng","qi","gu","zhi","lun","han","lang","bo","hong","yan","ruo","ming","peng","bin","liang","dong","wei","qi","ke","lun","xiang","xu","peng","ze","chen","chen","shi","yi","jian","jia","zhi","shu","yan","de","xing","shi","tai","sheng","xiu","juan","ying","hua","hui","qiao","mei","na","jing","shu","hui","zhu","cui","ya","zhi","yu","ping","hong","e","ling","fen","fang","yan","cai","chun","ju","lan","feng","jie","mei","lin","su","yun","lian","zhen","huan","xue","rong","ai","mei","xia","xiang","yue","ying","yuan","yan","rui","fan","jia","jia","qiong","qin","zhen","zhen","li","gui","di","ye","bi","lu","ya","qi","jing","yan","xi","qiu","shan","sha","jin","dai","qing","qing","ting","jiao","wan","xian","jin","ying","lu","yao","yi","chan","yan","bei","wan","yi","he","dan","rong","mei","jun","qin","rui","wei","jing","meng","lan","yuan","jun","rou","zhu","ai","ning","xiao","huan","xiao","feng","yun","fei","han","xin","ying","yi","ya","yi","ke","ji","shu","ying","li","zhi","si","li","xiu","piao","yu","fu","qi","jing","yan","xi","qiu","shan","sha","jin","dai","qing","qing","ting","ning","bei","wan","yuan","jie","xin","yuan","yan","yun","rong","yuan","yi","yong","qing","cong","lan","chun","yu","yue","zhao","bing","shuang","wan","ming","yu","xi"};
char hashmap1[26*26*26+26*26+26+3000][12];
char hashmap2[10000][12];
char hashmap3[3000][12];
char hashmap4[3000][12];
void makeName()
{
    srand((int)time(0));//让我们的随机数根据系统时间变化
    FILE *fp;//建立一个文件操作指针
    if ( (fp=fopen("name.txt","w+"))==NULL)     // 以追加只写模式打开文件操作
    {
        printf("File open error!\n");
    }
    for(int i = 0; i<3000; i++)
    {
        int a = rand()%444;//用来作为姓氏的数组索引
        int b = rand()%305;//用来作为名字的数组索引
        char tempName[12];
        strcpy(tempName,name0[a]);//将随机的姓复制到tempName中
        strcat(tempName,name1[b]);//将随机的名复制到tempName中
        fprintf( fp, "%s\n", tempName  );//将tempName写入文件
    }
    fclose(fp);//关闭文件操作
}

//直接取址法
//(名字第一个字母-'a')*26*26+(名字倒数第二个字母-'a')*26+(名字倒数第一个字母-'a')
void myHash1()
{
    memset(hashmap1,0,sizeof(hashmap1));//将hashmap1字符串数组中所有的字符串置为空
    FILE *fpRead;
    if ( (fpRead=fopen("name.txt","r"))==NULL)     // 打开文件
    {
        printf("File open error!\n");
    }
    char a[12];
    for(int i = 0; i<3000; i++)
    {
        fscanf(fpRead,"%s",&a);//读取name.txt文件的一行给字符串数组a
        int k = (a[0]-'a')*26*26 + (a[strlen(a)-2]-'a')*26 + (a[strlen(a)-1]-'a');
        int index = k;
        while(hashmap1[index][0]!='\0')
        {
            index++;
        }
        strcpy(hashmap1[index],a);//将读取到的a存入hashmap1的该位置
    }
}


int myHash1Find(char* a) //存在返回查找次数，不存在返回0
{
    int k = (a[0]-'a')*26*26 + (a[strlen(a)-2]-'a')*26 + (a[strlen(a)-1]-'a');
    int temp = k;
    while(1)
    {
        if(strcmp(hashmap1[temp],a)==0)
        {
            return temp-k+1;
        }
        else if(strlen(hashmap1[temp])!=0)
        {
            temp++;
        }
        else
        {
            return 0;
        }
    }
    return temp-k+1;
}

long long int getDigit(long long int num)//用来计算数字的位数的函数
{
    int count = 0;
    while(num!=0)
    {
        num = num / 10;
        count++;
    }
    return count;
}

//平方取中法
void myHash2()
{
    memset(hashmap2,0,sizeof(hashmap2));//将hashmap2字符串数组中所有的字符串置为空
    FILE *fpRead;
    if ( (fpRead=fopen("name.txt","r"))==NULL)     // 打开文件
    {
        printf("File open error!\n");
    }
    char a[12];
    int index = 0;
    for(int i = 0; i<3000; i++)
    {
        fscanf(fpRead,"%s",&a);//读取name.txt文件的一行给字符串数组a
        long long int k = (a[0]-'a')*26*26 + (a[strlen(a)-2]-'a')*26 + (a[strlen(a)-1]-'a');
        k = k*k;//平方
        if(k<10000)
        {
            index = k;
        }
        else//取中
        {
            int dight = getDigit(k);
            for(int i = 0; i<(dight-4)/2 ; i++)
            {
                k = k/10;
            }
            index = k%10000;
        }
        while(hashmap2[index][0]!='\0')
        {
            index++;
        }
        strcpy(hashmap2[index],a);//将a存到对应的位置
    }
}

int myHash2Find(char* a) //存在返回查找此时，不存在返回0
{
    long long int k = (a[0]-'a')*26*26 + (a[strlen(a)-2]-'a')*26 + (a[strlen(a)-1]-'a');
    int temp ;
    k = k*k;//平方
    if(k<10000)
    {
        temp = k;
    }
    else//取中
    {
        int dight = getDigit(k);//计算大数k的位数，根据位数来取中间4位数
        for(int i = 0; i<(dight-4)/2 ; i++)
        {
            k = k/10;
        }
        temp = k%10000;
    }
    int num = temp;
    while(1)
    {
        if(strcmp(hashmap2[temp],a)==0)
        {
            return temp-num+1;
        }
        else if(strlen(hashmap2[temp])!=0)
        {
            temp++;
        }
        else
        {
            return 0;
        }
        k++;
    }
}

//除留余数法,取素数2777
void myHash3()
{
    int count = 0;
    memset(hashmap3,0,sizeof(hashmap3));//将hashmap3字符串数组中所有的字符串置为空
    memset(hashmap4,0,sizeof(hashmap4));//将hashmap4字符串数组中所有的字符串置为空
    FILE *fpRead;
    if ( (fpRead=fopen("name.txt","r"))==NULL)     // 打开文件
    {
        printf("File open error!\n");
    }
    char a[12];
    int index = 0;
    for(int i = 0; i<3000; i++)
    {
        fscanf(fpRead,"%s",&a);//读取name.txt文件的一行给字符串数组a
        int k = (a[0]-'a')*26*26 + (a[strlen(a)-2]-'a')*26 + (a[strlen(a)-1]-'a');
        index = k%2777;
        if(strlen(hashmap3[index])==0)
        {
            strcpy(hashmap3[index],a);//如果不存在字符串，放进hashmap3对应位置
        }
        else
        {
            strcpy(hashmap4[count],a);//否则放到hashmap4字符串数组中
            count++;
        }
    }
}

int myHash3Find(char* a) //存在返回查找此时，不存在返回0
{
    int k = (a[0]-'a')*26*26 + (a[strlen(a)-2]-'a')*26 + (a[strlen(a)-1]-'a');
    int temp = k%2777;
    if(strcmp(hashmap3[temp],a)==0)
    {
        return 1;
    }
    else
    {
        int count = 0;
        while(strlen(hashmap4[count])!=0)
        {
            if(strcmp(hashmap4[count],a)==0)
            {
                return count+1;
            }
            count++;
        }
        return 0;
    }

}

void compareHash() //比较平均查找长度
{
    double hash1Count = 0;//用来存储使用hash1查找函数时用的次数和
    double hash2Count = 0;//用来存储使用hash2查找函数时用的次数和
    double hash3Count = 0;//用来存储使用hash3查找函数时用的次数和
    FILE *fpRead;
    if ( (fpRead=fopen("name.txt","r"))==NULL)     // 打开文件
    {
        printf("File open error!\n");
    }
    char a[12];

    for(int i = 0; i<3000; i++)
    {
        fscanf(fpRead,"%s",&a);//读取name.txt文件的一行给字符串数组a

        hash1Count = hash1Count + myHash1Find(a);
        hash2Count = hash2Count + myHash2Find(a);
        hash3Count = hash3Count + myHash3Find(a);
    }
    printf("hash1算法查找3000个名字的总查找次数为:%.2f\n",hash1Count/3000.00);
    printf("hash2算法查找3000个名字的总查找次数为:%.2f\n",hash2Count/3000.00);
    printf("hash3算法查找3000个名字的总查找次数为:%.2f\n",hash3Count/3000.00);
}

int main()
{
    makeName();//随机生成姓名并保存在同目录下的name.txt
    myHash1();//使用第1种hash函数将name.txt中的姓名读取并保存到hashmap1中
    myHash2();//使用第2种hash函数将name.txt中的姓名读取并保存到hashmap2中
    myHash3();//使用第3种hash函数将name.txt中的姓名读取并保存到hashmap3和hashmap4中
    compareHash();//比较平均查找长度

}
