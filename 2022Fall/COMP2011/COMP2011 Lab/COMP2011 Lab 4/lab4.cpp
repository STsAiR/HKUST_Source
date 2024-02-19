#include <iostream>
using namespace std;

// Maximum capacity of the queue system
const int MAX_QUEUE_LENGTH = 5;


void initialize_queue_system(int queue[]){
    /* TASK 1 - implement function initialize_queue_system
        (1). Initialize the input queue system with all 0s inside
    */
    // Please write your code below
    for (int i = 0; i < MAX_QUEUE_LENGTH; i++ )
        queue[i] = 0;
    // Your code ends here
}


bool take_a_queue_ticket(int queue[], int& next_ticket_number){
    /* TASK 2 - implement function take_a_queue_ticket
        (1). add the taken ticket to the input queue
        (2). you may need to maintain variable next_ticket_number for your usage
        (3). return true if the ticket number is sucessfully added, return false if the queue is already full
    */
    // Please write your code below
    for (int i = 0; i < MAX_QUEUE_LENGTH; i++ )
        if (queue[i] == 0){
            queue[i] = next_ticket_number;
            next_ticket_number += 1;
            return 1;
        }
    return 0;

    // Your code ends here
}


bool serve_the_first_come_customer(int queue[]){
    /* TASK 3 - implement function serve_the_first_come_customer
        (1). remove the first-come ticket from the input queue
        (2). after removing, you may need to maintain the queue to a correct format for possible terminal printing
        (3). return true if the ticket number is sucessfully removed, return false if the queue is already empty
    */
    // Please write your code below
    if (queue[0] == 0) return 0;
    for (int i = 0; i < MAX_QUEUE_LENGTH - 1; i++ ){
        queue[i] = queue[i+1];
    }
    queue[4] = 0;

    return 1;


    // Your code ends here
}


// Given: Print the current queue info to terminal
void show_current_queue(const int queue[]){
    cout << "<-- [ ";
    for (int i = 0; i < MAX_QUEUE_LENGTH; ++i){
        cout << queue[i] << " ";
    }
    cout << "] <--" << endl;
}


int main()
{
    // A dummy queue for starting
    int queue[MAX_QUEUE_LENGTH];

    // The starting ticket number, it should start at 1 and keep increse if people take more and more tickets
    int next_ticket_number = 1;

    // Initialize the queue system
    initialize_queue_system(queue);

    // Run the real-time queue system
    while(true)
    {
        cout << "---------------------------------" << endl;
        cout << "Current waiting tickets are:" << endl;
        show_current_queue(queue);

        // Ask for user operation
        // - enter 1: customer take a ticket
        // - enter 2: serve the first-come waiting customer
        // - enter 0: exit the queue system
        int operation;
        while (true) {
            cout << "Enter an operation (1 = customer take a ticket; 2 = serve the first-come waiting customer; 0 = exit the queue system):";
            if(cin >> operation){
                if (operation >= 0 && operation <= 2){
                    break;
                }
            }
            // use cin.clear() and cin.ignore() to recover and clean the current input to require user input again.
            // if you are interested you can refer to https://www.quora.com/Can-you-explain-cin-ignore-and-cin-clear-for-C-When-is-it-appropriate-to-use-these-How-do-they-affect-the-next-cin.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please re-enter." << endl;
        }    

        // run different input user operation
        if(operation == 0)
        {
            break;
        }

        switch(operation)
        {
            case 1:
            {
                // customer take a ticket
                // print operation success or failure info
                bool flag = take_a_queue_ticket(queue, next_ticket_number);
                if (flag){
                    cout << "A customer successfully takes a ticket!" << endl;
                }
                else{
                    cout << "Fail to take a ticket because even our queue is already full!" << endl;
                }
                break;
            }
            case 2:
            {
                // serve the first-come waiting customer
                // print operation success or failure info
                bool flag = serve_the_first_come_customer(queue);
                if (flag){
                    cout << "Successfully serve a customer to go and dine in!" << endl;
                }
                else{
                    cout << "Fail to serve a customer because no one is waiting in the queue!" << endl;
                }
                break;
            }
        }
    }

    cout << "The queue system close successfully!" << endl;

    return 0;
}