#include <iostream>
#include <string>
#include <time.h>       /* time */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <typeinfo>

using namespace std;

void createBoard(string board[][3]) {
	cout << "You are (x)" << endl;
	cout << "The computer is (o)" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] <<endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] <<endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] <<endl;
	cout << "     |     |     " << endl;
}

void makeAMove(string board[][3]) {
	int row=-1;
	int col=-1;
	while (row<0 || row>3) {
		cout << "Choose a row for your (x)" << endl;
		cin >> row;
	}
	while (col<0 || col>3) {
		cout << "Choose a col for your (x)" << endl;
		cin >> col;
	}
	
	if(board[row][col] == " "){
		board[row][col] = "x";
		return;
	} else{
		cout << "That spot is filled." << endl;
		makeAMove(board);
	}
}

bool ifFull(string board[][3]) {
	for(int i=0; i<=2; i++){
		for(int j=0; j<=2; j++){
			if(board[i][j]==" "){
				return false;
			}
		}
	}
	return true;
}

bool checkIfWon(string board[][3], string piece) {
	if (board[0][0] == board[0][1]) {
		if (board[0][1] == board[0][2]){
			if (board[0][0] == piece) {
				return true;
			}	
		}
	} 
	if (board[1][0] == board[1][1]) {
		if (board[1][1] == board[1][2]){
			if (board[1][0] == piece) {
				return true;
			}	
		}
	} 
	if (board[2][0] == board[2][1]) {
		if (board[2][1] == board[2][2]){
			if (board[2][0] == piece) {
				return true;
			}	
		}
	}
	if (board[0][0] == board[1][0]) {
		if (board[1][0] == board[2][0]){
			if (board[0][0] == piece) {
				return true;
			}	
		}
	} 
	if (board[0][1] == board[1][1]) {
		if (board[1][1] == board[2][1]){
			if (board[0][1] == piece) {
				return true;
			}	
		}
	} 
	if (board[0][2] == board[1][2]) {
		if (board[1][2] == board[2][2]){
			if (board[0][2] == piece) {
				return true;
			}	
		}
	}
	if (board[0][0] == board[1][1]) {
		if (board[1][1] == board[2][2]){
			if (board[0][0] == piece) {
				cout << "True" << endl;
				return true;
			}	
		}
	} 
	if (board[0][2] == board[1][1]) {
		if (board[1][1] == board[2][0]){
			if (board[0][2] == piece) {
				return true;
			}	
		}
	}
	return false;
}

void whereToMakeMove(string board[][3], int row, int col, string piece, int &count) {
	board[row][col] = piece;
	if(ifFull(board)){
		if(checkIfWon(board, "o")) {
			count++;
		}
	}
	if(board[0][0] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 0, 0, piece, count);
	}
	if(board[0][1] == " ") {
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 0, 1, piece, count);
	}
	if(board[0][2] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 0, 2, piece, count);
	}
	if(board[1][0] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 1, 0, piece, count);
	}
	if(board[1][1] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 1, 1, piece, count);
	}
	if(board[1][2] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 1, 2, piece, count);
	}
	if(board[2][0] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 2, 0, piece, count);
	}
	if(board[2][1] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 2, 1, piece, count);
	}
	if(board[2][2] == " "){
		if(piece == "o") {
			piece="x";
		}
		else {
			piece="o";
		}
		whereToMakeMove(board, 2, 2, piece, count);
	}
	return;
}

bool ifAboutToWin(string board[][3], string piece, int& row, int& col) {
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++) {
			if(board[i][j] == piece) {
				if(board[i][j] == board[i][j-1]){
					if(board[i][j+1] == " "){
						row = i;
						col = j+1;
						return true;
					}
				}
				
				if(board[i][j] == board[i][j+1]){
					if(board[i][j-1] == " "){
						row = i;
						col = j-1;
						return true;
					}
				}
				
				if(board[i][j] == board[i-1][j]){
					if(board[i+1][j] == " "){
						row = i+1;
						col = j;
						return true;
					}
				}
				
				if(board[i][j] == board[i+1][j]){
					if(board[i-1][j] == " "){
						row = i-1;
						col = j;
						return true;
					}
				}
				
				if(board[i][j] == board[i-1][j-1]){
					if(board[i+1][j+1] == " "){
						row = i+1;
						col = j+1;
						return true;
					}
				}
				
				if(board[i][j] == board[i-1][j+1]){
					if(board[i+1][j-1] == " "){
						row = i+1;
						col = j-1;
						return true;
					}
				}
				
				if(board[i][j] == board[i+1][j-1]){
					if(board[i-1][j+1] == " "){
						row = i-1;
						col = j+1;
						return true;
					}
				}
				
				if(board[i][j] == board[i+1][j+1]){
					if(board[i-1][j-1] == " "){
						row = i-1;
						col = j-1;
						return true;
					}
				}			
			}
		}
	}
	return false;
}

void duplicateBoard(string board[][3], string duplicate[][3]) {
	for(int i=0; i<=2; i++){
		for(int j=0; j<=2; j++){
			duplicate[i][j] = board[i][j];
		}
	}
	return;
}

void computerMove(string board[][3]) {
	int row, col;
	if (!ifAboutToWin(board, "x", row, col)){
		int count = 0;
		int wins[3][3];
		for(int i=0; i<=2; i++){
			for(int j=0; j<=2; j++){
				wins[i][j] = 0;
			}
		}
		string duplicate[3][3];
		duplicateBoard(board, duplicate);
		
		if(duplicate[0][0] == " "){
			whereToMakeMove(duplicate, 0, 0, "o", count);
			wins[0][0] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[0][1] == " "){
			whereToMakeMove(duplicate, 0, 1, "o", count);
			wins[0][1] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[0][2] == " "){
			whereToMakeMove(duplicate, 0, 2, "o", count);
			wins[0][2] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[1][0] == " "){
			whereToMakeMove(duplicate, 1, 0, "o", count);
			wins[1][0] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[1][1] == " "){
			whereToMakeMove(duplicate, 1, 1, "o", count);
			wins[1][1] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[1][2] == " "){
			whereToMakeMove(duplicate, 1, 2, "o", count);
			wins[1][2] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[2][0] == " "){
			whereToMakeMove(duplicate, 2, 0, "o", count);
			wins[2][0] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[2][1] == " "){
			whereToMakeMove(duplicate, 2, 1, "o", count);
			wins[2][1] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}
		if(duplicate[2][2] == " "){
			whereToMakeMove(duplicate, 2, 2, "o", count);
			wins[2][2] = count;
			count = 0;
			duplicateBoard(board, duplicate);
		}

		int highest = -1;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(wins[i][j] > highest){
					highest = wins[i][j];
					row=i;
					col=j;
				}
			}
		}	
	}	
	board[row][col] = "o";
}

int main() {
	bool wantToPlay = true;
	int youWon=0;
	int youLost=0;
	int youTied=0;
	while(wantToPlay){
		string board[3][3];
		for(int i=0; i<=2; i++){
			for(int j=0; j<=2; j++){
				board[i][j] = " ";
			}
		}
		bool won = false;
		bool full = false;
		string player = "x";
		string comp = "o";
		string winner;
	
		cout << "These are the indices you will use to specify what position you're placing you "<< endl;
		cout << "        |        |        " << endl;
		cout << " [0][0] | [0][1] | [0][2] " << endl;
		cout << "________|________|________" << endl;
		cout << "        |        |        " << endl;
		cout << " [1][0] | [1][1] | [1][2] " << endl;
		cout << "________|________|________" << endl;
		cout << "        |        |        " << endl;
		cout << " [2][0] | [2][1] | [2][2] " << endl;
		cout << "        |        |        " << endl;
		createBoard(board);

		while(full == false){
			makeAMove(board);
			createBoard(board);
			won = checkIfWon(board, player);
			if(won){
				winner = player;
				break;
			}
			full = ifFull(board);
			if(full){
				winner = "tie";
				break;
			}
			computerMove(board);
			createBoard(board);
			won = checkIfWon(board, comp);
			if(won){
				winner = comp;
				break;
			}
			full = ifFull(board);
			if(full){
				winner = "tie";
				break;
			}
		}
		if(winner == "tie"){
			cout << "The Game was a tie!";
			youTied++;
		}else if(winner == player){
			cout << "Congratulations you has won!!" <<endl;
			youWon++;
		}else if(winner == comp){
			cout << "Sorry you has lost!!" <<endl;
			youLost++;
		}
		int choice = -1;
		while(choice != 0 && choice!=1){
			cout <<"Do you want to play again?"<<endl<<"(0)-Yes Please!"<<endl<<"(1)-No Thank You!"<<endl;
			cin >>choice;
		}
		if(choice==1){
			wantToPlay = false;
		} else{
			system("CLS");
		}		
	}
	cout << "Your stats:" << endl;
	cout << "You won: " << youWon << " games" << endl;
	cout << "You lost: " << youLost << " games" << endl;
	cout << "You tied: " << youTied << " games" << endl;	
}
