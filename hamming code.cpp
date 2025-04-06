#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

unsigned int calculateParityBits(int datalength)
{
	unsigned int r=1;
	while(pow(2,r)<(r+datalength+1))
	{
		r++;
	}
	return r;
}

void calculateHammingCode(char data[],unsigned int m, unsigned int r)
{	
	int n = m+r;
	char in_result[n];
	
	int i,j,p;
	
	//positioning parity bit and data bits
	for(i=1; i<=n; i++)
	{
		if((i & (i-1))==0)
			{
				in_result[i-1] = '0';
			}
		else
		{
			if(m>0)
			{
				m-=1;
				in_result[i-1]= data[m];
			}
		}
		cout<<in_result[i-1]<<endl;
	}
	cout<<n<<":result-bits"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<in_result[i]<<" ";
	}

	char parityStr[n];
	for(p=0; p<r; p++)
	{
		for(i=0; i<n; i+=pow(2,p+1))
		{
			for(j=0; j<pow(2,p) && (i+j)<n; j++)
			{
				parityStr[i+j] = in_result[i+j+p];
			}
		}
	}
	

}

int calculateParity(char data[], int parity_type, int n)
{
	int i=0, ones=0;
	while(i<n)
	{
		if(data[i]=='1')
			ones++;
	}
	
	if(parity_type==0)
	{
		return (ones%2==0)?0:1;
	}
	else
	{
		return (ones%2==0)?1:0;
	}
}

int main() {
    unsigned int n;

    // Input array size
    cout << "Enter the number of data bits ";
    cin >> n;

    char databits[n];

    // Input array elements
    cout << "Enter " << n << " elements:(only binary)\n";
    for(int i = 0; i < n; i++) {
        cin >> databits[i];
    }
	
	unsigned int parity_no= calculateParityBits(n);
	cout<<parity_no<<":parity-bits. "<<"data bits= "<< n <<endl;
	calculateHammingCode(databits, n, parity_no);
	
    return 0;
}
