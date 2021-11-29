#include<stdio.h>
#include<iostream>
#include<string.h>
 
using namespace std;

string encryptMsg(string msg, int key){
    int msgLen = msg.length(), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = msg[i];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    printf("\nEncrypted Message: ");
    string enMsg = "";
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] != '\n') {
                cout<<railMatrix[i][j];
                enMsg += railMatrix[i][j];
            }
    return enMsg;
}
 
void decryptMsg(string enMsg, int key){
    int msgLen = enMsg.length(), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = '*';
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];
 
    row = col = 0;
    k = -1;
 
    printf("\nDecrypted Message: ");
 
    for(i = 0; i < msgLen; ++i){
        cout<<railMatrix[row][col++];
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
}
 
int main(){
    string msg, enMsg;
    int key = 3;
    cout<<"Enter Key: ";
    cin>>key;
    cout<<"Enter message: ";
    cin>>msg;
 
    cout<<"Original Message: "<<msg<<"\n";
    enMsg = encryptMsg(msg, key);
    decryptMsg(enMsg, key);
 
    return 0;
}