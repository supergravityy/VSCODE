#ifndef FUNC1_H
#define FUNC1_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

struct stdINFO
{
    int stdNo, stdAge, stdAge_ko;
    string stdName, stdBirth;

    stdINFO() : stdNo(0), stdAge(0), stdAge_ko(0) {}
    // ???
};

void Check_Birth_Input(vector <stdINFO>& stdInfoVec, int i);
void CalAge_and_Input(vector<stdINFO>& stdInfoVec, int i);

void Select_StudentInfo(int i, vector<stdINFO>& stdInfoVec);
void Select_StudentAVG(int i, vector<stdINFO>& stdInfoVec);
void Select_StudentBirthDay(int i, vector<stdINFO>& stdInfoVec);
void Select_editing(int i, int Num, vector<stdINFO>& stdInfoVec);

void Print_Student_Info(vector<stdINFO> stdInfoVec, int i);
double Cal_Student_AgeAVG(vector<stdINFO> stdInfoVec, bool useKoreanAge);
void Print_EarlyBirth_Student(vector<stdINFO> stdInfoVec, bool useYear);

#endif 