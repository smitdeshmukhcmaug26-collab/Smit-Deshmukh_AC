#include<iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

enum class HttpStatus{
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500

};

void handleResponses(HttpStatus status, const string& endpoint){
    int code = static_cast<int>(status);

    switch(static_cast<int>(status)){

        case 200:
                cout << endpoint << "-> " << code << " OK : Request successful" << endl;
                break;

        case 201:
                cout <<  endpoint << "-> " << code << " CREATED : Resource creation successful" << endl;
                break;

        case 400:
                cout <<  endpoint << "-> " << code << " BAD Request : Invalid" << endl;
                break;
                
        case 401:
                cout <<  endpoint << "-> " << code << " Unauthorized : Authentication required" << endl;
                break;
        
        case 404:
                cout <<  endpoint << "-> " << code << " Not found : Endpoint does not exist" << endl;
                break;
        
        case 500:
                cout <<  endpoint << "-> " << code << " Server error : Internal server error - retry later" << endl;
                break;

    }

}

void printHeaders(const HeaderList& headers){
    for(const auto& h : headers){
        cout << h.first <<" , " << h.second << endl;
    }
}

int main(){

    handleResponses(HttpStatus::OK, "[GET /api/users]");
    handleResponses(HttpStatus::Unauthorized, "[POST /api/login]");
    handleResponses(HttpStatus::NotFound, "[GET /api/products/99]");
    handleResponses(HttpStatus::ServerError, "POST / api/order]");
    
    Port Port = 8080;
    IPAddress reqID = "748293847";

    cout << "Request ID : " << Port << endl;
    cout << "Server Port : " << reqID << endl;

    cout << "Headers: " << endl;

    HeaderList headers = {
        {"Content-Type", "aplication/json"},
        {"Authorization", "earer eyJhbGci. .."},
        {"Accept-Language", "en-US"}
    };

    printHeaders(headers);

    return 0;
}