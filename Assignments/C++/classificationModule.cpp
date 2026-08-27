#include <iostream>
using namespace std;

int statusCode(double s){
    if(s < 0){
        return -1; 
    }
    else if(s >= 0 && s <= 29){
        return 0; 
    }
    else if(s >= 30 && s <= 44){
        return 1;    
    }
    else if(s >= 45 && s <= 59){
        return 2;
    }
    else return 3;
}

int main(){

    double sensorReading ;

    cout << "Enter sensor reading: ";
    cin >> sensorReading;

    double temperature = (sensorReading * 9.0/5.0) + 32;
    cout << "Temperature : " << sensorReading << "*C / " << temperature << "*F" << endl;

    int status_code = statusCode(sensorReading);

    switch(status_code){

        case -1:
        cout <<"Status : SENSOR_ERROR" << endl;
        cout << "Action : Sensor fault - check wiring" << endl;
        break;

        case 0:
        cout <<"Status : NORMAL" << endl;
        cout << "Action : No action required" << endl;
        break;

        case 1:
        cout <<"Status : WARNING" << endl;
        cout << "Action : Alert sent to supervisor" << endl;
        break;
        
        case 2:
        cout <<"Status : CRITICAL" << endl;
        cout << "Action : Cooling system triggered" << endl;
        break;

        case 3:
        cout <<"Status : SHUTDOWN" << endl;
        cout << "Action : Emergency shutdown initiated" << endl;
        break;

        default:
        break;
    }

    string reading = (sensorReading >= 25.0) ? "Above Average" : "Below Average";
    cout << "Reading : " << reading;

    return 0;
}