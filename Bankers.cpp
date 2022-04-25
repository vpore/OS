#include<bits/stdc++.h>
using namespace std;

int processNum, resourceNum, id, maxR, allocR, needR, freeResources, i, x;
vector<vector<int>> processes;

void processInput(){
    cout<<"Enter no. of processes : ";
    cin>>processNum;
    cout<<"Enter total no. of resources : ";
    cin>>resourceNum;

    cout<<"Enter process id, max need of resources, allocated resources for each process : "<<endl;
    for(i=0; i<processNum; i++){
        cin>>id>>maxR>>allocR;
        needR = maxR - allocR;
        processes.push_back({id, maxR, allocR, needR});
        freeResources = resourceNum - allocR;
    }

    cout<<"\n\nFree Resources left : "<<freeResources<<endl;
    cout<<"\n\nProcess ID\tMax Res\tAllocated Res\tNeed Res\n";
    for(auto i : processes){
        cout<<i[0]<<"\t"<<i[1]<<"\t"<<i[2]<<"\t"<<i[3]<<"\n";
    }
}

void Bankers(){
    if(freeResources < )
}

int main(){
    processInput();
    Bankers();
    return 0;
}