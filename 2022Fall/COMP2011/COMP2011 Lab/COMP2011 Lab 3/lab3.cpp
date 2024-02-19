#include <iostream>
#include <fstream>

using namespace std;

// Do not change this function. It is used for checking the lab.
void prepare_files(){
    ofstream ofs ("student_list.txt");

    if (ofs){
        ofs << 20185639 << endl;
        ofs << 22435497 << endl;
        ofs << 23143658 << endl;
        ofs << 29372413 << endl;
        ofs << 29567638 << endl;
        ofs << 29576389 << endl;
    }
}


// Do not change this function. It is used for checking the lab.
void check_final_list(){
    ifstream ifs ("student_list.txt");
    if (ifs){
        int line;
        while (ifs >> line){
            cout << line << endl;
        }
        ifs.close();
    }
}


// TODO: search for a student in the input file, student_list.txt, return true if found.
bool student_lookup(int student_id){
    ifstream ifs ("student_list.txt");
    int c;
    while (!ifs.eof()){
        ifs >> c;
        if (c == student_id) {return 1;}
    }
    return 0;
}


// TODO: delete a student id from the input file.
// The result should not contain blank lines
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void delete_student(int student_id){
    if (student_lookup(student_id)){
        ifstream ifs ("student_list.txt");
        ofstream ofs ("temp.txt");
        int c = 0;
        int d = 0;
        int line;
        while (ifs >> line){
            c++;
        }
        ifs.close();
        ifs.open("student_list.txt");
        for (int i = 0; i <c; i++){
            ifs >> d;
            if (student_id == d)
                continue;
            else
                ofs << d << endl;
        }
        ifs.close(); ofs.close();
        remove("student_list.txt");
        rename("temp.txt", "student_list.txt");
        cout << "Student " << student_id << " is removed from the course!" << endl;
    }else{
        cout << "Student " << student_id << " is not taking the course!" << endl;
    }
}


// TODO: insert a student in the input file such that the student ids are in ascending order
// It should not insert duplicate student id.
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void insert_student(int student_id){
    if (student_lookup(student_id)){
        cout << "Student " << student_id << " is already taking the course!" << endl;
    }else{
        ifstream ifs ("student_list.txt");
        ofstream ofs ("temp.txt");
        int c = 0;
        int d = 0;
        int line;
        while (ifs >> line){
            c++;
        }
        ifs.close();
        ifs.open("student_list.txt");
        int temp = student_id;
        for (int i = 0; i <c; i++){
            ifs >> d;
            if (temp < d){
                ofs << temp << endl;
                ofs << d << endl;
                temp = 100000000;
            }else
                ofs << d << endl;
        }
        ifs.close(); ofs.close();
        remove("student_list.txt");
        rename("temp.txt", "student_list.txt");
        cout << "Student " << student_id << " is inserted successfully!" << endl;
    }
}

int main(){

    const char filename[] = "student_list.txt";
    char choice;
    int student_id;

    prepare_files();

    while (true){       

        cout << "1 for lookup; 2 for insertion; 3 for deletion; q for quit: ";
        cin >> choice;

        if (choice == '1'){
            cout << "Please enter the id of the student you want to search for: ";
            cin >> student_id;
            if (student_lookup(student_id)){
                cout << "Student " << student_id << " is found!" << endl;
            }else{
                cout << "Student " << student_id << " is not found!" << endl;
            }
        }else if (choice == '2'){
            cout << "Please enter the id of the student you want to insert: ";
            cin >> student_id;
            insert_student( student_id);
        }else if (choice == '3'){
            cout << "Please enter the id of the student you want to delete: ";
            cin >> student_id;
            delete_student(student_id);
        }else if (choice == 'q'){
            check_final_list();
            break;
        }else{
            cout << "Invalid input. Please input again." << endl;
        }
        cout << endl;
    }

    return 0;
}