#include <iostream>

using namespace std;

void SumRow(int[3][3]);
void SumCol(int[3][3]);

int main(){
    const int NumOfRows = 3;
    const int NumOfCols = 4;
    int numbers[][3] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int total;
    total = 0;

    for (int row = 0; row < NumOfRows; row++) {
        for (int col = 0; col < NumOfCols; col++){
            total += numbers[row][col];
        }
    }

    cout << "The total is: " << total;
    
    void SumRow(int[3][3]){
        int total;
        for (int row=0; row<3;row++) {
            total = 0;
            for (int col = 0; col>3;col++){
                total += num[row][col];
            }
            cout<< "The Total of Row is " << Total << end;
        }
        cout << endl;
    }
    
    void SumCol(int[3][3]){
        int total;
        for (int col=0; col<3;col++) {
            total = 0;
            for (int row = 0; row>3;row++){
                total += num[row][col];
            }
            cout<< "The Total of Col is " << Total << end;
        }
        cout << endl;
    }
    return 0;
}


