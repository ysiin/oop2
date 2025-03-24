#include <iostream>
#include <string>

using namespace std;

class Payment
{
public:
    int ID;
    int amount;
    string date;
    string status;
};

class CardCreditPayment : public Payment
{
protected:
    int cvv;
public:
    void processPayment(int ID, int cvv, string date, string status)
    {
        cout << "PAYMENT PROCESS" << endl;
        cout << "Card number: " << ID << endl;
        cout << "CVV number: " << cvv << endl;
        cout << "Transaction date: " << date << endl;
        cout << "Status: " << status << endl;
        cout << endl;
    };


    void validatePayment(int ID, int cvv, string date, int amount)
    {
        cout << "VALIDATE PAYMENT" << endl;
        cout << "Card number: " << ID << endl;
        cout << "CVV number: " << cvv << endl;
        cout << "Transaction date: " << date << endl;
        cout << "All amount: " << amount << endl;
        cout << endl;
    };


    void refundPayment(int ID, string date, string status)
    {
        cout << "REFUND PAYMENT" << endl;
        cout << "Card number: " << ID << endl;
        cout << "Transaction date: " << date << endl;
        cout << "Status: " << status << endl;
        cout << endl;
    };
};

class BankTransfer : public Payment
{
protected:
    int tfCode;
public:
    string bankName;
    void processPayment(int ID, int tfCode, string bankName)
    {
        cout << "PAYMENT PROCESS" << endl;
        cout << "Acount number: " << ID << endl;
        cout << "Transfer code: " << tfCode << endl;
        cout << "Bank name: " << bankName << endl;
        cout << endl;
    };
    void validatePayment(int ID, int tfCode, int amount, string bankName)
    {
        cout << "VALIDATE PAYMENT" << endl;
        cout << "Acount number: " << ID << endl;
        cout << "Transfer code: " << tfCode << endl;
        cout << "All amount: " << amount << endl;
        cout << "Bank name: " << bankName << endl;
        cout << endl;
    };
};

class DigitalWallet : public Payment
{
protected:
    long long int phoneNumber;

public:
    string provider;
    int ID(const int &walletID)
    {
        return Payment::ID = walletID;
    }

    void processPayment(int walletID, string provider, long long int phoneNumber)
    {

        cout << "E-WALLET" << endl;
        cout << "Wallet ID: " << walletID << endl;
        cout << "Provider: " << provider << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << endl;
    };
};

int main()
{
    CardCreditPayment Pay1;
    BankTransfer Tf1;
    DigitalWallet wlt1;

    Pay1.processPayment(1234, 666, "22/04/2025", "Done");
    Pay1.validatePayment(1234, 666, "22/04/2025", 100000);
    Pay1.refundPayment(1234, "22/04/2025", "Refund");

    Tf1.processPayment(121212, 131313, "Mandiri");
    

    wlt1.processPayment(12345, "Gopay", 628888902026);
}
