// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define END 5


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;
	int m = 5;		
	int cnt = 1;
		
	int** data = new int*[m];
	int i = 0, j = 0, k = 0;	

	cout << "Make N x M @ matrix!" << endl;
	cout << "insert N(1~15) : ";
	cin >> n;
	cout << "insert M(1~15) : ";
	cin >> m;
	cout << endl << endl;
	
	for (int i = 0; i < m; i++)
	{
		data[i] = new int[n];
	}
	/* math rule algo */
	
	for (i = 0; i < (int)((((n>m)?m:n) + 1) / 2); i++){
		int lineLengthWidth = (int)(n - 2 * i - 1);
		int lineLengthHeight = (int)(m - 2 * i - 1);			
		int lineLength = 0;
		bool lastSignal = false;

		if (lineLengthWidth == 0 || lineLengthHeight == 0){
			lastSignal = true;
			if (lineLengthWidth == 0 && lineLengthHeight == 0){ lineLengthHeight = 1; lineLengthWidth = 1; }
			else if (lineLengthWidth == 0){ lineLengthHeight += 1; }
			else if (lineLengthHeight == 0){ lineLengthWidth += 1; }
		}
		else{
			lastSignal = false;
		}

		for (j = 0; j < lastSignal?1:4; j++){
			if (j%2 == 0){
				lineLength = lineLengthWidth;
				if (lineLengthWidth == 0){
					lineLength = lineLengthHeight;
				}
			}
			else{
				lineLength = lineLengthHeight;					
			}
				
			for (k = 0; k < lineLength; k++){					
				//cout << endl;
				//cout << "tempLength : " << tempLength << "lineLengthHeight : " << lineLengthHeight << endl;
				switch ((n < m && lastSignal) ? (j + 1) : j){
				case 0:	data[i][i + k] = cnt++;	/*cout << "1";*/ break;
				case 1:	data[k + i][n - 1 - i] = cnt++;	/*cout << "2";*/ break;
				case 2:	data[m - 1 - i][n - 1 - i - k] = cnt++;	/*cout << "3";*/ break;
				case 3:	data[m - 1 - i - k][i] = cnt++;	/*cout << "4";*/ break;
				}
			}				
								
		}			
	}
	
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			printf("%4d",data[i][j]);
			Sleep(10);
			if (j == n - 1){
				cout << endl;
			}
		}
	}
	
	return 0;
}

