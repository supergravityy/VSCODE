#include "Try32.h"

int BANKS_INFO::Change_Bank_LOG(BANKS_INFO &bank_info, bank_id dst_bank, char mode )
{
    if(mode == 'A') // �߰����
    {
        if(!(this->Confirm_Bank_LOG(bank_info,dst_bank))) // ����� �Ѵ�
        {
            printf("�� ������ �α׿� �߰��Ͽ����ϴ�!\n");
        }

        else // �߰��Ϸ��µ� �̹� ������ ����
        {
            printf("�̹� ������ �ֽ��ϴ�!\n");
            return 2; 
        }
        
    }

    else if(mode == 'D') // �������
    {
        if(this->Confirm_Bank_LOG(bank_info,dst_bank)) // �־�� �Ѵ�
        {

        }

        else
        {
            printf("������ �����ϴ�!\n");
            return 1; // ����Ϸ��µ� ������ ����
        }

        
    }

    else // ��ȿ�������� ���
    {
        printf("��ȿ���� ���� ����Դϴ�\n");
        return 0; // ��ȿ���� ���� ���
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