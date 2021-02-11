#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef ONLINE_JUDGE
#define freopen freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define freopen //comment
#endif

using namespace std;


int main()
{
  freopen
  string plaintext, ciphertext, key, output;
  bool choice;
  
  cout<<"enter the plaintext"<<endl;
  cin>>plaintext;
  cout<<"enter the key"<<endl;
  cin>>key;

  string newkey = key;

  while(newkey.length()<=plaintext.length())
  {
    newkey+=key;

  }

  cout<<"enter the choice either 1 or 0"<<endl;
  cin>>choice;

  if(choice==1)
  {
    for(int i = 0; i < plaintext.length(); i++)
    {
      ciphertext +=(plaintext[i]+newkey[i])%26 +65;

    }

    cout<<"ciphertext:"<<ciphertext<<endl;
  }

  else
  {
    for(int i=0; i < plaintext.length(); i++)
    {
      output+=(plaintext[i]-newkey[i]+26)%26 + 65;
    }

    cout<<"output:"<<output<<endl;
  }

  /*for(int i = 0; i < plaintext.length(); i++)
  {
    ciphertext +=(plaintext[i]-newkey[i]+26)%26 +65;

  }

  cout<<"ciphertext:"<<ciphertext<<endl;*/

  return 0;


}


// EXAMPLE INPUT FOR VINGENRE_CIPHER->
// IF CHOICE=1(TO GENERATE ENCRYPTED CODE)
// 1. PLAINTEXT: HELLO
// 2. KEY: DIVYAM 
// CIPHERTEXT WILL BE GENERATED AND PRINTED

// AND IF CHOICE=0(TO SEE ORIGINAL/DECRYPTED CODE)
//  1. PLAINTEXT: GENERATED CIPHERTEXT 
//  2. KEY: DIVYAM
//  HELLO WILL BE PRINTED 
  
  
