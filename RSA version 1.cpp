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

using l = long long int;
#define S 100

l p, q,      
  n,         
  t,         
  flag,      
  e[S],    
  d[S],    
  temp[S], m[S], en[S];

  char msg[S];


bool primecheck(l var)
{
  int i, j = sqrt(var);
  for (i = 2; i <= j; ++i)
  {
    if (var % i == 0)
    {
      return false;
    }

    else
    {
      return true;
    }
  }
}

void ce()
{
  int k = 0;
  for (int i = 2; i < t; i++)
  {
    if (t % i == 0) continue;
    flag = primecheck(i);
    if (flag == 1 && i != p && i != q)
    {
      e[k] = i;
      flag = cd(e[k]);
      if (flag > 0)
      {
        d[k] = flag;
        k++;
      }

      if (k == 99)
      {
        break;
      }
    }
  }
}


l cd(l x) 
{
  long int k = 1;
  while (true)
  {
    k += t;
    if (k % x == 0) return (k / x);
  }
}


void encrypt()
{
  l pt, ct, key = e[0], k, len;
  int i = 0;

  len = strlen(msg);
  while (i != len)
  {
    pt = m[i];
    pt = pt - 96;
    k = 1;
    for (int j = 0; j < key; j++)
    {
      k *= pt;
      k %= n;
    }

    temp[i] = k;
    ct = k + 96;
    en[i] = ct;
    i++;
  }

  en[i] = -1;
  cout << "Encrypted message :\n";
  for (i = 0; en[i] != -1; i++)
  {
    printf("%c", en[i]);
  }
}


void decrypt() 
{
  l pt, ct, key = d[0], k;
  int i = 0;
  while (en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for (int j = 0; j < key; j++)
    {
      k *= ct;
      k %= n;
    }

    pt = k + 96;
    m[i] = pt;
    i++;
  }

  m[i] = -1;
  cout << "Decrypted message :\n";
  for (int i = 0; m[i] != -1; i++)
  {
    printf("%c", m[i]);
  }
}










int main()
{
  freopen
  do
  {
    cout << "Enter two primes (p,q for Euler's totient to be taken as (p-1)(q-1)) :\n";
    cin >> p >> q;
    if(primecheck(p) && primecheck(q)) break;
    else cout << "Wrong input; enter again (-_-)\n";
  }while(1); 

  cout << "Enter message for encryption :\n";
  cin >> msg;

  for (int i = 0; msg[i] != '\0'; i++)
  {
    m[i] = msg[i];
  }

  n = p * q;
  t = (p - 1) * (q - 1);
  ce();
  encrypt();
  decrypt();  

  return 0;

}
