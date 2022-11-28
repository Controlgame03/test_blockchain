#include <iostream>
#include <chrono>

using namespace std;

class Block{
private:

    bool nonce_calculated = false;

    string transaction_time;
    int transaction_time_hash;

    long long nonce;

    long long sender;
    long long reciever;

    double amount;

    int current_block_hash;
    int prev_block_hash;

    void initialize_components(long long _sender, long long _reciever, double _amount, long long _prev_block_hash){
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);
        
        transaction_time = ctime(&time);
        transaction_time.erase(transaction_time.size() - 1, 1);
        sender = _sender;
        reciever = _reciever;
        amount = _amount;
        prev_block_hash = _prev_block_hash;
        nonce = 0; // default nonce
    }

public:

    Block(long long _sender, long long _reciever, double _amount, long long _prev_block_hash){
        initialize_components(_sender, _reciever, _amount, _prev_block_hash);
    }

    Block(long long _sender, long long _reciever, double _amount, long long _nonce, long long _prev_block_hash){
        initialize_components(_sender, _reciever, _amount, _prev_block_hash);

        this->nonce = _nonce;
        nonce_calculated = true;        
    }

    void set_current_block_hash(long long _current_block_hash){
        current_block_hash = _current_block_hash;
    }

    /*
    Информация о формате записи одного блока в файл. Один блок должен содержать в себе
            ___________________________________________
            |               -->Block<--               |
            |-----------------------------------------|
            |отправитель монет (id или публичный ключ)|
            |-----------------------------------------|
            |            получатель монет             |
            |-----------------------------------------|
            |            количество монет             |
            |-----------------------------------------|
            |            время транзакции             |
            |-----------------------------------------|
            |                  нонс                   |
            |-----------------------------------------| 
            |          хэш предыдущего блока          |
            |-----------------------------------------|
            |           хэш текущего блока            |
            |_________________________________________|

    В формате "Block{sender, reciever, amount, transaction_time, nonce, prev_block_hash, current_block_hash};\n"
    */
    string toString(){
        string result = "Block{";
        result.append(to_string(sender));
        result.append(", ");
        result.append(to_string(reciever));
        result.append(", ");
        result.append(to_string(amount));
        result.append(", ");
        result.append(transaction_time);
        result.append(", ");
        result.append(to_string(nonce));
        result.append(", ");
        result.append(to_string(prev_block_hash));
        result.append(", ");
        result.append(to_string(current_block_hash));
        result.append("};\n");
        return result;
    }

   
};

