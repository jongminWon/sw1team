// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0, j = 0;
	int width = 0;
	int height = 0;		
	int cnt = 1;

	int** data;
		
	int rotate[4] = { 1, 0, -1, 0 };
	int rotateStatus = 0;

/* setting data*/

	// input data

	char rev;

	cout << "Make N x M @ matrix!" << endl << "insert N(1~15) : ";	
	cin >> width;
	cout << "insert M(1~15) : ";
	cin >> height;	
	cout << "reverse?(YorN) : ";
	cin >> rev;
	if (rev == 'y' || rev == 'Y'){
		rotateStatus = 1;
	}
	cout << endl << endl;

	//memory alloc
		
	data = new int*[height+2];
	
	for (int i = 0; i < height + 2; i++)
	{
		data[i] = new int[width + 2];
	}
	
/* main algo */
	

	// ground setting
	
	for (j = 0; j < height + 2; j++){
		for (i = 0; i < width + 2; i++){
			if (i == 0 || j == 0 || i == width + 1 || j == height + 1){
				data[j][i] = -1;				
			}
			else{
				data[j][i] = 0;				
			}
		}
	}
	i = 1; j = 1;
	data[i][j] = cnt++;

	// input data 

	while (cnt < width*height + 1){

		int x = rotate[rotateStatus%4];
		int y = rotate[(rotateStatus+1)%4];
		
		if (data[i+y][j+x] == 0){
			i += y;
			j += x;
			data[i][j] = cnt++;			
		}
		else{						
			++rotateStatus;
		}
	}	
	
/* drawing result*/

	// ground view

	cout << "== Ground View ==" << endl;
	for (j = 0; j < height + 2; j++){
		for (i = 0; i < width + 2; i++){
			printf("%4d", data[j][i]);
			Sleep(10);
			if (i == width + 1){
				cout << endl;
			}
		}
	}
	 
	cout << endl; 
	cout << endl;
	
	// real field view

	cout << "== Real field View ==" << endl;
	for (j = 1; j < height + 1; j++){
		for (i = 1; i < width + 1; i++){
			printf("%4d", data[j][i]);
			Sleep(10);
			if (i == width){
				cout << endl;
			}
		}
	}	
	
    // delete memory
		
	for (int i = 0; i < height + 2; i++)
	{		
		delete data[i];
	}
		
	delete[] data;

	return 0;
}

