#include "int-queue.h" /* File: int-queue-test.cpp */

void print_queue_info(const int_queue& a) {
    cout << "No. of data currently on the queue = " << a.size() << "\t";
    if (!a.empty()) cout << "Front item = " << a.front();
    cout << endl << "Empty: " << boolalpha << a.empty();
    cout << "\t\t" << "Full: " << boolalpha << a.full() << endl << endl;
}
    
int main() {
    int_queue a;   print_queue_info(a);
    a.enqueue(4);  print_queue_info(a);
    a.enqueue(15); print_queue_info(a);
    a.enqueue(26); print_queue_info(a);
    a.enqueue(37); print_queue_info(a);
    a.dequeue();   print_queue_info(a);
    a.enqueue(48); print_queue_info(a);
    a.enqueue(59); print_queue_info(a);
    a.dequeue();   print_queue_info(a);
    a.dequeue();   print_queue_info(a);
    a.dequeue();   print_queue_info(a);
    a.dequeue();   print_queue_info(a);
    a.dequeue();   print_queue_info(a);
    return 0; 
} /* compile: g++ -L. -o int-queue-test int-queue-test.cpp -lintqueue */
