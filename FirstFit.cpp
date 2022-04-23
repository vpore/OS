#include<bits/stdc++.h>
using namespace std;

int memoryBlocks, processSize, x, i, Free;
vector<vector<int>> memory;

void printTable(int c){
    x=1;
    cout<<"\nNo.\tMemory\tStatus\n";
    for(auto i : memory){
        cout<<x<<"\t"<<i[0]<<"\t";
        if(i[1] == 0){cout<<"Not Free";}
        else{cout<<"Free";}
        if(c == x-1){cout<<"  <-- New Process Allocated\n";}
        else{cout<<endl;}
        ++x;
    }
}

void memoryInput(){
    cout<<"Enter total number of memory blocks : ";
    cin>>memoryBlocks;
    cout<<"Enter size of memory block & indicate if its in use or free : \n";
    cout<<"Type '1' for FREE and '0' for NOT Free\n";
    for(i=0; i<memoryBlocks; i++){
        cin>>x>>Free;
        memory.push_back({x, Free});
    }
    cout<<"\nMemory Allocation\n";
    printTable(-1);
    cout<<"\nEnter the size of process that needs to be added : ";
    cin>>processSize;
}

void firstFit(){
    for(i=0; i<memory.size(); i++){
        if(memory[i][1] && processSize <= memory[i][0]){
            memory[i][0] -= processSize;
            memory[i][1] = 1;
            memory.insert(memory.begin()+i, {processSize, 0});
            break;
        }
    }
    if(i>=memory.size()){cout<<"Process cannot be allocated"; return;}
    cout<<"\nAfter First Fit...\n";
    printTable(i);
}

int main(){
    memoryInput();
    firstFit();
    return 0;
}