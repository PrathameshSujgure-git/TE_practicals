#include<iostream>
#include<tuple> 
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector< tuple<int, int, int> > vert;

	int nodes;
	int vertices;
	cout<<"Enter no. of nodes: " ;
	cin>>nodes;
	cout<<"Enter no. of vertices: ";
	cin>>vertices;

	int src, dest, wt;
	int srcn, destn;
	while (vertices){
		cout<<"Enter the vertices: ";
		cin>>src>>dest;
		src = src;
		dest = dest;
		for (int i = 0; i < vert.size(); i++){
			if (get<1>(vert[i]) == src && get<2>(vert[i]) == dest){
				cout<<"You have already given this vertex as input, fill again correctly...";
				cout<<"\n";
				cout<<"Enter the correct vertices: ";
				cin>>srcn>>destn;
				src = srcn;
				dest = destn;
			}
			else if (get<1>(vert[i]) == dest && get<2>(vert[i]) == src){
				cout<<"You have already given this vertex as input, fill again correctly...";
				cout<<"\n";
				cout<<"Enter the correct vertices: ";
				cin>>srcn>>destn;
				src = srcn;
				dest = destn;
			}
		}
		
		cout<<"Enter Weight for "<<src<<" - "<< dest<<": ";
		cin>>wt;
		vert.push_back(make_tuple(wt, src, dest));
		vertices--;
	}

	cout<<"----UnSorted----"<<"\n";
	cout << "src" << " " 
         << "dest" << " "
         << "wt" << "\n";
	for (int i = 0; i < vert.size(); i++){
		cout << get<1>(vert[i]) << " " 
             << get<2>(vert[i]) << " " 
             << get<0>(vert[i]) << "\n";
	} 

	sort(vert.begin(), vert.end());
	cout<<"----Sorted based on weight----"<<"\n";
	cout << "src" << " " 
         << "dest" << " "
         << "wt" << "\n";
	for (int i = 0; i < vert.size(); i++){
		cout << get<1>(vert[i]) << " " 
             << get<2>(vert[i]) << " " 
             << get<0>(vert[i]) << "\n";
	} 

	// cout<<get<0>(vert[0]);

	   



	// cout << "The initial values of tuple are : ";
	// cout << get<0>(vert) << " " << get<1>(vert);
	// cout << " " << get<2>(vert) << endl;

	// get<0>(vert) = 'b';
	// get<2>(vert) = 20.5;

	// cout << "The modified values of tuple are : ";
	// cout << get<0>(vert) << " " << get<1>(vert);
	// cout << " " << get<2>(vert) << endl;

	return 0;
}
