#include<bits/stdc++.h>
using namespace std;

int memCapacity, blocksNum, processNum, sum=0, i, j, x, na;
bool allocated = false;
vector<vector<int>> blocks, processes;

void memoryInput(){
    cout<<"Enter the Memory Capacity : ";
    cin>>memCapacity;
    cout<<"Enter the no. of blocks : ";
    cin>>blocksNum;
    cout<<"Enter the size of each block :\n";
    for(i=0; i<blocksNum; i++){
        cin>>x;
        blocks.push_back({x, i+1});
    }
    sort(blocks.begin(), blocks.end());

    cout<<"\nEnter the no. of processes : ";
    cin>>processNum;
    for(i=0; i<processNum; i++){
        cin>>x;
        processes.push_back({x, i+1});
    }
}

void MFT(){
    cout<<"\nProcess\t\tBlock No.\tInternal Fragmentation\n";
    /*for(auto p : processes){
        for(auto b : blocks){
                cout<<"---"<<b[0]<<endl;
            if(p[0] <= b[0]){
                //cout<<"The Process-"<<p[1]<<" is allocated Block No. "<<b[1]<<endl;
                x = b[0] - p[0];
                cout<<p[1]<<"\t\t"<<b[1]<<"\t\t"<<x<<endl;
                b.at(0) = x;
                sum+=b[0];
                break;
            }
        }
    }*/
    for(i=0; i<processNum; i++){
        allocated = false;
        for(j=0; j<blocksNum; j++){
            if(processes[i][0] <= blocks[j][0]){
                x = blocks[j][0] - processes[i][0];
                cout<<processes[i][1]<<"\t\t"<<blocks[j][1]<<"\t\t"<<x<<endl;
                blocks[j][0]=-1;
                sum+=x;
                allocated = true;
                break;
            }
        }
        if(!allocated){
            cout<<processes[i][1]<<"\t\t-\t\t-"<<endl;
            na = i;
        }
    }
    cout<<"\nProcess-"<<processes[na][1]<<" is not allocated\n";
    cout<<"\nTotal Internal Fragmentation = "<<sum;
}

int main(){
    memoryInput();
    MFT();
    return 0;
}