#include <iostream>
#include <cstdlib>
using namespace std;

class map{

public:
	char** matrix;


	map(){
		matrix = new char* [8];
		for(int i=0;i<8;i++){
			matrix[i] =new char[8];
		}

		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				matrix[i][j] = ' ';}
		}
	}

	~map(){
		for(int i=0;i++;i<8){
			delete[] matrix [i];
		}
	}

	void print(){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
			cout<<matrix[i][j]<<' ';
			}
			cout<<endl;
		}
	}



	int check_if_empty(int x , int y, int size){

		if(size+y>8)
		return 0;

		int eq=0;

		for(int i = 0;i<size;i++){
			if(matrix[y+i][x] == ' ')
			++eq;
		}

		if(eq==size)
		return 1;
		else
		return 0;

	}

	void fill(){
		int x,y;
		int* count = new int[4]; // [0] is battleship [1] cruiser [2] cargo [3] submarine
		for(int i=0;i<4;i++){ count[i] = 0;}

		while(count[0]+count[1]+count[2]+count[3] != 18){
			x = rand()%8;
			y = rand()%8;
			if(count[0]<1 && check_if_empty(x,y,4)==1){
				for(int i=0;i<4;i++){matrix[y+i][x] = 'B';}
				++count[0];
			}
			else if(count[1]<2 && check_if_empty(x,y,3)==1){
				for(int i=0;i<3;i++){matrix[y+i][x] = 'C';}
				++count[1];
			}
			else if(count[2]<5 && check_if_empty(x,y,2)==1){
				for(int i=0;i<2;i++){matrix[y+i][x] = 'S';}
				++count[2];
			}
			else if(count[3]<10 && check_if_empty(x,y,1)==1){
				for(int i=0;i<1;i++){matrix[y+i][x] = '_';}
				++count[3];
			}
		}
	}

};


int main(){

	map* my_map=new map[100];
	srand(time(0));
	for(int i=0;i<100;i++){

		my_map[i].fill();
		my_map[i].print();
		cout<<endl;
	}

	delete[] my_map;

}
