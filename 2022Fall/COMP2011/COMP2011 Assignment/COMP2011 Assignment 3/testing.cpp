#include <iostream> /* File: ll_cnode.h */
#include <cstring>
using namespace std;
// constants
const int MAX_CODE = 10; // at most 10 characters (including the NULL character)
const int MAX_TITLE = 100; // at most 100 characters (including the NULL character)
struct CourseItem; // needed because Course needs to refer to CourseItem*
// A sorted linked list of Course. List items are sorted by the course code
struct Course {
    char code[MAX_CODE];        // course code
    char title[MAX_TITLE];      // course title
    int credit;                 // course credit
    Course* next;               // a pointer pointing to the next Course
    CourseItem* exclusions;     // a sorted linked list of CourseItem
    CourseItem* prerequisites;  // a sorted linked list of CourseItem
};
// A sorted linked list of CourseItem. List items are sorted by course->code
struct CourseItem {
    Course *course;             // pointing to the course
    CourseItem *next;           // a pointer pointing to the next CourseItem
};

void ll_print_all(const Course* head); // given, you cannot make any changes


int enter_credit() {
    int credit;
    while (true) {
        cout << "Enter the credit: " ;
        cin >> credit;
        if ( credit >= 0 )
            return credit;
        cout << "Invalid credit: " << credit << endl;
    }
}


int main()  // Create the LL-string "met"
{   // Create each of the 3 ll_cnodes
    char title[10] = "abcd";
    char yeah[10];
    cout << title << endl;
    memcpy(yeah, title, 10 * sizeof(char));
    cout << yeah << endl;
    // Course *clist = nullptr;
    // ll_print_all(clist);

    // int option = 0;
    // int i = 0;
    // int credit = 0;
    // // It is tricky to check the input character array, write assumptions that we don't need to check
    // char code[MAX_CODE] = ""; 
    // char title[MAX_TITLE] = "" ;
    // char targetCode[MAX_CODE] = "";
   
    // cout << "Enter a course code: ";
    // cin >> code;
    // cout << "Enter a course title: ";
    // cin.ignore(); // necessary when mixing cin>> and cin.getline
    // cin.getline(title, MAX_TITLE);
    // credit = enter_credit();
    // // cout << code << endl;
    // // cout << title << endl;
    // // cout << credit << endl;
    // clist-> next = clist;
    // memcpy(clist->code, code, MAX_CODE * sizeof(char)); 
    // memcpy(clist->title, title, MAX_TITLE * sizeof(char)); 
    // cout << clist->code << endl;
    // clist->credit = credit;
    // clist->exclusions = nullptr;
    // clist->prerequisites = nullptr;    
    // ll_print_all(clist);

}



// This function is given
// DO NOT MODIFY THIS FUNCTION
// Otherwise, you may not be able to pass the ZINC test cases
void ll_print_all(const Course* head) {
    const Course *p;
    const CourseItem *q;
    int count;

    cout << "=== Course List (Code[Credits]) ===" << endl;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        cout << p->code << "[" << p->credit << "]" ;
        if ( p->next != nullptr )
            cout << " -> ";
        count++;
    }
    if ( count == 0 ) {
        cout << "No courses in the list";
    }
    cout << endl;

    cout << "=== Course titles ===" << endl ;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        cout << p->code << ": " << p->title << endl ;
        count++;
    }
    if ( count == 0 ) {
        cout << "No course titles" << endl;
    }

    cout << "=== Pre-requisites ===" << endl ;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        q = p->prerequisites;
        if ( q != nullptr ) {
            cout << p->code << ": ";
            for ( ; q != nullptr; q = q->next ) {
                cout << q->course->code ;
                if ( q->next != nullptr )
                    cout << ", " ;
            }
            count++;
            cout << endl;
        }
    }
    if ( count == 0 ) {
        cout << "No pre-requisites" << endl;
    }

    cout << "=== Exclusions ===" << endl ;
    count = 0;
    for (p = head; p!= nullptr; p = p->next) {
        q = p->exclusions;
        if ( q != nullptr ) {
            cout << p->code << ": ";
            for ( ; q != nullptr; q = q->next ) {
                cout << q->course->code ;
                if ( q->next != nullptr )
                    cout << ", " ;
            }
            count++;
            cout << endl;
        }
    }
    if ( count == 0 ) {
        cout << "No pre-exclusions" << endl;
    }

}
