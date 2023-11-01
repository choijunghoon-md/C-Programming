#include<iostream>
#include<vector>
using namespace std;

int main(void) {
    vector<string> v;

    v.push_back("Show Me");
    v.push_back("Tiger JK");
    v.push_back("Dok2");
    v.push_back("GAEKO");
    v.push_back("ZICO");

    //ex4) v.front(), v.back() 
    cout << "//ex4) v.front(), v.back()" << endl;

    cout << "v.front() : " << v.front() << endl;
    cout << "v.end() : " << v.back() << endl;
    cout << endl;




    //ex5) v.popback()
    cout << "//ex5) v.popback()" << endl;

    vector<string>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " / ";
    }
    cout << endl;

    v.pop_back();

    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " / ";
    }
    cout << endl;
    cout << endl;




    //ex6) v.erase(iter);
    cout << "//ex6) v.erase(iter)" << endl;

    for (iter = v.begin(); iter != v.end(); iter++) {
        if (*iter == "Dok2") {
            v.erase(iter);
            break;
        }
    }
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " / ";
    }



    cout << endl << endl;
    //ex7) v.size(), v.capacity();
    cout << "//ex7) v.size(), v.capacity()" << endl;

    cout << "v.size() : " << v.size() << endl;
    cout << "v.capacity() : " << v.capacity() << endl;

    return 0;
}


void vecotor1() {
    vector<int> v;

    cout << "[ v[i] , v.size(), v.capacity() ] " << endl;
    for (int i = 0; i <= 64; i++) {
        v.push_back(i + 1);
        cout << "[" << v[i] << " , " << v.size() << " , " << v.capacity() << "]" << endl;
    }
}

void vecotor2() {
    vector<int> v;

    v.push_back(21);
    v.push_back(32);
    v.push_back(53);
    v.push_back(64);
    v.push_back(15);


    //ex1) 멤버형식 size_type 이용한 반복.
    cout << "ex1-1) [v.at(i)] size_type : ";
    for (vector<int>::size_type i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "ex1-1) [ v[i] ] size_type : ";
    for (vector<int>::size_type i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;


    //ex2) int i 를 이용한 반복.
    cout << "ex2-1) [v.at(i)] int : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "ex2-2) [ v[i] ] int : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;


    //ex3) 반복자 iterator를 이용한 반복. 
    cout << "ex3) [*iter] iterator : ";
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl << endl;
}