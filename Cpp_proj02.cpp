#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void print_words(vector<string> &words)
{
    cout << words[0];

    for(int i = 1; i < words.size(); i++)
    {
        cout << "->" << words[i];
    }

    cout << endl << endl;
}

int is_connected(string &last_word, string &new_word)
{
    if(last_word.back() == new_word.front())
        return 1;

    else 
        return 0;
}

int is_unique(vector<string> &wordVec, string &new_word)
{
    for(int i =0; i<wordVec.size(); i++)
        if(wordVec[i] == new_word)
            return 0;
    
    return 1;
}

int main()
{
    vector<string> Words;

    string A_word = "airplane"; // 첫 단어
    Words.push_back(A_word);


    clock_t startTime = clock();
    clock_t currentTime;
    clock_t diffTime;
    while(1)
    {
        currentTime = clock();
        diffTime = currentTime-startTime;
        // 시간초 분석 30초가 지나면 while문 탈출

        if((diffTime/CLOCKS_PER_SEC) > 30.0)
            break;

        print_words(Words);

        while(1) // 유효한 입력받기
        {
            cout << "input valid word : ";

            cin >> A_word;

            if(is_connected(Words.back(),A_word) && is_unique(Words,A_word))
            {
                Words.push_back(A_word);
                break;
            }

            else
            {
                cout << "\nInvalid word!" << endl;
            }
        }
    }

    cout << "\nTime over" <<endl;
    cout << "total num of words (" << Words.size() << ")" <<endl;

    return 0;
}