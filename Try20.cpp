#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> List = {5,4,3,4,2,1,1};

    int cnt = 0;

    for(auto element : List)
        if(4==element)
            cnt++;
    
    cout << "Number of 4\'s int the List : " << cnt;

    List.sort();

    cout << "\n\nThe sorted out List" << endl;

    for(auto element : List)
        cout << element << " ";

    cout << "\n\nduplicates has been removed" << endl;

    List.unique();
    for(auto element : List)
        cout << element << " ";

    cout << "\n\nThe elements has been added after" << endl;
    List.push_back(6);
    List.push_back(7);

    for(auto element : List)
        cout << element << " ";

    cout << "\n\nThe elements has been added front" << endl;
    List.push_front(0);

    for(auto element : List)
        cout << element << " ";

    cout << "\n\nPrint specific elements" << endl;
    for(auto element : List)
        if(element >=3 && element <= 6)
            cout<< element << " ";


    return 0;
}