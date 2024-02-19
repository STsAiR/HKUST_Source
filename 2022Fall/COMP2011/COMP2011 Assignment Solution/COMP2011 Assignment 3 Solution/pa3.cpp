// === Region: Project Overview ===
//
// Project TA: CHUNG, Peter (cspeter@cse.ust.hk)
// For code-level questions, please send a direct email to the above TA. 
// Asking questions with code in a discussion forum (e.g., Piazza) may cause plagiarism issues
// Usually, you will get the quickest response via a direct email.
//
// Assumptions:
// The course code is the unique key (i.e., there won't be duplicated course codes in the system). 
// This assumption is necessary for many operations (e.g., searching, insertions, and deletions, etc.)
//
// ================================= 

#include <iostream>
#include <cstring>
using namespace std;

// === Region: constants and structs ===
// The constants are structs are defined in this region
// ===================================

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
    CourseItem* prerequisites;  // a a sorted linked list of CourseItem
};
// A sorted linked list of CourseItem. List items are sorted by course->code
struct CourseItem {
    Course *course;             // pointing to the course
    CourseItem *next;           //  a pointer pointing to the next CourseItem
};

// === Region: function declarations ===
// The function declarations. 
// The implementation is done in the function definitions 
// ===================================


/**
 * function ll_create_course_item creates a new CourseItem and set its course attribute pointing to r
 * @param r a pointer to a Course
 * @return a pointer pointing to a new CourseItem
*/
CourseItem* ll_create_course_item(Course* r);

/**
 * function ll_create_course creates a new Course
 * @param c course code
 * @param t course title
 * @param credit course credit
 * @return a pointer pointing to a new Course 
*/
Course* ll_create_course(const char c[MAX_CODE], const char t[MAX_TITLE], int cred);

/**
 * function ll_search_course searches a course from a list
 * @param head pointing to the head of the linked list
 * @param c course code
 * @return nullptr if it is not found. Otherwise, return a valid Course* pointer 
*/
Course* ll_search_course(Course* head, const char c[MAX_CODE]);

/**
 * function ll_print_all prints the linked lists stored in the system
 * @param head pointing to the head of the linked list
*/
void ll_print_all(const Course* head); // given, you cannot make any changes

/**
 * function ll_insert_prerequisite inserts a pre-requisite
 * Example: if COMP2011 requires COMP1022P, the targetCode is COMP2011 and the preCode is COMP1022P
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param preCode stores the course code of the pre-requisite 
 * @return true if the insertion is complete. false otherwise
*/
bool ll_insert_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]);

/**
 * function ll_insert_exclusion inserts an exclusion
 * Example: if COMP2011 excludes COMP1022P, the targetCode is COMP2011 and the excludeCode is COMP1022P
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param excludeCode stores the course code to be excluded
 * @return true if the insertion is complete. false otherwise 
*/
bool ll_insert_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]);

/**
 * function ll_delete_prerequisite deletes a pre-requisite
 * Example: Given the input, if there is a pre-requisite, the pre-requisite will be deleted
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param preCode stores the course code of pre-requisite
 * @return true if the deletion is complete. false otherwise
*/
bool ll_delete_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]);

/**
 * function ll_delete_exclusion deletes an exclusion
 * Example: Given the input, if there is an exclusion, the exclusion will be deleted
 * @param head pointing to the head of the linked list
 * @param targetCode stores the course code of the target
 * @param excludeCode stores the course code of exclusion
 * @return true if the deletion is complete. false otherwise 
*/
bool ll_delete_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]);

/**
 * function ll_insert_course inserts a course
 * Note: head is passed by reference because head may be changed during the insertion
 * @param head pointing to the head of the linked list
 * @param c is the course code 
 * @param t is the course title
 * @param cred is the course credit
 * @return true if the insertion is complete. false otherwise
*/
bool ll_insert_course(Course* &head, const char c[MAX_CODE], const char t[MAX_TITLE], int cred);

/**
 * function ll_delete_course deletes an existing course
 * Note: head is passed by reference because head may be changed during the deletion
 * @param head pointing to the head of the linked list
 * @param c is the course code
 * @return true if the deletion is complete. false otherwise
*/
bool ll_delete_course(Course* &head, const char c[MAX_CODE]);

/**
 * function ll_modify_course_title modifies the course title attribute of a course
 * @param head pointing to the head of the linked list
 * @param c is the course code
 * @param t is the new course title
 * @return true if the modification is complete. false otherwise 
*/
bool ll_modify_course_title(Course* head, const char c[MAX_CODE], const char t[MAX_TITLE]);

/**
 * function ll_modify_course_credit modifies the course credit attribute of a course
 * @param head pointing to the head of the linked list
 * @param c is the course code
 * @param cred is the new credit
 * @return true if the modification is complete. false otherwise
*/
bool ll_modify_course_credit(Course* head, const char c[MAX_CODE], int cred);



/**
 * function ll_cleanup_all cleans up the linked lists used in the system. It restores the original states (i.e., empty linked lists) of the system. 
 * No memory leak should be found after the clean up
 * Note: head is passed by reference because head may be changed during the clean up
 * @param head pointing to the head of the linked list
*/
void ll_cleanup_all(Course* &head);

// === Region: The main() function ===
// The main function is given
// DO NOT MODIFY anything inside the main() function
// ===================================

/**
 * function enter_credit: A helper function to enter a valid credit
 * ensure the credit is a non-negative integer
*/
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

/**
 * function main - the main function
*/
int main() {
    Course *clist = nullptr;
    enum MeunOption {
        OPTION_DISPLAY_CURRENT_LIST = 0,
        OPTION_INSERT_COURSE,
        OPTION_INSERT_PRE_REQUISITE,
        OPTION_INSERT_EXCLUSION,
        OPTION_DELETE_COURSE,
        OPTION_DELETE_PRE_REQUISITE,
        OPTION_DELETE_EXCLUSION,
        OPTION_MODIFY_COURSE_TITLE,
        OPTION_MODIFY_COURSE_CREDIT,
        OPTION_EXIT_WITHOUT_CLEANUP,
        OPTION_EXIT_WITH_CLEANUP, 
        MAX_MENU_OPTIONS
    };
    const int MAX_MENU_OPTIONS_LENGTH = 50;
    char menuOptions[MAX_MENU_OPTIONS][MAX_MENU_OPTIONS_LENGTH] = {
        "Display the current list",
        "Insert a new course",
        "Insert a pre-requisite",
        "Insert an exclusion",
        "Delete an existing course",
        "Delete an existing pre-requisite",
        "Delete an existing exclusion",
        "Modify a course title",
        "Modify a course credit",
        "Exit without clean up",
        "Exit with clean up"
    };
    
    int option = 0;
    int i = 0;
    int credit = 0;
    // It is tricky to check the input character array, write assumptions that we don't need to check
    char code[MAX_CODE] = ""; 
    char title[MAX_TITLE] = "" ;
    char targetCode[MAX_CODE] = "";
   
    bool ret = false;
    
    while (true) {
        cout << "=== Menu ===" << endl;
        for (i=0; i<MAX_MENU_OPTIONS; i++) 
            cout << i+1 << ": " << menuOptions[i] << endl; // shift by +1 when display

        cout << "Enter your option: ";
        cin >> option;

        option = option - 1; // shift by -1 after entering the option

        // The invalid menu option handling
        if ( option < 0 || option >= MAX_MENU_OPTIONS ) {
            cout << "Invalid option" << endl;
            continue;
        }

        // Exit operations handling
        if (option == OPTION_EXIT_WITHOUT_CLEANUP)
            break; // break the while loop
        else if (option == OPTION_EXIT_WITH_CLEANUP) {
            cout << "=== Cleanup ===" << endl;
            ll_cleanup_all(clist);
            ll_print_all(clist);
            break; //  break the while loop
        }
        
        switch (option) {
            case OPTION_DISPLAY_CURRENT_LIST:
                ll_print_all(clist);
                break;
            case OPTION_INSERT_COURSE:
                cout << "Enter a course code: ";
                cin >> code;
                cout << "Enter a course title: ";
                cin.ignore(); // necessary when mixing cin>> and cin.getline
                cin.getline(title, MAX_TITLE);
                credit = enter_credit();
                ret = ll_insert_course(clist, code, title, credit);
                if ( ret == false ) {
                     cout << "Failed to insert " << code << endl ;
                }
                else {
                    cout << code << " is successfully inserted" << endl ;
                    ll_print_all(clist);
                }
                break;
            case OPTION_INSERT_PRE_REQUISITE:
                cout << "Enter the target course code: ";
                cin >> targetCode;
                cout << "Enter the pre-requisite course code: ";
                cin >> code;
                if ( strcmp(targetCode, code) == 0) {
                    cout << "Cannot insert a pre-requisite to the same course " << code << endl;
                } else {
                    ret = ll_insert_prerequisite(clist, targetCode, code);
                    if ( ret == false ) {
                        cout << "Failed to insert pre-requisite " << targetCode << ", " << code << endl;
                    } else {
                        cout << "Inserted a pre-requisite " << targetCode << ", " << code << endl;
                        ll_print_all(clist);
                    }
                }
                break;
            case OPTION_INSERT_EXCLUSION:
                cout << "Enter the target course code: ";
                cin >> targetCode;
                cout << "Enter the exclusion course code: ";
                cin >> code;
                if ( strcmp(targetCode, code) == 0) {
                    cout << "Cannot insert an exclusion to the same course " << code << endl;
                } else {
                    ret = ll_insert_exclusion(clist, targetCode, code);
                    if ( ret == false ) {
                        cout << "Failed to insert exclusion " << targetCode << ", " << code << endl;
                    } else {
                        cout << "Inserted an exclusion " << targetCode << ", " << code << endl;
                        ll_print_all(clist);
                    }
                }
                break;
            case OPTION_DELETE_COURSE:
                cout << "Enter the course code: ";
                cin >> code ;
                ret = ll_delete_course(clist, code);
                if ( ret == false ) {
                    cout << "Failed to delete course " << code << endl;
                } else {
                    cout << "Deleted a course " << code << endl ;
                    ll_print_all(clist);
                }
                break;
            case OPTION_DELETE_PRE_REQUISITE:
                 cout << "Enter the target course code: ";
                cin >> targetCode;


                cout << "Enter the pre-requisite course code: ";
                cin >> code;
                ret = ll_delete_prerequisite(clist, targetCode, code);
                if ( ret == false ) {
                    cout << "Failed to delete pre-requisite " << targetCode << ", " << code << endl;
                } else {
                    cout << "Deleted a pre-requisite " << targetCode << ", " << code << endl;
                    ll_print_all(clist);
                }
                break;
            case OPTION_DELETE_EXCLUSION:
                cout << "Enter the target course code: ";
                cin >> targetCode;

                // Note: fixed a minor typo: pre-requisite => exclusion
                // As students are not required to change the main(), and 
                // a student reported this problem late, so this typo is not fixed in the ZINC grading
                cout << "Enter the exclusion course code: ";
                cin >> code;
                ret = ll_delete_exclusion(clist, targetCode, code);
                if ( ret == false ) {
                    cout << "Failed to delete exclusion " << targetCode << ", " << code << endl;
                } else {
                    cout << "Deleted an exclusion " << targetCode << ", " << code << endl;
                    ll_print_all(clist);
                }
                break;
            case OPTION_MODIFY_COURSE_TITLE:
                cout << "Enter the course code: ";
                cin >> code;
                cout << "Enter the new course title: " ;
                cin.ignore();
                cin.getline(title, MAX_TITLE);
                ret = ll_modify_course_title(clist, code, title);
                if ( ret == false ) {
                    cout << "Failed to modify the course title of " << code << endl ;
                } else {
                    cout << "The course title of " << code << " is modified" << endl ;
                    ll_print_all(clist);
                }
                break;
            case OPTION_MODIFY_COURSE_CREDIT:
                cout << "Enter the course code: ";
                cin >> code ;
                credit = enter_credit();
                ret = ll_modify_course_credit(clist, code, credit);
                if ( ret == false ) {
                    cout << "Failed to modify the course credit of " << code << endl;
                } else {
                    cout << "The course credit of " << code << " is modified" << endl;
                    ll_print_all(clist);
                }
                break;
                
        } // end switch

    } // end while true
    return 0;
}


// === Region: function definitions ===
// You should implement the functions below
// ====================================


CourseItem *ll_create_course_item(Course* r) {
    CourseItem *newCourseItem = new CourseItem;
    newCourseItem->course = r;
    newCourseItem->next = nullptr;
    return newCourseItem;
}
Course *ll_create_course(const char c[MAX_CODE], const char t[MAX_TITLE], int cred) {
    Course *newCourse = new Course;
    strcpy(newCourse->code, c);
    strcpy(newCourse->title, t);
    newCourse->credit = cred;
    newCourse->next = nullptr;
    newCourse->exclusions = nullptr;
    newCourse->prerequisites = nullptr;
    return newCourse;
}
Course* ll_search_course(Course* head, const char c[MAX_CODE]) {
    for (Course *p = head; p!= nullptr; p = p->next) {
        if ( strcmp(p->code, c) == 0)
            return p;
    }
    return nullptr;
}
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
// helper function: shared between ll_insert_prerequisite and ll_insert_exclusion
bool ll_insert_course_item(CourseItem *&head, Course* course) {
    // empty list handling
    if ( head == nullptr ) {
        head = ll_create_course_item(course);
        return true;
    }
    // if the list is not empty
    CourseItem *prev = nullptr;
    CourseItem *p = nullptr;
    int cmp;
    for (p = head; p!= nullptr; p = p->next) {
        cmp = strcmp(p->course->code, course->code);
        if ( cmp == 0 ) {
            // found an existing entry
            return false; // cannot insert 
        } else if ( cmp > 0 ) {
            break;
        }
        prev = p;        
    }
    // insert - normal case handling
    CourseItem *newCourseItem = ll_create_course_item(course);
    if ( prev == nullptr ) {
        // insert to the front
        newCourseItem->next = head;
        head = newCourseItem;
    } else {
        prev->next = newCourseItem;
        newCourseItem->next = p;
    }
    return true;
}

// helper function: shared between ll_delete_prerequisite and ll_delete_exclusion
bool ll_delete_course_item(CourseItem *&head, Course* course) {
    // empty list handling
    if ( head == nullptr ) {
        return false; // cannot delete an empty list
    }
    // if the list is not empty
    CourseItem *prev = nullptr;
    CourseItem *p = nullptr;
    int cmp;
    bool found = false;
    for (p = head; p!= nullptr; p = p->next) {
        cmp = strcmp(p->course->code, course->code);
        if ( cmp == 0 ) {
            found = true;
            break;
        } 
        prev = p; 
    }
    if ( found  ==  true ) {
        // delete the item p
        if ( p == head ) {
            // update head before deleting p
            head = p->next;
        } else {
            prev->next = p->next;
        }
        delete p;
        return true;
    } 
    
    return false; // cannot delete if the item is not found

}

bool ll_insert_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]) {
    Course* target = ll_search_course(head, targetCode);
    Course* pre = ll_search_course(head, preCode);
    if ( target == nullptr || pre == nullptr )
        return false; // cannot insert if either one of them does not exists
    bool result = ll_insert_course_item(target->prerequisites, pre);
    return result;
}
bool ll_insert_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]) {
    Course* target = ll_search_course(head, targetCode);
    Course* exclude = ll_search_course(head, excludeCode);
    if ( target == nullptr || exclude == nullptr )
        return false; // cannot insert if either one of them does not exists
    bool result = ll_insert_course_item(target->exclusions, exclude);
    return result;
}

bool ll_delete_prerequisite(Course* head, const char targetCode[MAX_CODE], const char preCode[MAX_CODE]) {
    Course* target = ll_search_course(head, targetCode);
    Course* pre = ll_search_course(head, preCode);
    if ( target == nullptr || pre == nullptr )
        return false; // cannot delete if either one of them does not exists
    bool result = ll_delete_course_item(target->prerequisites, pre);
    return result;
}

bool ll_delete_exclusion(Course* head, const char targetCode[MAX_CODE], const char excludeCode[MAX_CODE]) {
    Course* target = ll_search_course(head, targetCode);
    Course* exclude = ll_search_course(head, excludeCode);
    if ( target == nullptr || exclude == nullptr )
        return false; // cannot delete if either one of them does not exists
    bool result = ll_delete_course_item(target->exclusions, exclude);
    return result;
}




bool ll_insert_course(Course*& head, const char c[MAX_CODE], const char t[MAX_TITLE], int cred) {

    // empty list handling
    if ( head == nullptr ) {
        head = ll_create_course(c, t, cred);
        return true;
    } 

    // if the list is not empty
    Course *prev = nullptr;
    Course *p = nullptr;
    int cmp;
    for (p = head; p!= nullptr; p = p->next) {
        cmp = strcmp(p->code, c);
        if ( cmp == 0 ) {
            // found an existing entry
            return false; // cannot insert 
        } else if ( cmp > 0 ) {
            break;
        }
        prev = p;        
    }

    // insert - normal case handling
    Course *newCourse = ll_create_course(c, t, cred);
    if ( prev == nullptr ) {
        // insert to the front
        newCourse->next = head;
        head = newCourse;
    } else {
        prev->next = newCourse;
        newCourse->next = p;
    }
    return true;
}

bool ll_delete_course(Course*& head, const char c[MAX_CODE]) {

    // empty list handling
    if ( head == nullptr ) {
        return false;
    } 

    // if the list is not empty
    Course *prev = nullptr;
    Course *p = nullptr;
    int cmp;
    bool found = false;
    for (p = head; p!= nullptr; p = p->next) {
        cmp = strcmp(p->code, c);
        if ( cmp == 0 ) {
            // found an existing entry
            found = true;
            break;
        } 
        prev = p;        
    }

    if ( found == false ) {
        // cannot delete a course that is not existing..
    } else {
        // need to delete Course pointed by p
        Course *q; 
        for (q = head; q!= nullptr; q = q->next) {
            ll_delete_prerequisite(head, q->code, p->code);
            ll_delete_exclusion(head, q->code, p->code);
        }

        CourseItem *item, *itr;
        if ( p->prerequisites != nullptr) {
            // delete all items in p->prerequisites
            itr = p->prerequisites;
            while ( itr != nullptr ) {
                item = itr;
                itr = itr->next;
                delete item;
            }
        }

        if ( p->exclusions != nullptr ) {
            // delete all items in p->exclusions
            itr = p->exclusions;
            while ( itr != nullptr ) {
                item = itr;
                itr = itr->next;
                delete item;
            }
        }

        if ( p == head ) {
            head = p->next;
        } else {
            prev->next = p->next;
        }
        delete p;
        return true;

    }
    return false;
}

bool ll_modify_course_title(Course* head, const char c[MAX_CODE], const char t[MAX_TITLE]) {
    Course* target = ll_search_course(head, c);
    if ( target == nullptr )
        return false;
    strcpy(target->title, t);
    return true;
}
bool ll_modify_course_credit(Course* head, const char c[MAX_CODE], int cred) {
    Course* target = ll_search_course(head, c);
    if ( target == nullptr )
        return false;
    target->credit = cred;
    return true;
}



void ll_cleanup_all(Course *&head) {
    while ( head != nullptr ) {
        ll_delete_course(head, head->code);
    }
}
