#include<iostream>
using namespace std;

int mat[10][3];


int main(){
    int num;

    cout << "Enter number of Edges: ";
    cin >> num;
  

    for (int i = 0; i < num; i++) {
        cout << " n1 " <<" n2 "<< " Value "<<"\n";
        cin>>mat[i][0]>> mat[i][1]>> mat[i][2];
    }

     cout<< "\t"  << "First Node "<< "\t"  << "Second Node "<< "\t"  << " Value "<< "\t\t" 
        << "\n";
    for (int i = 0 ; i < num ; i++)
    {
        cout << "\t\t" << mat[i][0]<< "\t\t"
             <<mat[i][1] << "\t\t" << mat[i][2] << "\t\t "
             << endl;
    }

    return 0;
}