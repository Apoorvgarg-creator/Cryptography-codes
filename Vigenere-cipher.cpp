#include <iostream>

using namespace std;

string encrypt(string plaintext, string key)
{
    string ciphertext;
    for(int i=0; i<plaintext.size(); i++)
    if(plaintext[i]!=' ')
    ciphertext+=(((plaintext[i]-97)+(key[i%key.size()]-97))%26)+97;
    else ciphertext+=' ';
    return ciphertext;
}

string decrypt(string ciphertext, string key)
{
    string plaintext;
    for(int i=0; i<ciphertext.size(); i++)
    if(ciphertext[i]!=' ')
    plaintext+=(((ciphertext[i]-97)+(26-(key[i%key.size()]-97)))%26)+97;
    else plaintext+=' ';
    return plaintext;
}

int main()
{   string s;
    string key;
    cout<<"Enter plaintext and key\n";
    cin>>s;
    cin>>key;
    string encrypt_text = encrypt(s,key);
    cout<<"Encrypted text:"<<encrypt_text<<endl;
    cout<<"Decrypted text:"<<decrypt(encrypt_text,key)<<endl;
    return 0;
}

