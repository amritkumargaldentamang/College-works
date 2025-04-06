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

void calculateHammingCode(char data[],unsigned int m, unsigned int r)
{	
	int n = m+r;
	char in_result[n];
	char paritybits[r];
	int i,j,p;
	int parity_type;
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
//	 for (int i = 0, j = m; i < n; i++) {
//        if ((i & (i + 1)) == 0) { // Check if it's a power of 2 position
//            in_result[i] = '0'; // Initialize parity bits to '0'
//        } else {
//            in_result[i] = data[j--]; // Fill data bits
//        }
//    }
	cout<<n<<":result-bits"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<in_result[i]<<" ";
	}
	
	cout<<"Enter the parity type: 0(even) or 1(odd):\n";
	cin>>parity_type;
	for(p=0; p<r; p++)
	{
		int parityPos = (1 << p);
		int k=0;
        char parityStr[r];
        
		for(int i = parityPos - 1; i < n; i += 2* parityPos)//pow (2, p+1))
		{
			cout<<endl;
            for (int j = i; j < i + parityPos && j < n; j++) 
			{
                if (j != parityPos - 1) 
				{
//                    parityValue ^= (in_result[j] - '0'); // XOR operation for parity calculation
					parityStr[k]= in_result[j];
					cout<<parityStr[k]<<" \t";
					k++;
                }
            }
        }
        cout<<"hello msg"<<endl;
       	paritybits[p] = calculateParity(parityStr, parity_type, r);
        cout<<paritybits[p]<<endl;
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
