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
    int line;
    ifstream ifs ("student_list.txt");
    if (ifs){
        while (ifs >> line){
            if (student_id == line){
                return true;
            }
        } 
        ifs.close();
    }else{
        cerr << "Error: student_list.txt cannot be found!" << endl;
        exit(1); // indicate an abnormal termination of the program
    }

    return false;
}


// TODO: delete a student id from the input file.
// The result should not contain blank lines
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void delete_student(int student_id){
    if (!student_lookup(student_id)){
        cout << "Student " << student_id << " is not taking the course!" << endl;
        return;
    }

    int line;
    ifstream ifs ("student_list.txt");

    if (ifs){
        ofstream ofs ("temp.txt");
        if (ofs){

            while (ifs >> line){
                if (student_id != line){
                    ofs << line << endl;
                }
            }

            ifs.close();
            ofs.close();

            if (remove("student_list.txt") != 0){
                cerr << "Error: Can't delete student_list.txt" << endl;
                exit(1); // indicate an abnormal termination of the program
            }else{
                if (rename("temp.txt", "student_list.txt") != 0){
                    cerr << "Error: Can't rename file" << endl;
                    exit(1); // indicate an abnormal termination of the program
                }else{
                    cout << "Student " << student_id << " is removed from the course!" << endl;
                }
            }
        }else{
            cerr << "Error: Can't open temp.txt" << endl;
            exit(1); // indicate an abnormal termination of the program
        }
    }else{
        cerr << "Error: Can't open student_list.txt" << endl;
        exit(1); // indicate an abnormal termination of the program
    }
}


// TODO: insert a student in the input file such that the student ids are in ascending order
// It should not insert duplicate student id.
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void insert_student(int student_id){
    if (student_lookup(student_id)){
        cout << "Student " << student_id << " is already taking the course!" << endl;
        return;
    }
    ifstream ifs ("student_list.txt");

    if (ifs){
        ofstream ofs ("temp.txt");
        if (ofs){

            int last = 0;
            int line;
            while (ifs >> line){
                if ((student_id > last) && (student_id < line) ){
                    ofs << student_id << endl;
                }
                last = line;
                ofs << line << endl;
            }
            if (student_id> last) {
                ofs << student_id << endl;
            }

            ifs.close();
            ofs.close();

            if (remove("student_list.txt") != 0){
                cerr << "Error: Can't delete student_list.txt" << endl;
                exit(1);
            }else{
                if (rename("temp.txt", "student_list.txt") != 0){
                    cerr << "Error: Can't rename file" << endl;
                    exit(1);
                }else{
                    cout << "Student " << student_id << " is inserted successfully!" << endl;
                }
            }
        }else{
            cerr << "Error: Can't open temp.txt" << endl;
            exit(1);
        }
    }else{
        cerr << "Error: Can't open student_list.txt" << endl;
        exit(1);
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
