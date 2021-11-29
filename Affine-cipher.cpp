#include <iostream>

using namespace std;

int inverse(int a, int m=26)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
    
    return -1;
}

string encrypt(string plaintext, int k1, int k2)
{
    string ciphertext;
    for(int i=0; i<plaintext.size(); i++)
    if(plaintext[i]!=' ')
    ciphertext+=(k1*(plaintext[i]-97)+k2)%26+97;
    else ciphertext+=' ';
    return ciphertext;
}

string decrypt(string ciphertext, int k1, int k2)
{
    string plaintext;
    for(int i=0; i<ciphertext.size(); i++)
    if(ciphertext[i]!=' ')
    plaintext+=(((ciphertext[i]-97)+(26-k2))*inverse(k1))%26+97;
    else plaintext+=' ';
    return plaintext;
}

int main()
{
    string s="apoorvgarg";
    int k1=7, k2=2, process=1;
    string encrypt_text = encrypt(s,k1,k2);
    cout<< encrypt_text << endl;
    cout<<decrypt(encrypt_text,k1,k2)<<endl;
    return 0;
}
