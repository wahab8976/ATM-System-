#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef CARD_H
#define CARD_H

extern long long getNumericInputFromUser(int length);

class CARD
{
private:
    long long cardNumber;
    string cardHolder;
    long long balance;
    int pin;

public:
    long long getcardNumber()
    {
        return cardNumber;
    }

    int getPin()
    {
        cout << "Getting Pin...." << endl;
        return pin;
    }

    void loadCardsFromFile(string line)
    {
        string token;
        int pos = 0;
        pos = line.find(",");
        token = line.substr(0, pos);
        cardHolder = token;
        line.erase(0, pos + 1);

        pos = line.find(",");
        token = line.substr(0, pos);
        cardNumber = stoll(token);
        line.erase(0, pos + 1);

        pos = line.find(",");
        token = line.substr(0, pos);
        balance = stoll(token);
        line.erase(0, pos + 1);

        pos = line.find(",");
        token = line.substr(0, pos);
        pin = stoi(token);

    }
};

#endif
