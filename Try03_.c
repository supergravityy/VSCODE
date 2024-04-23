#include <stdio.h>
#define NAME_LEN 30

int check_name(const char * name,const char * src)
{
    int i =0;
    while(*(name+i) != '\0' && *(src+i) != '\0')
    {
        if(*(name+i) != *(src+i)) 
            return 1;
        i++;
    }
        
    if(*(name+i) == '\0' || *(src+i)== '\0')
        return 1;
    

    return 0;
}

int main()
{
    puts("이름을 입력하시오 : ");
    char name[NAME_LEN];

    fgets(name,NAME_LEN,stdin);

    if(check_name(name,"홍길동"))
        puts("남자");

    else if(check_name(name,"성춘향"))
        puts("여자");

    else
        puts("모르겠음");

    return 0;
}

