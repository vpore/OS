#include<bits/stdc++.h>
using namespace std;

int memCapacity, processNum, m, i;
//vector<int> 

void memoryInput(){
    cout<<"Enter the Memory Capacity : ";
    cin>>memCapacity;
    cout<<"Enter the no. of processes : ";
    cin>>processNum;
}

void MVT(){
    for(i=0; i<processNum; i++){
        cout<<"Enter the memory required for process-"<<i+1<<" : ";
        cin>>m;
        if(m < memCapacity){
            cout<<"The memory is allocated for process-"<<i+1<<endl;
            memCapacity -= m;
            cout<<"Remaining memory : "<<memCapacity<<endl;
        }
        else{
            cout<<"The memory is not allocated to the process-"<<i+1<<endl;
        }
    }
    cout<<"External Fragmentation = "<<memCapacity;
}

int main(){
    memoryInput();
    MVT();
    return 0;
}