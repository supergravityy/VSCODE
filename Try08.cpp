#include <iostream>

int main()
{
    int sum = 0;
    int n;

    while(1)
    {
        std::cout<<"input Number : ";
        std::cin>>n;
        
        if(n == 0)
            break;
        
        sum += n;
    }
    std::cout<<"Sum : "<<sum<<std::endl;

    std::cout<<"How many do you wanna make triangle of star? : ";
    std::cin >> n;
    std::cout<<"star triangle : \n\n";
    for(int i =1; i<=n;i++)
    {
        for(int j =1; j<=i;j++)
        {
            std::cout<<'*';
        }
        std::cout<<'\n';
    }


    return 0;
}