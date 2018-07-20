#include <iostream>
#include <fstream>
#include<math.h>
#include <string>
#include <cstdlib>
#include <cassert>
//#include <chrono>  // for high_resolution_clock
#include<bits/stdc++.h>
using namespace std;

	



static int value(char c)
{
    if ((c-'0')>=0 && (c-'0')<=9) { return c - '0';      }
   if ((c-'a')>=0 && (c-'a')<=5) { return c - 'a'+10;   } 
   if ((c-'A')>=0 && (c-'A')<=5) { return c - 'A'+10;  }
    return -1;
}

string str_xor(string s1,string s2)
{
    //assert(s1.length() == s2.length());

    static char const alphabet[] = "0123456789abcdef";
    
    
    string result;
    result.reserve(s1.length());
	//cout <<s1 <<" "<<s2<<endl;
	
	
	
	
	
	 
	 //cout<<(int)s2[0] % 10; 
	 
	 
	// cout<<str[0] << " "<<str[1]<<" ";
    for (int i = 0; i != s1.length(); i++)
    { 
    	//cout<<s1[i] << " " << (int)s2[i];
    	//cout <<value(s1[i]) <<" "<<value(s2[i])<<endl;
    	char p = alphabet[value(s1[i])^value(s2[i])];
    	//p = p %16;
    	//cout<< s1[i] << " " << (int) str[i] << " " << value(p) <<" ";
        // int v = value(s1[i]) ^ value(s2[i]);
        
       // cout<< p<<" ";

        //assert(v < sizeof alphabet);

        result.push_back(p);
        
        
    }
   // cout<<endl;

    return result;
}












int main() {



//auto tart = std::chrono::high_resolution_clock::now();

clock_t t,t1,t2;
    t = clock();
    

string line, text,txt[10];
string name,filename;
int i=0;
filename = "J:\\cloud computing security\\final\\final\\2018IS-18_mtp4\\" ;
//char s = '\';
cout << "Give filename: ";
getline( cin, name );
filename += name;
//cout<<filename;
ifstream fin( filename.c_str() );

if ( !fin )
{
  cout << "Error! Incorrect file."
       << endl;
  exit( EXIT_FAILURE );
}

getline( fin, txt[0]);
i=1;
while ( !fin.eof() )
{
  getline( fin, line);
  txt[0]= txt[0] +"#" +   line ;
         //   i++;

}

//for (int j=0; txt[j]!="\0"; j++)
//cout<<"------------------------------------------------------------------------"<<endl;
cout<<"Original message"<< endl;
        cout << txt[0] << endl;
cout<<"-------------------------------------------------------------------------"<<endl;

      //  cout<< txt[0].length()<<endl;



string msg =txt[0];                 //original message or plain text
long long len = msg.length();             //length of original message
cout<<len;



long long n=0;

	for(long long i=0;i <= sqrt(len);i++)
	{
		if( n *n < len)
		{
			n++;
		}
	}
	//cout<<n;
	while( (n *n) > len)
	{
		msg += "$";
		len++;
	}
	
	long long le = msg.length();        
//	cout<<n<<endl<<le<<endl;


// Changing the each character to its ascii value
long long as[len];
for(long long i =0 ; i< len;i++)
{
	as[i] = (int) msg[i];
}

//long long as_len = n*n;
/*
for(long long i =0 ; i< len;i++)
{
	cout<<as[i]<<" ";
}
*/

cout<<endl;
string hexa[len];

// changing the each charcater to hexadecimal
for(long long i =0 ; i< len;i++)
{
	  char hex[10];
	itoa (as[i],hex,16);
	hexa[i] = hex;
	//cout<<as[i]<<" ";
}
//itoa (msg,hexa,16);
/*
for(long long i =0 ; i< len;i++)
{
	cout<<hexa[i]<<" ";
}
*/
cout<<endl;
//form a square matrix


long long j;
string sq_mat[n][n];

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		sq_mat[i][j] = hexa[(i * n ) + j];
	}
}
/*
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cout<<sq_mat[i][j]<<" ";
	}
	cout<<endl;
}
*/

// transpose the matrix

string sq_mat_tr[n][n];

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		sq_mat_tr[i][j] = sq_mat[j][i];
	}
}


/*
cout<<"after transpose"<<endl;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cout<<sq_mat_tr[i][j]<<" ";
	}
	cout<<endl;
}
*/
//take the even columm (2,4 ,..) values Rewrite the row wise   and odd columm values(1,3,..) rewrite to row wise

string cipher_mat[n][n];
int k =1;
for(i=0; i < n;i++  )
{
	for(j=0;j<n;j++)
	{
			cipher_mat[i][j] = sq_mat_tr[j][k];
		
	}
	k += 2;
	if(k == n) k=0;
	
}
/*
cout<<"after r1 c "<<endl;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cout<<cipher_mat[i][j]<<" ";
	}
	cout<<endl;
}


*/

//keys for each row

string key[n];
key[0] = "23";
key[1] = "32";
key[2] = "12"; 
key[3] = "21";

for(i=4;i<n;i++)
{
	key[i] = key[i %4];
}

// ex=-r the every elements to their corresponding key values




//cout<<"after r1 c and xor with key "<<endl;
	


string str,str1;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		str =  str_xor(cipher_mat[i][j] , key[i]) ;
        
        cipher_mat[i][j] = str;
	}
	//cout<<endl;
}

/*
cout<<"after r1 c  and xor"<<endl;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cout<<cipher_mat[i][j]<<" ";
	}
	cout<<endl;
}

*/



// read the 4 col and write it row wise and read the all col and write it rowwise





string cipher_fin[n][n];
k =n-1;
for(i=0; i < n;i++  )
{
	for(j=0;j<n;j++)
	{
			cipher_fin[i][j] = cipher_mat[j][k] ;
		
	}
	k = i;
	//if(k >n) k=0;
	
}
/*
cout<<"after r4 c "<<endl;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cout<<cipher_fin[i][j]<<" ";
	}
	cout<<endl;
}
*/

string cipher_text[n][n];

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		unsigned long hex_value  =  strtoul(cipher_fin[i][j].c_str() , 0, 16);
			
			cipher_text[i][j]  = (char)hex_value;		
	}
}

/*
cout<<"cipher_text "<<endl;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cout<<cipher_text[i][j]<<" ";
	}
//	cout<<endl;
}
*/
string cipher = "";
cout<<"cipher text  = \t  ";


for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		cipher +=cipher_text[i][j];
	}
	
}


cout<<cipher<<endl;
cout<<cipher.length();
 t1 = clock() - t;
    double time_taken = ((double)t1)/CLOCKS_PER_SEC; // in seconds
 
    printf(" encryption  took %f seconds to execute \n", time_taken);

// encrytion is done , now decrptiong the cipher text into original msg

string dec = cipher;

int len_dec = dec.length();
int n_dec=0;


	for(long long i=0;i <= sqrt(len);i++)
	{
		if( n_dec *n_dec < len)
		{
			n_dec++;
		}
	}

//cout<<n_dec<<endl;

long long dec1[n_dec][n_dec];

for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
		dec1[i][j] = (int)dec[(i * n_dec ) + j];
		
		//if(dec[i][j].length() == 1 ) 
		
	}
}
/*
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			cout<<dec1[i][j] <<" ";
	}
	cout<<endl;
}

*/
// convert the ascii values to its hex values



string hexa_dec[n_dec][n_dec];
string ze ="0";
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
		char hex[10];
	itoa (dec1[i][j],hex,16);
	hexa_dec[i][j] = hex;
	if(hexa_dec[i][j].length() == 1 ) hexa_dec[i][j] = ze + hexa_dec[i][j];  
	}
	//cout<<endl;
}



/*

for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			cout<<hexa_dec[i][j] <<" ";
	}
	cout<<endl;
}
*/
//read the values row wise and write it column wise  start from 2 row and at last 1 row
string dec2[n_dec][n_dec];
k=1;

for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			dec2[j][i] = hexa_dec[k][j] ;
	}
	k++;
	if(k == n_dec) k=0;
}
/*

for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			cout<<dec2[i][j] <<" ";
	}
	cout<<endl;
}
*/
//xor the values with the corresponding row  values
string dec_xor[n_dec][n_dec];
string str_a = "0";
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{	    
			if(dec2[i][j].length() == 1 ) dec2[i][j] = str_a + dec2[i][j];
			
			dec_xor[i][j] = str_xor(dec2[i][j]  , key[i] );
	}

}
/*
cout<<endl;
cout<<"after xor" <<endl;
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			cout<<dec_xor[i][j] <<" ";
	}
	cout<<endl;
}
*/
 k =n_dec /2;
 int count =0;
 int rt =0;
 int fr = n_dec/2;

string dec_f[n_dec][n_dec];
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
		dec_f[j][i] = dec_xor[k][j] ;
	}
		
		
		count++;
		if(count %2 != 0) {
			fr++;
			k =rt;
		} 
		else
		{
			rt++;
			k = fr;
		}
		
}
/*
cout<<endl;
cout<<endl;cout<<"after row mani";
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			cout<<dec_f[i][j] <<" ";
	}
	cout<<endl;
}

*/

string dec_final[n_dec][n_dec];
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			dec_final[i][j] =dec_f[j][i] ;
	}
	//cout<<endl;
}
//cout<<endl;
//cout<<endl;
/*
for(i=0;i<n_dec;i++)
{
	for(j=0;j<n_dec;j++)
	{
			cout<<dec_final[i][j] <<" ";
	}
	cout<<endl;
}

*/
string msg_dec ="";





for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		unsigned long hex_value  =  strtoul(dec_final[i][j].c_str() , 0, 16);
			
			
			if(hex_value == 35)
			{
				msg_dec +="\n";
				continue;
				
			}
			if(hex_value == 36)break;
			
			msg_dec  += (char)hex_value;		
	}
}

cout<<"-------------------------------------------------------------------------"<<endl;
cout<<"Original message"<< endl;
       cout<<msg_dec<< endl;

 t2 = clock() - t1;
    double time_take = ((double)t2)/CLOCKS_PER_SEC; // in seconds
 
    printf("  decryption took %f seconds to execute \n", time_take);
    
    
     t2 = clock() - t;
    time_take = ((double)t2)/CLOCKS_PER_SEC; // in seconds
 
    printf("  whole algorithm took %f seconds to execute \n", time_take);
return 0;
}
