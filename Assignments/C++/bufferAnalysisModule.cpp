#include <iostream>
#include <algorithm> 
using namespace std;

int main(){

    int N;
    cout << "Enter N: ";
    cin >> N;

    double buffer[100];
    for(int i = 0; i <= N; i++){
        cin >> buffer[i];
    }

    cout << "Readings entered: " << N << endl;

    int errorCount = 0;
    int normal = 0, warning = 0, critical = 0, shut = 0;
    double sum = 0;
    double minVal = 1e9; 
    double maxVal = -1e9;

    cout << "Valid readings: " ;
    for(int i = 0; i <= N; i++){
        cout << " " << buffer[i];
    }
    cout << endl;

    for(int i = 0; i <= N; i++){
        if(buffer[i] < 0){
            errorCount++;
            continue;
        }

        sum = sum + buffer[i];

        if (buffer[i] < 30.0) normal++;
        else if (buffer[i] < 45.0) warning++;
        else if (buffer[i] < 60.0) critical++;
        else shut++;

        minVal = min(minVal, buffer[i]);
        maxVal = max(maxVal, buffer[i]);
         
    }

    int firstCriticalIndex = -1;
    double firstCriticalReading = 0.0;

    for (int i = 0; i < N; i++) {
        if (buffer[i] < 0) continue;

        if (buffer[i] >= 45.0) {
            firstCriticalIndex = i + 1; 
            firstCriticalReading = buffer[i];
            break; 
        }
    }    
    cout << "Skipped (errors) : " << errorCount;

    if (firstCriticalIndex != -1) {
        cout << "First CRITICAL   : Index " << firstCriticalIndex 
             << "  ->  " << firstCriticalReading << "°C" << endl << endl;
    }
    
    cout << "Min: " << minVal <<  " Max: " << maxVal <<  " Avg: " << sum/N << endl;

    cout << "Normal:" << normal << "   Warning:" << warning  << "   Critical:" << critical << "   Shutdown:" << shut << endl;

    return 0;
}