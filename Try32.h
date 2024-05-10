#ifndef _BANK_H
#define _BANK_H

#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;

typedef char client_id[30+1];
typedef char bank_id[20+1];
typedef char bank_acc[14+1];
// �ڷ����� �ҹ��ڷ�

class CLI_INFO // Ŭ������ �빮�ڷ�
{
private: // Ŭ���� �ܺο��� ���� �Ұ�

    client_id cli_ID;
    char Name[100+1];
    int Age;
    bank_acc Bank_Acc;
    char Phone[11+1];
    bank_id Bank_ID; // ���� ����� �տ��� �빮�ڷ�
    
public: // Ŭ���� �ܺο��� ���ٰ���

    // ����߰�
    bank_acc* Find_My_Account(client_id my_id, char *my_name);
    // ���ο��� �����Ҵ����� ���¸� ����� �ش��� �ݷ��ʿ��� memcpy�� ������, �ݸ��� �� �����Ҵ��� free�Ұ�
    int Make_Account(CLI_INFO &my_info,BANKS_INFO &bank, bank_id agency_id);
    // ��� �ȉ��?
    int Account_Transfer(bank_acc dst_account, char * dst_name, CLI_INFO &my_info, int money);
    // ��� �̸�,���¹�ȣ, �� ����Ŭ���� -> ��� �ȉ��?
};

class BANKS_INFO
{
private:

    vector<bank_id> Bank_IDs; // ������� �ڷ������� �����ϸ�? ���ͷ� ����
    char Region[100+1];
    vector<client_id> Clis_IDs;
    int Cli_Num;
    int Activate_Account_Num;

public:
    int Confirm_Cli_LOG(CLI_INFO &cli_info);
    // ��� �ȉ��?
    int Change_Cli_LOG(CLI_INFO &cli_info, char mode);
        // this->Confirm_Cli_LOG; // this��� Ű����� �� Ŭ�������� �޼ҵ��°� ǥ���ϱ� ����

    // ��带 �Է¹ް�, �˻��� �߰� ���� ���� �Ǵ�, �׿����� ��ɽ��� () -> �����ڵ� ��ȯ
    int Confirm_Bank_LOG(BANKS_INFO &bank_info, bank_id dst_bank);
    // ��� �ȉ��?
    int Change_Bank_LOG(BANKS_INFO &bank_info, bank_id dsst_bank, char mode );
    // ��� �ȉ��?
};

#endif // _BANK_H