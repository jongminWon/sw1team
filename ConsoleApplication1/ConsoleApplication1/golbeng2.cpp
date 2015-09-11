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

int findDirection(**int, int, int);

int findDirection(int **data, int i, int j){
	
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



int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;
	int m = 5;	
	
	
	bool goStatus = true;
	int cnt = 1;
	
	int** data = new int*[m];
	int i = 0, j = 0, k = 0;
	int direction = 1; //1.right,2.left,3.up,4.down;

	cout << "Make N x M @ matrix!" << endl;
	cout << "insert N(1~15) : ";
	cin >> n;
	cout << "insert M(1~15) : ";
	cin >> m;
	cout << endl << endl;
	
	for (int i = 0; i < m+2; i++)
	{
		data[i] = new int[n+2];
	}

	/* line tracer gogo algo */
	
	for (i = 0; i < n+2; i++){
		for (j = 0; j < m+2; j++){
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1){
				data[i][j] = -1;
			}
			else{
				data[i][j] = 0;
			}
		}
	}
	/*
	i = 1; j = 1;

	data[i][j] = cnt++;

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
	*/

	

	for (i = 0; i < m+2; i++){
		for (j = 0; j < n+2; j++){
			printf("%4d",data[i][j]);
			Sleep(10);
			if (j == n - 1){
				cout << endl;
			}
		}
	}
	/*
	for (i = 1; i < m + 1; i++){
		for (j = 1; j < n + 1; j++){
			printf("%4d", data[i][j]);
			Sleep(10);
			if (j == n - 1){
				cout << endl;
			}
		}
	}*/
	
	return 0;
}

