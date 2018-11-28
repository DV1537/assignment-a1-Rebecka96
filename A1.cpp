#include <iostream>
#include <string>
#include <fstream>


int main(int argc, const char *argv[])
{
    int sum = 0;
    int nrCounter = 0;
    int arraySize = 0;
    double average = 0;
    double *array = new double[1]; //börjar med en plats och ökar med platser i while-loopen

    std::ifstream myFile;

    myFile.open(argv[1]); 

    if(!myFile.is_open()) //om filen inte går att öppna, visa fel-meddelande och avsluta programmet
    {
        std::cout << "ERROR! The file could not open!" << '\n';
        system ("PAUSE");
    }    

    while(myFile >> array[nrCounter]) //spara myFile-innehållet i arrayen
    {
        sum += array[nrCounter]; //kolla om innehållet av myFile i array[] om den innehåller char eller string.

        nrCounter++;

        arraySize += 2;

        double *secondArray = new double[arraySize]; //kan inte använda nrcounter, får ta något annat
                
        for(int i = 0; i < nrCounter; i++)
            secondArray[i] = array[i];

        delete[] array; 
        array = nullptr;

        array = secondArray; //array pekar på secondArray
    }
    

    average = sum / nrCounter;

    for(int j = 0; j < nrCounter; j++)
    {
        if(array[j] > average)
            std::cout << "The number/numbers above the average is/are: " << array[j] << " ";
    }

    myFile.close();
    
    system ("PAUSE");

    return 0;
}

