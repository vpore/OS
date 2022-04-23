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

void worstFit(){
    int curr=0, index;
    for(i=0; i<memory.size(); i++){
        if(memory[i][1] && processSize <= memory[i][0]){
            if(memory[i][0]-processSize > curr){
                curr = memory[i][0]-processSize;
                index=i;
            }            
        }
    }
    if(index != -1){
        memory[index][0] -= processSize;
        memory[index][1] = 1;
        memory.insert(memory.begin()+index, {processSize, 0});  
    }     
    else{cout<<"Process cannot be allocated"; return;}
    cout<<"\nAfter Worst Fit...\n";
    printTable(index);
}

int main(){
    memoryInput();
    worstFit();
    return 0;
}