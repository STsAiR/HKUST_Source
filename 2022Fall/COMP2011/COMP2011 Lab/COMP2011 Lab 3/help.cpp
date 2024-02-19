#include <iostream>     /* File: filecopy.cpp */
#include <fstream>
using namespace std;	
int main()
{
    ifstream ifs ("student_list.txt");
    ofstream ofs ("temp.txt");
    int d;
    for (int i = 0; i < 10; i++){
        ifs >> d ;
        if (d == 4){
            continue;
        }
        else{
            ofs << d << endl;
        }
    }
    ifs.close(); ofs.close();
    remove("student_list.txt");
    rename("temp.txt", "student_list.txt");

            if (student_id < d){
                ofs << student_id << endl;
            }
            else{
                ofs << d << endl;
            }
        for (int i = 0; i <=c; i++){
            ifs >> d;
            cout << d << endl;
        }
        

}



    if (student_lookup(student_id)){
        cout << "Student " << student_id << " is already taking the course!" << endl;
    }else{
        cout << "Student " << student_id << " is inserted successfully!" << endl;
    }
1
2
3

7
9
10