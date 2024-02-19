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
    /* Please replace this to your own code below */
    int count, temp;
    for (int i =0; i < num_prisoners; i++){
        count = 1;
        if (boxes[i] == i) continue;
        else temp = boxes[i];
        while (boxes[temp] != i){
            count++;
            temp = boxes[temp];
        }
        if (count >= num_trials) return false;
    }
    return true;
}

// TASK 2: Display certain statistics for a given room
void statsRoom(const int boxes[], int num_prisoners, int num_trials)
{
    /* Here in this task, we provide some lines of code for your reference. Please write your code below and replace some of the given code */
    int count, temp, i, j, k , numberOfSuccess = 0;
    int smallest = 1000, longest = 1;
    for (i =0; i < num_prisoners; i++){
        count = 1;
        if (boxes[i] == i) {
            numberOfSuccess++;
            smallest = 1;
            continue;
        }
        temp = boxes[i];
        count++;
        while (boxes[temp] != i){
            count++;
            temp = boxes[temp];
        }
        if (count <= num_trials) numberOfSuccess++;
        if (smallest > count) smallest = count;
        if (longest < count) longest = count;
    }
    int boxes2[num_prisoners];
    int boxes3[num_prisoners];
    count =0; temp=0;
    int num_of_loop=0, pos2 =0, pos3=0;
    for (i =0; i<num_prisoners; i++) boxes2[i] = -2;
    for (i =0; i<num_prisoners; i++){
        if (boxes[i] == i){
            boxes2[i] = count;
            count++;
            continue;
        }
        if (boxes2[i] != -2) continue;
        boxes2[i] = count;
        temp = boxes[i];
        boxes2[temp] = count;
        while (boxes[temp] != i){
            temp = boxes[temp];
            boxes2[temp] = count;
        }
        count++;
    }
    for (i =0; i<num_prisoners; i++){
        count = 0;
        if (boxes2[i] > num_of_loop) num_of_loop = boxes2[i]; //Getting number of loop
        for (j =0; j<num_prisoners; j++) {if (boxes2[j] == i) count++;} //creating boxes3
        boxes3[i] = count;
    }    

    temp =0;

    for (i =0; i<num_prisoners; i++){
        if (boxes3[i] == longest){
            pos2 = i;
            break;
        }
    }
    cout << "The number of prisoners who find their slips: " << numberOfSuccess /* Please replace this to your own code */ << endl;
    cout << "Number of loops: " << num_of_loop + 1 << endl;
    cout << "Smallest loop length: " << smallest /* Please replace this to your own code */ << endl;
    cout << "Longest loop length: " << longest /* Please replace this to your own code */ << endl;
    cout << "Largest loop: "<<  pos2 << " ";

    /* Please replace this to your own code */
    temp = pos2;
    while (boxes[temp] != pos2){
        cout << boxes[temp] << " ";
        temp = boxes[temp];
    }

    cout << endl;
}

// TASK 3: Find the number of instances in 1000 rooms when the prisoners will all be able to escape
double successRooms(int boxes[], int num_prisoners, int num_trials) //  suceess rate of 1000 rooms basically repeating it a 1000 times
{
    /* Please replace this to your own code below */
    int count = 0;
    for (int i = 0; i<1000; i++){
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials)) count++;
    }
    return count ;
}

// TASK 4: Nice guard will help the prisoners to successfully leave the room by breaking any loop which is greater than the number of trials
//         Return true if the intervention was applied, else return false
bool niceGuard(int boxes[], int num_prisoners, int num_trials)
{
    /* Please replace this to your own code below */
    if (simulateRoom(boxes, num_prisoners, num_trials)) return false;
    else {
    int count, temp1, temp2;
    for (int i =0; i < num_prisoners; i++){
        count = 1;
        if (boxes[i] == i) continue;
        else temp1 = boxes[i];
        while (boxes[temp1] != i && count < num_trials){
            count++;
            temp1 = boxes[temp1];
        }
        if (count >= num_trials){
            temp2 = boxes[i];
            boxes[i] = boxes[temp1];
            boxes[temp1] = temp2;
        }

    }
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