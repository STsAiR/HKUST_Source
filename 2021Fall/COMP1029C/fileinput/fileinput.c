#include <stdio.h>
struct highscore {
    char name[20];
    int numofwords;
};
int main(){
    
    char name[5] = "Yeah";
    // Task 3. Save the high score table into the text file
    //
    // Open the high score table file for writing
    // 
    FILE *fp;
    fp = fopen("highscoretable.txt", "w");
    fprintf(fp, "%s", name);
    // Write the high score entries using a loop
    //

    // Close the word list file
    //
    fclose(fp);






}