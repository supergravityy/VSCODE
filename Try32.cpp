#include "Try32.h"

int BANKS_INFO::Change_Bank_LOG(BANKS_INFO &bank_info, bank_id dst_bank, char mode )
{
    if(mode == 'A') // 추가모드
    {
        if(!(this->Confirm_Bank_LOG(bank_info,dst_bank))) // 없어야 한다
        {
            printf("새 지점을 로그에 추가하였습니다!\n");
        }

        else // 추가하려는데 이미 정보가 있음
        {
            printf("이미 정보가 있습니다!\n");
            return 2; 
        }
        
    }

    else if(mode == 'D') // 삭제모드
    {
        if(this->Confirm_Bank_LOG(bank_info,dst_bank)) // 있어야 한다
        {

        }

        else
        {
            printf("정보가 없습니다!\n");
            return 1; // 기능하려는데 정보가 없음
        }

        
    }

    else // 유효하지않은 모드
    {
        printf("유효하지 않은 기능입니다\n");
        return 0; // 유효하지 않은 모드
    }
    
}

int BANKS_INFO::Confirm_Bank_LOG(BANKS_INFO &bank_info, bank_id dst_bank)
{

}

int BANKS_INFO::Change_Cli_LOG(CLI_INFO &cli_info, char mode)
{

}

int BANKS_INFO::Confirm_Cli_LOG(CLI_INFO& cli_info)
{

}


int CLI_INFO::Account_Transfer(bank_acc dst_account, char * dst_name, CLI_INFO &my_info, int money)
{

}

bank_acc* CLI_INFO::Find_My_Account(client_id my_id, char *my_name)
{

}

int CLI_INFO::Make_Account(CLI_INFO &my_info,BANKS_INFO &bank, bank_id agency_id)
{
    
}