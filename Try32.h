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
// 자료형은 소문자로

class CLI_INFO // 클래스는 대문자로
{
private: // 클래스 외부에서 접근 불가

    client_id cli_ID;
    char Name[100+1];
    int Age;
    bank_acc Bank_Acc;
    char Phone[11+1];
    bank_id Bank_ID; // 내부 멤버는 앞에만 대문자로
    
public: // 클래스 외부에서 접근가능

    // 기능추가
    bank_acc* Find_My_Account(client_id my_id, char *my_name);
    // 내부에서 동적할당으로 계좌를 만들어 준다음 콜러쪽에서 memcpy로 복사후, 콜리가 한 동적할당을 free할것
    int Make_Account(CLI_INFO &my_info,BANKS_INFO &bank, bank_id agency_id);
    // 됬냐 안됬냐?
    int Account_Transfer(bank_acc dst_account, char * dst_name, CLI_INFO &my_info, int money);
    // 상대 이름,계좌번호, 내 정보클래스 -> 됬냐 안됬냐?
};

class BANKS_INFO
{
private:

    vector<bank_id> Bank_IDs; // 은행들을 자료형으로 선언하면? 벡터로 가능
    char Region[100+1];
    vector<client_id> Clis_IDs;
    int Cli_Num;
    int Activate_Account_Num;

public:
    int Confirm_Cli_LOG(CLI_INFO &cli_info);
    // 됬냐 안됬냐?
    int Change_Cli_LOG(CLI_INFO &cli_info, char mode);
        // this->Confirm_Cli_LOG; // this라는 키워드는 이 클래스안의 메소드라는걸 표시하기 위함

    // 모드를 입력받고, 검색후 추가 동작 여부 판단, 그에따른 기능실행 () -> 오류코드 반환
    int Confirm_Bank_LOG(BANKS_INFO &bank_info, bank_id dst_bank);
    // 됬냐 안됬냐?
    int Change_Bank_LOG(BANKS_INFO &bank_info, bank_id dsst_bank, char mode );
    // 됬냐 안됬냐?
};

#endif // _BANK_H