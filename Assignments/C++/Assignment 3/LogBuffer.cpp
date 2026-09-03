#include<iostream>
#include<memory>
#include<algorithm>
#include<cstring>

using namespace std;

class LogBuffer{

    private:

    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

    public:

    LogBuffer(int capacity) : capacity(capacity), size(0){
        buffer = new char[capacity];
        buffer[0]= '\0';
        instanceCount++;
    }

    LogBuffer(const LogBuffer& other) : capacity(other.capacity), size(other.size){
        buffer = new char[capacity];
        memcpy(buffer, other.buffer, size + 1);
        instanceCount++;
    }

    LogBuffer& operator = (const LogBuffer& other) {
        if(this == &other){
            cout << "Self Assignment" << endl;
            return *this;
        }

        delete[] buffer;

        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity];
        memcpy(buffer, other.buffer, size + 1);
        return *this;
    }

    ~LogBuffer(){
        delete[] buffer;
        cout << "Buffer released" << endl;
        instanceCount--;
    }

    void append(const char* msg){
        if(!msg){
            return;
        }

        int spaceAvailable = capacity - size - 1;
        if(spaceAvailable <= 0){
            return;
        }

        int byteToCopy = min(static_cast<int>(strlen(msg)), spaceAvailable);
        memcpy(buffer + size , msg, byteToCopy);
        size = size + byteToCopy;
        buffer[size] = '\0';
    }

    void print() const{
        cout << buffer << endl;
    }

    void clear(){
        size = 0;
        buffer[0] = '\0';
    }

    static int getInstanceCount(){
        return instanceCount;
    }

};

int LogBuffer :: instanceCount = 0;

int main(){

    LogBuffer log1(256);
    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");
    log1.print();
    cout << endl;

    LogBuffer log2 = log1;
    log2.append("Cached response sent");
    cout << "log1 : ";
    log1.print();
    cout << "log2 : ";
    log2.print();
    cout << endl;

    LogBuffer log3(128);
    log3 = log1;
    cout << "log3 : "; log3.print();
    cout << endl;

    log1 = log1;
    log1.print();
    cout << endl;

    cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl << endl;
    
    return 0;
}