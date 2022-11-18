#include <iostream>
#include <chrono>

using namespace std;

class Block{
private:

    bool nonceCalculated = false;

    string transaction_time;
    int transaction_time_hash;

    int nonce;

    int sender;
    int reciever;

    int amount;

public:

    Block(long long sender, long long reciever, int amount){
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);

        transaction_time = ctime(&time);
        this->sender = sender;
        this->reciever = reciever;
        this->amount = amount;
    }

    Block(long long sender, long long reciever, int amount, int nonce){
        Block(sender, reciever, amount);

        this->nonce = nonce;
        nonceCalculated = true;        
    }
    /*
    [-] Сделать добавление одного блока в файл пока без проверки хэшей ---> проверка корректности транзакции в перспективе
    [-] Для этого придётся подумать над представлением информации с текстовом виде
    Добавить проверки: 
        [-] Проверка на то, что у отправителя есть достаточное количество монет (Сложный цикл просматривающий весть блокчейн с самого первого блока)
        [-] Проверка на то, что нонс верен и хэш от блока удовлетворяет заданным условиям нормировки
    */
};