#include<iostream>
using namespace std;

int mat[10][6];

void arrangeArrival(int num, int mat[][6])
{
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mat[j][1] > mat[j + 1][1]) {
                for (int k = 0; k < 5; k++) {
                    swap(mat[j][k], mat[j + 1][k]);
                }
            }
        }
    }
}

void findWaitingTime(int mat[][6], int num)
{  
    int full_time[5];
    full_time[0] = mat[0][1];
    for (int i = 1; i < num ; i++)
    {    
        // mat[i][3] = mat[i-1][2] + mat[i-1][3] - mat[i][1];    
        full_time[i] = full_time[i-1] + mat[i-1][2];
        mat[i][3] = full_time[i] - mat[i][1];
        
        if (mat[i][3] < 0){
            mat[i][3] = 0;
        }

    }

}
void findTurnAroundTime(int mat[][6], int num)
{
    for (int i = 0; i < num ; i++){
            mat[i][4] = mat[i][2] + mat[i][3];
    }
    
}
void finalAnswer(int mat[][6], int num)
{
 
    findWaitingTime(mat, num);
    findTurnAroundTime(mat, num);
 
    cout << "Processes " << " Burst Time " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time "
         << "\n";
    for (int i = 0 ; i < num ; i++)
    {
        cout << " " << i+1 << "\t\t" << mat[i][2]<< "\t\t"
             <<mat[i][1] << "\t\t" << mat[i][3] << "\t\t "
             <<mat[i][4]  <<  "\t\t " << endl;
    }
 
    
}


int main(){
    int num;

    cout << "Enter number of Process: ";
    cin >> num;
  
    
    for (int i = 0; i < num; i++) {
        cout << "--------P" << i + 1 <<"--------"<< "\n";
        mat[i][0] = i+1;
    
        cout << i+1 <<" Arrival Time: ";
        cin >> mat[i][1];
        cout << i+1 << " Burst Time: ";
        cin >> mat[i][2];
    }

    for (int i = 0; i<num; i++){
        cout<<"P"<< mat[i][0]<<" ";
        cout<< mat[i][1]<<" ";
        cout<< mat[i][2]<< "\n";
    }
    arrangeArrival(num, mat);

    cout<<"Sorted with arrival time:"<<"\n";
    for (int i = 0; i<num; i++){
        cout<<"P"<< mat[i][0]<<" ";
        cout<< mat[i][1]<<" ";
        cout<< mat[i][2]<< "\n";
    }
    finalAnswer(mat, num);

    return 0;
}