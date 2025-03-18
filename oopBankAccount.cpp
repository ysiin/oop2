#include<iostream>

using namespace std;

class BankAccount{
    private:
    int accountNumber;
    string holderName;
    int balance = 0;

    //constructor
    public:
    BankAccount(string name, int number){
        this->accountNumber = number;
        this-> holderName = name;
    }

    void deposit(int amount){
        this-> balance = balance + amount;
    }

    void withdraw(int amount){
        if (amount > balance){
            cout << "Saldo anda kurang" << endl;
        } else {
            this -> balance = balance - amount;
        }
    }

    void transfer(BankAccount &receiver, int amount){
        if (amount > balance){
            cout << "Saldo anda kurang" << endl;
        } else {
            receiver.deposit(amount);
        this -> balance = balance - amount;
        }
    }

    void cekSaldo(){
        cout << "Nama: " << holderName << endl;
        cout << "Saldo: " << balance << endl << endl;
    }
};


int main(){
    BankAccount yasin = BankAccount("Yaa Siin", 1234);
    BankAccount aden = BankAccount("deden", 12343);
    yasin.deposit(500000);
    yasin.withdraw(100000);
    yasin.transfer(aden, 300000);
    yasin.cekSaldo();
    aden.cekSaldo();
}

