#include<iostream>
#include<tuple> 
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
vector<tuple<int, int, int>> vert;
vector<tuple<int, int, int>> answer;
int nodes, edges, dist,cost=0;
int cycle[20];

int checkparent(int a){
	if(cycle[a]==-1)
	checkparent(cycle[a]);
	return a;
}
bool dsu(int a, int b)
{
   if(checkparent(a)==checkparent(b))return false;
   else{
    cycle[checkparent(b)]=checkparent(a);
    return true;
   }
}
void mst()
{
    int curr = 0;
    int done = 0;
    while (done < nodes - 1)
    {
        auto tem = vert[curr];
        if (dsu(get<1>(tem), get<2>(tem)))
        {
            answer.push_back(make_tuple(get<1>(tem), get<2>(tem), get<0>(tem)));
            done++;
        }
        curr++;
    }
}

int main()
{
    memset(cycle, -1, sizeof(cycle));

	cout<<"Enter no. of nodes: " ;
	cin>>nodes;
	cout<<"Enter no. of vertices: ";
	cin>>edges;

	int src, dest, wt;
	int srcn, destn;
	while (edges){
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
		edges--;
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
    mst();
    
    for (int i = 0; i < answer.size(); i++)
    {
        auto tem = answer[i];
        cost+=get<2>(tem);
    }
	cout<<"Cost of mst: "<<cost<<"\n";
}
