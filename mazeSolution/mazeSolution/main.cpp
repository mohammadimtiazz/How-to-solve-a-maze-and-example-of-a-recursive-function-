#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

//seting the maze size 5x5
const int row = 5;
const int col = 5;

//check whether the current position in the maze is safe or not
//the positionn have to be in the range from 0 -4 both row and col
//and that location should contain one
//if it pass all the above condition then we will mark it as a safe location to move
bool safePosInMaze(int t[row][col], int x, int y){
	if (x >= 0 && x <= row && y >= 0 && y <= col && t[x][y] == 1){
		return true;
	}
	else{
		return false;
	}
}


//recursive way of utilizingthe solution
bool solveMazeUtil(int t[row][col], int x, int y, int sol[row][col]){

	//this condition confirms that it reach to the final destination right bottom corner
	if (x == row -1 && y == col -1){
		sol[x][y] = 1;
		return true;
	}

	//check the current location is safe t move or not
	if (safePosInMaze(t, x, y)){

		// if it is safe, mark solution path as 1
		sol[x][y] = 1;
		
		// decide where to ove next
		///////////////////////////
		//moving right
		if (solveMazeUtil(t,x,y+1, sol))
			return true;

		//moving down
		if (solveMazeUtil(t, x+1,y, sol))
			return true;

		//moving left
		if (solveMazeUtil(t, x,y-1, sol))
			return true;

		//moving up
		if (solveMazeUtil(t, x-1,y, sol))
			return true;

		//if nothing of the above work
		//then mark the solution matrix as zero
		sol[x][y] = 0;
		return false;
	}

	return false;
}

void printMaze(int sol[row][col]){
	//print the input matrix
	for(int i = 0; i < row; i++){
		for(int j =0; j < col; j++){
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}


bool solveMaze(int t[row][col]){
	//sol matrix will hold the solution of which way to move
	int sol[row][col] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	};

	//start with the initial position
	//and the recursive function will keep repeating the steps
	//until it reach to destination
	if (solveMazeUtil(t, 0, 0, sol)){
		cout << "maze solved" << endl;
		printMaze(sol);
		return true;
	}
	else{
		cout << "maze cant be solved"<< endl;
		return false;
	}
	printMaze(sol);
}



int main(){
	int maze[row][col] = {
		{1,1,1,0,0},
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,1,1,0},
		{0,0,0,1,1},
	};

	//call solveMaze
	solveMaze(maze);
	return 0;
}