//
// Created by 이한별 on 24. 10. 23.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>

#include "Number.h"
#include "Fraction.h"
#include "ComplexFraction.h"

using namespace std;

int msgReadInt(string message)
{
    int inputNum;
    cout << message;
    cin >> inputNum;

    return inputNum;
}

void changeComplexFraction(ComplexFraction& compFrac)
{
    Fraction realFrac, imagFrac;
    realFrac.setNumerator(msgReadInt("Real Numerator:")).setDenominator(msgReadInt("Real Denominator:"));
    imagFrac.setNumerator(msgReadInt("Imaginary Numerator:")).setDenominator(msgReadInt("Imaginary Denominator:"));
    compFrac.setReal(realFrac).setImaginary(imagFrac);

}

int chooseFromMenu()
{
    int menuNum = 0;
    while(menuNum == 0)
    {
        try
        {
            cin >> menuNum;
            if(menuNum < 1 || menuNum > 4)
                throw runtime_error("Invalid menu item");
        }
        catch(runtime_error & ex)
        {
            cout << ex.what() << endl;
            menuNum = 0;
        }
    }

    return menuNum;
}

void writeFractionToFile(ComplexFraction& compFrac, char* fileName)
{
    ofstream myFile;

    bool isOpenPossible = true;
    try
    {
        myFile.open(fileName, ios::app);
        if(!myFile)
            throw runtime_error("Try to write file which is read-only!");
    }
    catch(runtime_error & ex)
    {
        cout << ex.what() << endl;
        isOpenPossible = false;
    }

    if(isOpenPossible)
    {
        myFile << compFrac.getReal().getTop() << " ";
        myFile << compFrac.getReal().getBottom() << " ";
        myFile << compFrac.getImaginary().getTop() << " ";
        myFile << compFrac.getImaginary().getBottom() << " ";
        myFile << endl;
    }

    myFile.close();
}

Fraction readFractionFromFile(ifstream & myFile)
{
    int top, bottom;
    Fraction myFrac;
    myFile >> top >> bottom;
    myFrac.setNumerator(top).setDenominator(bottom);
    return myFrac;
}

void printAllFractions(char* filename)
{
    ifstream myFile;
    ComplexFraction compFrac;
    Fraction realFrac, imagFrac;

    bool isReadPossible = true;
    try
    {
        myFile.open(filename, ios::in);
        if(!myFile)
            throw runtime_error("Error opening file");
    }
    catch (runtime_error & ex)
    {
        cout << ex.what() << endl;
        isReadPossible = false;
    }


    if(isReadPossible)
    {
        while(!myFile.eof())
        {
            realFrac = readFractionFromFile(myFile);
            imagFrac = readFractionFromFile(myFile);

            compFrac.setReal(realFrac).setImaginary(imagFrac);
            if(!myFile.eof()) compFrac.print();
            cout << endl;
        }
        myFile.close();
    }
}

void printComplexFraction(ComplexFraction& compFrac)
{
    cout << endl;
    cout << "Current Complex Fraction = ";
    compFrac.print();
    cout << endl;
    cout << "--------------------" << endl;
}

void printMenu()
{
    cout << "1) Change Complex Fraction" << endl;
    cout << "2) Append Complex Fraction" << endl;
    cout << "3) Print all Complex Fractions in file" << endl;
    cout << "4) Quit" << endl;
}

void menuAction(int menuChoice, ComplexFraction& compFrac, char* fileName)
{
    switch (menuChoice)
    {
        case 1: changeComplexFraction(compFrac); break;
        case 2: writeFractionToFile(compFrac, fileName); break;
        case 3: printAllFractions(fileName); break;
        case 4: exit(0);
    }

}

int main()
{
    ComplexFraction cf1;
    int menuChoice;
    char filename[25] = "ComplexFractions.txt";

    while(true)
    {
        printComplexFraction(cf1);
        printMenu();
        menuChoice = chooseFromMenu();
        menuAction(menuChoice, cf1, filename);
    }
}