#include <iostream>
#include <ctime>

using namespace std;

int userInputToInt(string userInput);
void populateArray(int arr[], int arrayLength);
void printArray(int arr[],int arrayLength);
void searchArray(int arr[], int target, int arrayLength);
void sortArray(int arr[], int arrayLength);
void welcomeMessage();

// working on extended branch 

int main()
{

    srand(time(NULL));
    welcomeMessage();

    string userInput;
    cout << "Enter the option from the menu: ";
    cin >> userInput;
    int userOption = userInputToInt(userInput);

    int arrayLength;
    cout << "enter arraylength: ";
    cin >> arrayLength;

    int arr[arrayLength]={};


    while(userOption != 6)
    {

        switch(userOption){
            case 1:
            {
                populateArray(arr,arrayLength);
                break;
            }
            case 2:
            {
                printArray(arr,10);
                break;
            }
            case 3:
            {
                int target;
                cout << "Enter value you want to search: ";
                cin >> target;
                searchArray(arr,target,arrayLength);
            break;
            }
            case 4:
            {
                sortArray(arr,arrayLength);
                cout << "Array is sorted." << endl;
                break;
            }
            case 5:
            {
                cout << "Writing array.." <<endl;
                break;
            }
             case 6:
            {
                cout << "Exiting program" << endl ;
                exit(0);
            }
        }
    }

    welcomeMessage();
    cin >> userInput;
    userOption = userInputToInt(userInput);
    

    return 0;
}

int userInputToInt(string userInput){
    int userOption;
    if(userInput == "a")
        userOption = 1;
    else if(userInput == "b")
        userOption = 2;
    else if(userInput == "c")
        userOption = 3;
    else if(userInput == "d")
        userOption = 4;
    else if(userInput == "e")
        userOption = 5;
    else if(userInput == "f")
        userOption = 6;
    return userOption;
}

void populateArray(int arr[], int arrayLength){
    cout << "Populating array..."<<endl;

   for(int i = 0; i < arrayLength; i++){
        int x = rand()%100 + 1;
        arr[i] = x;
    }

    cout << "Array is populated."<<endl;
}

void printArray(int arr[],int arrayLength){
    cout << "Printing array: " << endl;
    for(int i = 0; i < arrayLength; i++){
            if(i==0)
            cout <<"[ ";
        cout <<arr[i]<<", ";
        if(i==arrayLength-1)
            cout <<"]"<<endl;
    }
}

void searchArray(int arr[], int target, int arrayLength){

cout << "Searching in the array..."<< endl;
bool exists = false;
int index;
   for(int i = 0; i < arrayLength; i++){
    if(arr[i] == target){
        exists = true;
        index = i;
        break;
    }
   }
   if(exists)
    cout <<target << " found at index: "<< index <<endl;
   if(exists == false)
    cout << "Element not found!"<< endl;
}

void sortArray(int arr[], int arrayLength){

    cout << "sorting array... "<<endl;
int temp;
 	for(int i=1;i<arrayLength;++i)
	{
		for(int j=0;j<(arrayLength-i);++j)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	}
}

	void welcomeMessage(){

    cout << "\n\t\tMenu"<<endl;
    cout << " a. Populate array" <<endl;
    cout << " b. Print array contents" <<endl;
    cout << " c. Search an array element" <<endl;
    cout << " d. Sort the array content" <<endl;
    cout << " e. Write a file (sorted array)" <<endl;
    cout << " f. Exit\n" <<endl;
}

