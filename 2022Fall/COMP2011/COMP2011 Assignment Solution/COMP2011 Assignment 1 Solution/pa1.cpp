#include <iostream>
#include <ctime>
using namespace std;

/* -------------------------------------------------------------- */
/* This part serves as a pseudo random number generator for auto grade purpose only */
/* You are suggested not to refer to these codes in this assignment. */
/* You are not allowed to use global variables in this course. */
unsigned int next_num = 1; // Here we initiate an unsigned integer to be used in the following functions.

unsigned int pa1_rand() // This function is used to return a pseudo random number from 0 to 32767.
{
    next_num = next_num * 1103515245 + 2011;
    return static_cast<unsigned int>(next_num / 65536) % 32768;
}
void pa1_srand(unsigned int seed) // This function is used to set a seed of the pseudo random number generator.
{
    next_num = seed;
}
/* Everytime you call pa1_rand(), you will get a new pseudo random number. For the same seed, the sequence of pseudo 
   random number is fixed. For example, when seed = 3, the sequence of pseudo random number is fixed to be [17746, 
   30897, 9622, 18921, 4034, 17510, 24152, 14388, 23665, 31532, ...]. When seed = 5, the sequence of pseudo random 
   number is fixed to be [18655, 32247, 9873, 9718, 26373, 27678, 5314, 22512, 31845, 22885, ...] */
/* -------------------------------------------------------------- */



const int MAX_BOXES = 1000; // This constant stores the largest length of boxes[]. You can use it in your code.

// This function is used to fill the 1D array with a random sequence of unique numbers from 1 to the user input for the number of prisoners
void placeSlips(int boxes[], int num_prisoners)
{
    for (int i = 0; i < num_prisoners; i++)
        boxes[i] = -1;
    int counter = 0;
    while (counter < num_prisoners)
    {
        int num = pa1_rand() % (num_prisoners);
        if (boxes[num] == -1)
        {
            boxes[num] = counter;
            counter++;
        }
    }
}

// TASK 1: Simulate an actual riddle room
bool simulateRoom(const int boxes[], int num_prisoners, int num_trials)
{
    for (int i = 0; i < num_prisoners; i++) // i is the prisoner's number
    {
        int counter = i; // counter is the next box's number the prisoner wants to check
        bool flag = false;

        for (int j = 0; j < num_trials; j++)
        {
            if (boxes[counter] == i)
            {
                flag = true;
                break;
            }                         // prisoner i finds his slip
            counter = boxes[counter]; // check in the box which had the number here
        }

        if (flag == false)
            return false; // the prisoner didn't find his slip
    }

    return true;
}

// TASK 2: Display certain statistics for a given room
void statsRoom(const int boxes[], int num_prisoners, int num_trials)
{
    int largest_loop;             // store only one number for the largest_loop to represent the whole loop
    bool visited[MAX_BOXES] = {}; // store the boxes that already counted in a previous loop
    int counter = 0;              // to keep a tab on the number of loops
    int numEscape = 0;            // to store the number of prisners that are able to escape
    int box_counter = 0;
    int max_loop = 0;
    int min_loop = num_prisoners;
    int numLoops = 0; // to store the number of loops
    // max and min are flipped for easier comparison
    for (int i = 0; i < num_prisoners; i++) // i is the prisoner's number
    {
        counter = 0;     // reset the counter for the next prisoner
        box_counter = i; // reset box counter for the next prisoner

        // cout << i << ": ";

        if (visited[i] == true)
            continue; // to avoid duplicate loop counting

        while (counter <= num_prisoners)
        {
            // cout << box_counter << " ";
            // mark bool arr true: visited
            counter++;                   // update the counter (next chance to open the box) ---> TRACKING THE LENGTH OF EACH LOOP
            visited[box_counter] = true; // visited that box so mark it as true
            if (boxes[box_counter] == i) // if the prisoner find his number
            {
                break;
            }                                 // prisoner i finds their slip
            box_counter = boxes[box_counter]; // else you keep looking
        }

        // cout << endl;

        numLoops++;
        if (counter < min_loop && counter >= 1)
            min_loop = counter;    // find the loop with min length
        if (counter <= num_trials) // to find the number of prisoners that were able to find their slip as it forms a complete loop
        {
            numEscape += counter;
        }
        if (counter > max_loop) // find the loop with max length
        {
            max_loop = counter; // update the max length
            largest_loop = i;
        }
    }

    cout << "The number of prisoners who find their slips: " << numEscape << endl;
    cout << "Number of loops: " << numLoops << endl;
    cout << "Smallest loop length: " << min_loop << endl;
    cout << "Longest loop length: " << max_loop << endl;
    cout << "Largest loop: ";

    box_counter = largest_loop;
    for (int i = 0; i < max_loop; i++)
    {
        cout << box_counter << " ";
        box_counter = boxes[box_counter];
    }
    cout << endl;
}

// TASK 3: Find the number of instances in 1000 rooms when the prisoners will all be able to escape
double successRooms(int boxes[], int num_prisoners, int num_trials) //  suceess rate of 1000 rooms basically repeating it a 1000 times
{
    // consistent num_trials
    int counter = 0;
    for (int i = 0; i < 1000; i++)
    {

        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials) == true)
            counter++;
    }
    return counter; // sending the number back
}

// TASK 4: Nice guard will help the prisoners to successfully leave the room by breaking any loop which is greater than the number of trials
//         Return true if the intervention was applied, else return false
bool niceGuard(int boxes[], int num_prisoners, int num_trials)
{
    int largest_loop; // store only one number for the largest_loop to represent the whole loop
    bool visited[MAX_BOXES] = {};
    int counter = 0; // to keep a tab on the number of loops
    int box_counter = 0;
    int max_loop = 0;
    for (int i = 0; i < num_prisoners; i++) // i+1 is the prisoner's number
    {
        counter = 0;     // reset the counter for the next prisoner
        box_counter = i; // reset box counter for the next prisoner

        if (visited[i] == true)
            continue; // to avoid duplicate loop counting

        while (counter <= num_prisoners)
        {
            // cout << box_counter+1 << " ";
            counter++;                   // update the counter (next chance to open the box) ---> TRACKING THE LENGTH OF EACH LOOP
            visited[box_counter] = true; // visited that box so mark it as true
            if (boxes[box_counter] == i)
                break; // if the prisoner find his number

            box_counter = boxes[box_counter]; // else you keep looking
        }
        if (counter > max_loop) // find the loop with max length
        {
            max_loop = counter; // update the max length
            largest_loop = i;
        }
    }

    if (max_loop <= num_trials)
        return false;
    else
    {
        // apply intervention here
        int half = max_loop / 2;
        int ind1 = largest_loop; // to get the accurate index

        box_counter = largest_loop;
        for (int i = 0; i < half; i++)
        {
            box_counter = boxes[box_counter];
        }
        int ind2 = box_counter;

        // cout<<"ind1= "<<ind1<<" and ind2= "<<ind2<<endl;
        // break the loop by swapping the middle two elements
        int temp = boxes[ind1];
        boxes[ind1] = boxes[ind2];
        boxes[ind2] = temp;

        return true;
    }
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED.

int main()
{

    int num_prisoners, num_trials, seed;
    // set boxes, priosoners

    cout << "Enter the number of prisoners (from 1 to 1000) :" << endl;
    cin >> num_prisoners;
    cout << "Enter the number of boxes each prisoner can open (from 1 to 1000) :" << endl;
    cin >> num_trials;
    cout << "Enter the seed for randomization else enter 0 and the system will randomize for you :" << endl;
    cin >> seed;

    if (seed == 0)
    {
        pa1_srand(time(NULL));
    }
    else
    {
        pa1_srand(seed);
    }

    int boxes[MAX_BOXES]; // array for the boxes
    for (int i = 0; i < MAX_BOXES; i++)
        boxes[i] = 0;

    int choice;
    cout << "Please choose an option:" << endl;
    cout << "0.Print the boxes" << endl;
    cout << "1.Simulate a room" << endl;
    cout << "2.Compute statistics of a room:" << endl;
    cout << "3.Compute success rate over 1000 rooms" << endl;
    cout << "4.Apply nice guard intervention in a room" << endl;
    cin >> choice;

    switch (choice)
    {
    case 0:
        placeSlips(boxes, num_prisoners);
        for (int i = 0; i < num_prisoners; i++)
            cout << boxes[i] << " ";
        cout << endl;
        break;
    case 1:
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials) == true)
        {
            cout << "Success! All prisoners found their slip." << endl;
        }
        else
        {
            cout << "Failure! Not all prisoners were able to find their slip." << endl;
        }
        break;
    case 2:
        placeSlips(boxes, num_prisoners);
        statsRoom(boxes, num_prisoners, num_trials);
        break;
    case 3:
    {

        double prisoners_left = successRooms(boxes, num_prisoners, num_trials);
        cout << "All prisoners were able to leave " << prisoners_left << "/1000 of the rooms." << endl;
    }
    break;
    case 4:
    {
        placeSlips(boxes, num_prisoners);
        int copy_arr[MAX_BOXES];
        for (int i = 0; i < num_prisoners; i++)
        {
            copy_arr[i] = boxes[i]; // copying the array for checking if no more than 2 swaps are made
        }

        bool nice_guard_val = niceGuard(boxes, num_prisoners, num_trials);

        int swap_count = 0;
        for (int j = 0; j < num_prisoners; j++)
        {
            if (copy_arr[j] != boxes[j])
            {
                swap_count++;
            }
        }
        if (swap_count > 2)
        {
            cout << "Illegal intervention as you have more than 1 swap " << endl;
        }
        else
        {
            if (nice_guard_val == false)
                cout << "No intervention needed." << endl;
            else
            {
                cout << "Intervention applied." << endl;
                // validity function
                bool prisoners_left = simulateRoom(boxes, num_prisoners, num_trials);
                // should return true
                if (prisoners_left == true)
                    cout << "All the prisoners were able to escape" << endl;
                else
                {
                    cout << "All the prisoners were not able to escape" << endl;
                }
            }
        }
    }
    break;
    }

    return 0;
}