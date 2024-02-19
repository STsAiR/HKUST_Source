#include <iostream>

using namespace std;

// width and height of the canvas
const int WIDTH = 20;
const int HEIGHT = 10;

// Given
void initialize_canvas(char canvas[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            canvas[i][j] = '.';
        }
    }

    canvas[0][0] = '#';
}

// Task 1: Print the canvas
void print_canvas(const char canvas[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

// Task 2: change the cursor after painting the pixel
void paint_pixel(char canvas[HEIGHT][WIDTH], int row_position, int col_position)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (canvas[i][j] == 'X')
                canvas[i][j] = 'x';
        }
    }
    canvas[row_position][col_position] = 'X';
}

// Task 3: change the cursor after painting the pixel
void erase_pixel(char canvas[HEIGHT][WIDTH], int row_position, int col_position)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (canvas[i][j] == 'X')
                canvas[i][j] = 'x';
        }
    }
    canvas[row_position][col_position] = '#';
}

// Task 4: check whether the move is valid and move the cursor
bool move_brush(char canvas[HEIGHT][WIDTH], int &row_position, int &col_position, char move)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (canvas[i][j] == 'X')
                canvas[i][j] = 'x';
        }
    }
    if (move == 'i')
    {
        if (row_position == 0)
            return 0;
        else
        {
            if (canvas[row_position][col_position] != 'x')
                canvas[row_position][col_position] = '.';
            if (canvas[row_position - 1][col_position] == 'x')
                canvas[row_position - 1][col_position] = 'X';
            else
                canvas[row_position - 1][col_position] = '#';
            row_position = row_position - 1;
            return 1;
        }
    }
    else if (move == 'j')
    {
        if (col_position == 0)
            return 0;
        else
        {
            if (canvas[row_position][col_position] != 'x')
                canvas[row_position][col_position] = '.';
            if (canvas[row_position][col_position - 1] == 'x')
                canvas[row_position][col_position - 1] = 'X';
            else
                canvas[row_position][col_position - 1] = '#';
            col_position = col_position - 1;
            return 1;
        }
    }
    else if (move == 'k')
    {
        if (row_position == 9)
            return 0;
        else
        {
            if (canvas[row_position][col_position] != 'x')
                canvas[row_position][col_position] = '.';
            if (canvas[row_position + 1][col_position] == 'x')
                canvas[row_position + 1][col_position] = 'X';
            else
                canvas[row_position + 1][col_position] = '#';
            row_position = row_position + 1;
            return 1;
        }
    }
    else if (move == 'l')
    {
        if (col_position == 19)
            return 0;
        else
        {
            if (canvas[row_position][col_position] != 'x')
                canvas[row_position][col_position] = '.';
            if (canvas[row_position][col_position + 1] == 'x')
                canvas[row_position][col_position + 1] = 'X';
            else
                canvas[row_position][col_position + 1] = '#';
            col_position = col_position + 1;
            return 1;
        }
    }
    return 0;
}

// Task 5: Print the canvas without the cursor
void print_canvas_without_cursor(const char canvas[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (canvas[i][j] == 'X')
                cout << 'x';
            else if (canvas[i][j] == '#')
                cout << '.';
            else
                cout << canvas[i][j];
        }
        cout << endl;
    }
}

int main()
{
    // initial canvas definition
    char canvas[HEIGHT][WIDTH];

    initialize_canvas(canvas);

    cout << "****************************************************************" << endl;
    cout << "******************* Welcome to CPPPaint! ***********************" << endl;
    cout << "****************************************************************" << endl;
    cout << "An empty canvas region is represented by \'.\'" << endl;
    cout << "An painted canvas region is represented by \'x\'" << endl;
    cout << "\'#\' represents your cursor over an emtpy region" << endl;
    cout << "\'X\' represents your cursor over a painted region" << endl;

    cout << "###################### Painting the Pixel ######################" << endl;
    cout << "Press \'r\' to paint the current pixel" << endl;
    cout << "Press \'e\' to erase the current pixel" << endl;
    cout << "####################### Moving the cursor ######################" << endl;
    cout << "Press \'i\',\'k\',\'j\',\'l\' to move up, down, left, or right respectively" << endl;
    cout << "Press \'q\' to stop the program and display your final work" << endl;

    cout << endl;
    cout << endl;
    cout << "Your canvas is currently empty" << endl;

    char movement;
    int row_position = 0;
    int col_position = 0;

    print_canvas(canvas);

    do
    {
        cout << "Select action to perform (r to paint pixel, e to erase pixel; i,k,j,l to move): " << endl;
        cin >> movement;

        if ((movement == 'i') || (movement == 'j') || (movement == 'k') || (movement == 'l'))
        {
            if (!move_brush(canvas, row_position, col_position, movement))
            {
                cout << "move invalid" << endl;
            }
            else
            {
                print_canvas(canvas);
            }
        }

        else if (movement == 'r')
        {
            paint_pixel(canvas, row_position, col_position);
            print_canvas(canvas);
        }

        else if (movement == 'e')
        {
            erase_pixel(canvas, row_position, col_position);
            print_canvas(canvas);
        }

        else if (movement == 'q')
        {
            cout << "Thanks for using CPPPaint!" << endl;
            break;
        }
        else
        {

            cout << "wrong option" << endl;
        }

    } while (true);

    cout << "Here is your finished painting!" << endl;
    print_canvas_without_cursor(canvas);
    return 0;
}