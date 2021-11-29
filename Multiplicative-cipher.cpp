#include <iostream>

using namespace std;

int inverse(int a, int m=26)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;

    // return -1;
}

string encrypt(string plaintext, int k)
{
    string ciphertext;
    for(int i=0; i<plaintext.size(); i++)
    if(plaintext[i]!=' ')
    ciphertext+=((plaintext[i]-97)*k)%26+97;
    else ciphertext+=' ';
    return ciphertext;
}

string decrypt(string ciphertext, int k)
{
    string plaintext;
    for(int i=0; i<ciphertext.size(); i++)
    if(ciphertext[i]!=' ')
    plaintext+=((ciphertext[i]-97)*inverse(k))%26+97;
    else plaintext+=' ';
    return plaintext;
}

int main()
{
    string s="apoorvgarg";
    int k=7, process=1; //0 for encryption, 1 for decryption
    // cin>>process;
    // if(process==0)
    string encrypt_text = encrypt(s,k);
    cout<< encrypt_text << endl;
    // else if(process==1)
    cout<<decrypt(encrypt_text,k)<<endl;
    return 0;
}
