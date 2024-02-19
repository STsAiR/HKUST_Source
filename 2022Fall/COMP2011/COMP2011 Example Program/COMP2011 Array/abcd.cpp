#include <iostream>     /* File: 2d-array-fcn.cpp */
#include <cmath>	
using namespace std;	

float euclidean_distance(const float pointA[], const float pointB[])
{
    float x_diff = pointA[0] - pointB[0];
    float y_diff = pointA[1] - pointB[1];
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

void print_2d_array(const float a[][3], int num_rows, int num_columns)
{
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
}

void compute_all_distances(
    const float point[][2], float dist[][3], int num_points)
{
    for (int i = 0; i < num_points; i++)
        for (int j = 0; j < num_points; j++)
            dist[i][j] = euclidean_distance(point[i], point[j]);
}

int main()	
{
    float dist[3][3];   // Distances between any pairs of points
    float point[3][2];  // (x, y) coordinates of 3 points
    cout << "Co-ordinates of A: "; cin >> point[0][0] >> point[0][1];
    cout << "Co-ordinates of B: "; cin >> point[1][0] >> point[1][1];
    cout << "Co-ordinates of C: "; cin >> point[2][0] >> point[2][1];
    compute_all_distances(point, dist, 3);
    print_2d_array(dist, 3, 3);
    return 0;
}
