#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    double maxVal = -100;
    int floor = 0, room = 0;

    double sum1 = 0, sum2 = 0, sum3 = 0, avg1 = 0, avg2 = 0, avg3 = 0;
    int warningcount = 0;
    double currentsum = 0;

    double building[3][3];

    cout << "Enter : ";

    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            cin >> building[i][j];
            
            if(building[i][j] >= 30.0){
                warningcount ++;
            }


            if(building[i][j] > maxVal){
                maxVal = building[i][j];
                floor = i+1;
                room = j+1;
            }
        }
    }

     for(int i = 0; i <= 2; i++){
        currentsum = 0;
        for(int j = 0; j <= 2; j++){
            currentsum = currentsum + building[i][j];
        }

        if(i == 0){
            sum1 = currentsum;
            avg1 = sum1/3;
        }
        else if(i == 1){
            sum2 = currentsum;
            avg2 = sum2/3;
        }
        else{
            sum3 = currentsum;
            avg3 = sum3/3;
        }
    }

    int hottestFloor ;
    double maxAvg ;

    if(avg1 > avg2 && avg1 > avg3){
        hottestFloor = 1;
        maxAvg = avg1;
    }
    else if(avg2 > avg3){
        hottestFloor = 2;
        maxAvg = avg2;
    }
    else{
        hottestFloor = 3;
        maxAvg = avg3;
    }

    cout << "          Room1     Room2     Room3" << endl;
    cout << "Floor 1 : " << building[0][0] << "      " << building[0][1] << "      " << building[0][2] << endl;
    cout << "Floor 2 : " << building[1][0] << "      " << building[1][1] << "      " << building[1][2] << endl;
    cout << "Floor 3 : " << building[2][0] << "      " << building[2][1] << "      " << building[2][2] << endl << endl;

    cout << "Hottest Room : " << "Floor " << floor << "," << " Room " << room << " --> " << maxVal << "*C" << endl ;
    cout << "Hottest Floor : " << "Floor " <<  hottestFloor << " (avg" << maxAvg << "*C" << ")" << endl ;
    cout << "Rooms at WARNING or above : " << warningcount << endl;

    return 0;
}