#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

void makeArray(string order, int* orderArray);
int computeParcels(int order[6]);

int main(){

    string order;
    int* orderArray = new int[6];
    bool terminate = false;
    int numPackets = 0;
    vector<int> results;

    while(!terminate){
        for(int i = 0; i < 6; ++i){
            cin >> numPackets;
            //cout << "cin >> numPackets: " << numPackets << endl;
            //cout << "numPackets == 0: " << (numPackets == 0) << endl;
            orderArray[i] = numPackets;
        }
        terminate = true;
        //cout << "terminate: " << terminate << endl;
        for(int i = 0; i < 6; ++i){
            //cout << "orderArray[" << i << "]: " << orderArray[i] << endl;
            if(orderArray[i] > 0){
                terminate = false;
            }
        }
        if(terminate){
            break;
        }
        results.push_back(computeParcels(orderArray));
    }

    for(int i = 0; i < results.size(); ++i){
        cout << results[i] << endl;
    }

    delete orderArray;
    return 0;

}

void makeArray(string order, int* orderArray){

    int numPackets;
    stringstream ss(order);

    for(int i = 0; i < 6; ++i){
        ss >> numPackets;
        cout << "numPackets: " << numPackets << endl;
        orderArray[i] = numPackets;
    }

}

int computeParcels(int* order){

    int numParcels = order[5],
        extraSpace;

    // Pack 5x5 parcels.
    while(order[4]){

        ++numParcels;
        order[4] -= 1;

        // Pack extra 1x1s.
        if(0 < order[0] && order[0] < 11){
            order[0] = 0;
        }
        else if(0 < order[0]){
            order[0] -= 11;
        }

    }

    // Pack 4x4 parcels.
    while(order[3]){

        ++numParcels;
        order[3] -= 1;

        extraSpace = 20;
        // Pack extra 2x2s.
        while(order[1] && extraSpace > 0){
            order[1] -= 1;
            extraSpace -= 4;
        }

        if(extraSpace > 0 && order[0] > 0){

            if(extraSpace < order[0]){
                order[0] -= extraSpace;
            } else {
                order[0] = 0;
            }
        }

    }

    // Pack 3x3 parcels.
    while(order[2]){

        ++numParcels;
        extraSpace = 36;
        int num_3x3_packed = 0;

        while(extraSpace > 0 && order[2] > 0){
            extraSpace -= 9;
            order[2] -= 1;
            ++num_3x3_packed;
        }

        // Pack 2x2s.
        switch(num_3x3_packed){
            case 1:
                if(order[1] > 5){
                    order[1] -= 5;
                    extraSpace = 7;
                } else {
                    extraSpace -= 4*order[1];
                    order[1] = 0;
                }
                break;
            case 2:
                if(order[1] > 3){
                    order[1] -= 3;
                    extraSpace = 6;
                } else {
                    extraSpace -= 4*order[1];
                    order[1] = 0;
                }
                break;
            case 3:
                if(order[1] > 0){
                    extraSpace -= 4;
                    order[1] -= 1;
                }
                break;
        }

        if(extraSpace > 0){
            if(extraSpace > order[0]){
                order[0] = 0;
            } else {
                order[0] -= extraSpace;
            }
        }

    }

    int remainingArea = order[0] + 4*order[1];
    while(remainingArea > 0){
        remainingArea -= 36;
        ++numParcels;
    }

    return numParcels;

}
