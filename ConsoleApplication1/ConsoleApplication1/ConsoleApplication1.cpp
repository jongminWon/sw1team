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

int findDirection(int[100][100], int, int);
int findStatus(int[2], int[2]);

int findDirection(int data[100][100], int i, int j){
	
	int direction = 0;

	if (data[i][j + 1] == -1){
		direction = RIGHT;
	}
	else if (data[i][j-1] == -1){
		direction = LEFT;
	}
	else if (data[i+1][j] == -1){
		direction = DOWN;
	}
	else if (data[i-1][j] == -1){
		direction = UP;
	}
	else{
		direction = END;
	}
	return direction;
}

int findStatus(int pre[2],int post[2]){

	int direction = 0;

	if (pre[0] == post[0]){
		if (pre[1] + 1 == post[1]){
			direction = RIGHT;
		}
		else{
			direction = LEFT;
		}
	}
	else{
		if (pre[0] + 1 == post[0]){
			direction = DOWN;
		}
		else{
			direction = UP;
		}
	}
	
	return direction;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;
	int m = 5;	
	int tempLength = 0;
	int algo = 1,reverse = 0;
	bool goStatus = true;
	int cnt = 1;
	int lineLength = 0;
	int lineLengthWidth = 0;
	int lineLengthHeight = 0;
	
	int** data = new int*[m];
	int i = 0, j = 0, k = 0;
	int direction = 1; //1.right,2.left,3.up,4.down;

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

	cout << "select algo~(1,2) : ";
	cin >> algo;
	if (algo == 1){
		cout << "normal(1),reverse(2) : ";
		cin >> reverse;			
	}
	cout << "thank you";
	cout << endl << endl;


	/* line tracer gogo algo */

	if (algo == 1){		

		int data[100][100] = { 0 };

		if (reverse == 2){
			direction = 4;
		}

		n = 4;
		m = 3;

		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				data[i][j] = -1;
			}
		}
		i = 0; j = 0;

		data[0][0] = cnt++;

		while (goStatus){

			switch (direction){
			case RIGHT:
				if ((i < 0) || (j < 0) || data[i][j + 1] != -1){
					direction = findDirection(data,i,j);
				}
				else{
					data[i][++j] = cnt++;
				}
				break;
			case LEFT:
				if ((i < 0) || (j < 0) || data[i][j - 1] != -1){
					direction = findDirection(data, i, j);
				}
				else{
					data[i][--j] = cnt++;
				}
				break;
			case UP:
				if ((i < 0) || (j < 0) || data[i - 1][j] != -1){
					direction = findDirection(data, i, j);
				}
				else{
					data[--i][j] = cnt++;
				}
				break;
			case DOWN:
				if ((i < 0) || (j < 0) || data[i + 1][j] != -1){
					direction = findDirection(data, i, j);
				}
				else{
					data[++i][j] = cnt++;
				}
				break;
			}

			if (findDirection(data, i, j)==5){
				goStatus = false;
			}


		}
	}

	/* math rule algo */

	else if (algo == 2){

		for (i = 0; i < (int)((((n>m)?m:n) + 1) / 2); i++){
			lineLengthWidth = (int)(n - 2 * i - 1);
			lineLengthHeight = (int)(m - 2 * i - 1);

			if (lineLengthWidth == 0 || lineLengthHeight == 0){
				tempLength = 1;				
				if (lineLengthWidth == 0 && lineLengthHeight == 0){ lineLengthHeight = 1; lineLengthWidth = 1; }
				else if (lineLengthWidth == 0){ lineLengthHeight += 1; }
				else if (lineLengthHeight == 0){ lineLengthWidth += 1; }
			}
			else{
				tempLength = 4;
			}

			for (j = 0; j < tempLength; j++){
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
					switch ((n < m && tempLength == 1)?(j+1):j){
					case 0:	data[i][i + k] = cnt++;	/*cout << "1";*/ break;
					case 1:	data[k + i][n - 1 - i] = cnt++;	/*cout << "2";*/ break;
					case 2:	data[m - 1 - i][n - 1 - i - k] = cnt++;	/*cout << "3";*/ break;
					case 3:	data[m - 1 - i - k][i] = cnt++;	/*cout << "4";*/ break;
					}
				}				
								
			}			
		}
	}	

	cout << endl;

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

