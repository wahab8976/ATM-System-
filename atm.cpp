#include <iostream>
#include <fstream>
#include <conio.h>
#include "./headers/card.h"

using namespace std;
class ATM
{
    CARD loadedCard[100];
    string location;
    long code;
public:
    void readDataFromFile(string filePath)
    {
        ifstream reader(filePath);
        if (!reader.is_open())
        {
            cout << "Error in Opening the File " << endl;
        }
        else
        {
            string line;
            int cardCount = 0;
            while (getline(reader, line))
            {
                loadedCard[cardCount].loadCardsFromFile(line);
                cardCount++;
            }
            reader.close();
            authenticateUser(); // Call to authenticate once the user is Authenticated
        }
    }

    long long getNumericInputFromUser(int length)
    {

        string strInput = ""; // Empty string to store only valid values
        for (int i = 0; i < length;)
        {
            char chInput = _getch();
            if (chInput >= '0' && chInput <= '9')
            {
                cout << chInput;
                strInput.push_back(chInput); // Push valid characters to the Input string
                i++;
            }
        }
        cout << endl;
        return stoll(strInput);
    }

    void authenticateUser()
    {
        int tempPin = 0;
        long long tempCardNumber = 0;
        int foundCardIndex = -11;
        bool cardFound = false;
        int tryCount = 0;

        cout << "Well Come to ATM!" << endl;
        cout << "Enter your Card Number: " << endl;
        tempCardNumber = getNumericInputFromUser(16);

        for (int i = 0; i < 20; i++)
        {
            if (tempCardNumber == loadedCard[i].getcardNumber())
            {
                foundCardIndex = i;
                cardFound = true;
                break;
            }
        }

        // Checking for Pin
        if (cardFound)
        {
            while (tryCount <= 3)
            {
                cout << "Please enter your Pin: " << endl;
                tempPin = getNumericInputFromUser(4);
                tryCount++;
                if (tempPin == loadedCard[foundCardIndex].getPin())
                {
                    cout << "User Authenticated!" << endl;
                    break;
                }
            }
            exit(0);
        }
        else
        {
            cout << "No card Found with Number: " << tempCardNumber << endl;
        }
    }

    // Menus
   
};

int main()
{

    ATM atm;
    atm.readDataFromFile("cardData.txt");
    return 0;
}