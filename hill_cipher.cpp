#include<iostream>
#include<math.h>
using namespace std;
float en[3][1], de[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];
string decre = "", encre = "";
void encrypt() 
{
   int i, j, k;
   for(i = 0; i < 3; i++)
      for(j = 0; j < 1; j++)
         for(k = 0; k < 3; k++)
            en[i][j] = en[i][j] + a[i][k] * msg[k][j];
   for(i = 0; i < 3; i++)
      encre += (char)(fmod(en[i][0], 26) + 65); 
}
void inversematrix() {
   int i, j, k;
   float p, q;
   for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++) 
      {
         if(i == j)
            b[i][j]=1;
         else
            b[i][j]=0;
      }
   for(k = 0; k < 3; k++) {
      for(i = 0; i < 3; i++) {
         p = m[i][k];
         q = m[k][k];
         for(j = 0; j < 3; j++) {
            if(i != k) {
               m[i][j] = m[i][j]*q - p*m[k][j];
               b[i][j] = b[i][j]*q - p*b[k][j];
            }
         }
      }
   }
   for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
         b[i][j] = b[i][j] / m[i][i];
   
   cout<<"\n\nInverse Matrix is:\n";
   for(i = 0; i < 3; i++) 
   {
      for(j = 0; j < 3; j++)
         cout<<b[i][j]<<" ";
      cout<<"\n";
   }
}
void decrypt() 
{
   int i, j, k;
   
   for(i = 0; i < 3; i++)
      for(j = 0; j < 1; j++)
         for(k = 0; k < 3; k++)
            de[i][j] = de[i][j] + b[i][k] * en[k][j];
   for(i = 0; i < 3; i++) 
   {
      decre += (char)(fmod(de[i][0], 26) + 65);
   }
}
int main() {
   int i, j;
   string message;
   cout<<"Enter 3x3 matrix for key (should have inverse):\n";
   for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++) 
      {
         cin>>a[i][j];
         m[i][j] = a[i][j];
      }
   inversematrix();
   cout<<"\nEnter a string: ";
   cin>>message;

   for(int i=0; i < message.length(); i+= 3) {
      string temp = "";
      for(int j=0; j<3 && i+j<message.length(); j++)
         temp += message[i+j];
      while(temp.length() < 3)
         temp +="Z";
      for(int j = 0; j < 3; j++) {
         msg[j][0] = temp[j] - 65;
      }
      for(int j=0; j<3; j++) {
         en[j][0] = 0;
         de[j][0] = 0;
      }
      encrypt();
      decrypt();
   }
   cout<<"Encrypted message: "<<encre<<"\n";
   cout<<"Decrypted message: ";
   for(int i=0; i<message.length(); i++)
      cout<<decre[i];
}