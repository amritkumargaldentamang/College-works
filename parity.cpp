#include<iostream>

using namespace std;

int countBits(char str[])//to count number of bits in the given data
{
	int i=0, count=0;
	
	while(str[i]!='\0')
	{
		count++;
		i++;
	}
	return count;
}

int countOnes(char str[],int num)//to count number of 1s for adding parity
{
	int ones=0, i=0;
	while(i<(num))
	{
		if(str[i]=='1')
		{
			ones++;
		}
		i++;
	}
	return ones;
}

//function to return a parity to the given data
int Parity(char str[], int ones, int type)
{
	if(type==0)
	{
		return (ones%2==0)?0:1;	//even parity
	}
	else	//odd parity
		return (ones%2==0)?1:0;
}

int main()
{
	int bits, type, ones, parity;
	char databits[40];
	
	//take input data from the user
	cout<<"Enter the binary data:\n";
	cin>>databits;
	cout<<"\n\nEnter the parity:\n0 for even\n1 for odd\n0 or 1:\n";
	cin>>type;
	
	//count the number of data bits and ones
	bits=countBits(databits);
	ones=countOnes(databits, bits);
	cout<<endl<<endl<<bits<<"\t"<<ones;
	
	//added parity with data bit
	parity =Parity(databits, ones, type);
	cout<<"\nParity is:"<<parity;
	
	//adding parity to the data 
	databits[bits]=parity + '0';
	databits[bits+1]='\0';
	cout<<"\nYour data with parity is:"<<databits;

}
