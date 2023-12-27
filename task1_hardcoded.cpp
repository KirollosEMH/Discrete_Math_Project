#include <iostream>
#include <cmath>
using namespace std;

void initializeArray(int **arr, int size, int num_of_columns, int num_of_arguments);
void creating2DArray(int **arr, int size, int num_of_columns);
void printArray(int **arr, int size, int num_of_columns);
void deleteArray(int **arr, int size);
void initializeNegatedColumns(int **arr, int size, int num_of_columns, int num_of_arguments, int num_of_negated_arguments);
void initializeConditionalColumns(int **arr, int size, int num_of_relationships);
bool conditionalOutput(int p, int q);
bool checkSatisfiable(int **arr, int size, int num_of_columns);
int checkValidity(int **arr, int size, int num_of_columns);

int main() {
    int num_of_arguments = 3;
    cout << "Statement:\n";
    cout << "If you are a fire-eater, then you work in the circus. If you don't like cotton candy, then you don't work in the circus. Therefore, if you are a fire-eater, then you like cotton candy.\n";
    cout << "Hypothesis:\n\t1. If you are a fire-eater, then you work in the circus. (p -> q)\n";
    cout << "\t2. If you don't like cotton candy, then you don't work in the circus. (~r -> q)\n";
    cout << "Conclusion:\n\t Therefore, if you are a fire-eater, then you like cotton candy. (p -> r)\n";
    int size = pow(2, num_of_arguments);

    int num_of_negated_arguments = 2;

    int num_of_relationships = 3;

    int num_of_columns = num_of_arguments + num_of_negated_arguments + num_of_relationships;


    // create 2D dynamic array
    int **arr = new int*[size]; 
    creating2DArray(arr, size, num_of_columns);
    
    // initialize the array as a truth table
    initializeArray(arr, size, num_of_columns, num_of_arguments);
    initializeNegatedColumns(arr, size, num_of_columns, num_of_arguments, num_of_negated_arguments);
    initializeConditionalColumns(arr, size, num_of_relationships);

    // print the array
    cout << "========================================\n";
    cout << "The truth table is: \n";
    printArray(arr, size, num_of_columns);
    cout << "========================================\n";

    // check if the formula is satisfiable
    if (checkSatisfiable(arr, size, num_of_columns) == true)
    {
        cout << "The formula is satisfiable\n";
    }
    else
    {
        cout << "The formula is not satisfiable\n";
    }

    // check if the formula is valid
    if (checkValidity(arr, size, num_of_columns) == 0)
    {
        cout << "The formula is not valid\n";
    }
    else if (checkValidity(arr, size, num_of_columns) == 1)
    {
        cout << "The formula is valid\n";
    }
    else if (checkValidity(arr, size, num_of_columns) == 2)
    {
        cout << "The formula cannot be determined\n";
    }
    

    // Delete the array
    deleteArray(arr, size);


    return 0;
}

// function that creates 2D array
void creating2DArray(int **arr, int size, int num_of_columns) {
    for (int i = 0; i < size; i++) {
        arr[i] = new int[num_of_columns]; // number of columns
    }
}

// function that intializes array as a truth table
void initializeArray(int **arr, int size, int num_of_columns, int num_of_arguments) {
    for (int i = 0; i < size; i++) {
        int value = i;
        for (int j = 0; j < num_of_arguments; j++) {
            arr[i][j] = value % 2;
            value /= 2;
        }
        // Initialize the rest of the columns to 0
        for (int j = num_of_arguments; j < num_of_columns; j++) {
            arr[i][j] = 0;
        }
    }
        for (int i = 0; i < size; i++) {
        swap(arr[i][0], arr[i][2]);
    }
}

// function that prints the array
void printArray(int **arr, int size, int num_of_columns) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < num_of_columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// function that deletes the array
void deleteArray(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}

// function that initializes the negated columns
void initializeNegatedColumns(int **arr, int size, int num_of_columns, int num_of_arguments, int num_of_negated_arguments) {
    if (num_of_negated_arguments == 0)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i][1] == 0) { arr[i][3] = 1; }
        else if (arr[i][1] == 1) { arr[i][3] = 0; }

       if (arr[i][2] == 0) { arr[i][4] = 1; }
       
       else if (arr[i][2] == 1) { arr[i][4] = 0; }
               
        
    }
    
}

// function that initializes the conditional columns
void initializeConditionalColumns(int **arr, int size, int num_of_relationships) {
    if (num_of_relationships == 0)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (conditionalOutput(arr[i][0], arr[i][1]) == false) { arr[i][5] = 0; }
        else if (conditionalOutput(arr[i][0], arr[i][1]) == true) { arr[i][5] = 1; }

        if (conditionalOutput(arr[i][4], arr[i][3]) == false) { arr[i][6] = 0; }
        else if (conditionalOutput(arr[i][4], arr[i][3]) == true) { arr[i][6] = 1; }

        if (conditionalOutput(arr[i][0], arr[i][2]) == false) { arr[i][7] = 0; }
        else if (conditionalOutput(arr[i][0], arr[i][2]) == true) { arr[i][7] = 1; }


    }
    
}

// function that returns the output of the conditional statement (if-then statement )
bool conditionalOutput(int p, int q){
    if (p == 1 && q == 0) { return false; }
    return true;
}

// function that checks if the formula is satisfiable by checking if there is a row that has at least all 1's in the last 3 columns
bool checkSatisfiable(int **arr, int size, int num_of_columns) {
    for (int i = 0; i < size; i++) {
     
        if (arr[i][5] == 1 && arr[i][6] == 1 && arr[i][7] == 1)
        {
            return true;
        }
     
    }
    return false;
}

// function that checks if the formula is valid by checking critical rows (both hypothesis is true thus conditional must be true) in the last 3 columns
int checkValidity(int **arr, int size, int num_of_columns) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
     
        if (arr[i][5] == 1 && arr[i][6] == 1 && arr[i][7] == 0)
        {
            return 0;
        }
        if (arr[i][5] != 1 && arr[i][6] != 1)
        {
            counter++;
        }
        
    }
    if (counter == size -1)
    {
        return 2; // cannot be determined
    }
    
    return 1;
}
