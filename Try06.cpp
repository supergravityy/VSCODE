#include<iostream>

int main()
{
    for(int i = 1; i<=9;i++)
    {
        std::cout<<"----"<<i<<"----"<<std::endl;

        for(int j = 0; j<=9;j++)
        {
            std::cout << i << " * " << j << " = " << i*j <<std::endl;
        }
    }

    return 0;
}