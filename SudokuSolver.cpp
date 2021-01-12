#include<bits/stdc++.h>
using namespace std;
#define n 9
bool isValid(int arr[n][n],int x,int y,int val){
    
    for(int i=0;i<n;i++){
        if(arr[i][y]==val){
            return false;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[x][j]==val){
            return false;
        }
    }
    int smi=x/3*3;
    int smj=y/3*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[smi+i][smj+j]==val){
                return false;
            }
        }
    }
    return true;
}
void display(int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool SudokuSolve(int arr[n][n],int i,int j){
    if(i==n){
    return true;
    }
    int ni=0,nj=0;
        if(j==n-1){
       ni=i+1;
       nj=0;
        }
        else{
            ni=i;
            nj=j+1;
        }

if(arr[i][j]!=0){
    return SudokuSolve(arr,ni,nj);
}
for(int pos=1;pos<=9;pos++){
        if(isValid(arr,i,j,pos)==true){
            arr[i][j]=pos;
            if(SudokuSolve(arr,ni,nj))
                return true;   
        }
        arr[i][j]=0;   
    }
    return false;

}
int main(){
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
   
    if(SudokuSolve(arr,0,0)){
        cout<<"Sudoku is Valid"<<endl;
        display(arr);
    }
    else{
        cout<<"Invalid Sudoku";
    }
    
}