// 97 = blank 99 = nonusable
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#define empty 0
using namespace std;
//ptr is board
class NPUZZLE {
	public :
	// Defining The Public Functions
	inline void print_goal()  { BoardObj.print_goal();}
	inline void setLine(int x){ BoardObj.setLine(x);}
	inline void setcoloun(int x){ BoardObj.setcoloun(x);}
	inline void print() { BoardObj.print(); }
	inline void printReport(){	BoardObj.printReport();}
	inline void readFromFile(string name){		BoardObj.readFromFile(name);}
	inline void writeToFile(string name){	BoardObj.writeToFile(name);}
	inline void initial_goal(){	BoardObj.initial_goal();}
	inline int isSolved() const {	return BoardObj.isSolved();}
	inline int moveIntelligent(int last_move){	return BoardObj.moveIntelligent(last_move);}
	inline int move_up(int arr[9][9]){ BoardObj.move_up(arr);};
	inline int move_left(int arr[9][9]){ BoardObj.move_left(arr);};
	inline int move_down(int arr[9][9]){ BoardObj.move_down(arr);};
	inline int move_right(int arr[9][9]){ BoardObj.move_right(arr);};
	inline void moveRandom(){ BoardObj.moveRandom();}
	void reset(int size);
	void setSize();
	void move(char selection);
	void solvePuzzle();
	void shuffle(){
		int number_of_move;
		BoardObj.shuffle(number_of_move);
	}
	 private :
		 class Board {
		 public:
			 // Defining the public functions ...
			 void print_goal();
		inline	 int move_up(){move_up(ptr);}
		inline 	 int move_left(){move_left(ptr);}
		inline 	 int move_down(){move_down(ptr);}
		inline 	 int move_right(){move_right(ptr);}
			 int move_up(int arr[9][9]);
		 	 int move_left(int arr[9][9]);
		 	 int move_down(int arr[9][9]);
		 	 int move_right(int arr[9][9]);
		inline	 void setLine(int x){ line=x;}
		inline	 void setcoloun(int x){ coloun=x;}
			 void print();
			 void readFromFile(string name);
			 void writeToFile(string name);
			 void reset(int size);
			 void setSize();
			 void moveRandom();
			 int moveIntelligent(int last_move);
			 void shuffle(int number_of_move);
			 int find_the_difference_between_two_ptr(int yeni[9][9]);
			 int isSolved() const;
			 int find_blank_coordinat_x_new(int arr[9][9]);
			 int find_blank_coordinat_y_new(int arr[9][9]);
			 int find_the_y(int ptr2[][9],int y,int line,int coloun) const;
			 int find_the_x(int ptr2[][9],int x,int line,int coloun) const;
			 int find_the_difference_between_two_coordinates(int x_1,int x_2,int y_1,int y_2) const;
			 void printReport(){		 cout << "Move number -> " << count << "\n" ;}
			 void initial_goal();
		 	 int find_the_smallest(int a,int b,int c,int d) const;
			 int copy_ptr(int ptr[9][9],int copy[9][9]);
			 private :
			 		int goal_ptr[9][9];
			 		int ptr[9][9];
					int ptr_up[9][9];
					int ptr_left[9][9];
					int ptr_down[9][9];
					int ptr_right[9][9];
					int line=3;
					int coloun=3;
					int count = 0 ;
		 }BoardObj;
};
///////////////////////////////////////////////MAİN/////////////////////////////////////////////////////////////////
int main(int argc, char* argv[]){
	NPUZZLE puzzle ;
	int size;
	int last_move=-1;
	int choise=0;
	int i=0;
	char selection;
	string name;
	srand(time(NULL));
	if(argc==1){
		cout << "please enter size : ";
		cin >> size;
		//Initializing
		puzzle.reset(size);
		puzzle.shuffle();
		puzzle.print();
		do{
			cout << "Please enter any selection : " ;
			cin >> selection ;
			if(selection=='u' || selection=='U' || selection=='l' || selection=='L' || selection=='d' || selection=='D' || selection=='r' || selection=='R')
			{
				puzzle.move(selection);
				puzzle.print();
			}
			else if(selection=='s' || selection=='S'){
				puzzle.shuffle();
				cout << "SHUFFLE BOARD : \n";
				puzzle.print();
			}
			else if(selection=='i' || selection=='I'){
				last_move=puzzle.moveIntelligent(last_move);
				puzzle.print();
			}
		}while(puzzle.isSolved()!=1 && selection!='q' && selection!='Q');
		cout << "SOLVED\n" ;
	}
	else{
		puzzle.readFromFile(argv[1]);
		puzzle.initial_goal();
		puzzle.print();
		cout << "\n";
		choise=0;
		do{
			cout << "Please select your move : " ;
			cin >> selection ;

			//SOLVING
			if(selection=='v' || selection=='V'){
				choise=0;
				do{
					if(choise%15==0 && choise!=0){
						i=0;
						while(i<3){
							cout << i ;
							puzzle.moveRandom();
							i++;
						}
					}
					else{
						last_move=puzzle.moveIntelligent(last_move);
						puzzle.print();
						cout <<  "\n";
					}
					choise++;
				}while(puzzle.isSolved()!=1 );
			}
			// PRINTING
			else if(selection=='t' || selection=='T'){
				cout << "Soloution is founded by " << choise << "moves\n";
			}
			// SAVE
			else if(selection=='e' || selection=='E'){
				cout << "Please enter file name : " ;
				cin >>name;
				puzzle.writeToFile(name);
			}
			// LOAD

			else if(selection=='s' || selection=='S'){
				puzzle.shuffle();
				cout << "SHUFFLE BOARD \n";
				puzzle.print();
			}

			else if(selection=='o' || selection=='O'){
				cout << "Please enter file name : " ;
				cin >> name;
				puzzle.readFromFile(name);
			}

			else if(selection=='u' || selection=='U'
			|| selection=='l' || selection=='L'
			|| selection=='d' || selection=='D'
			|| selection=='r' || selection=='R'){
				puzzle.move(selection);
				puzzle.print();
			}

	}while(  selection!='q' && selection!='Q');
	//	last_move=puzzle.moveIntelligent(last_move);
		cout << "SOLVED " << choise << "\n" ;
		puzzle.print();
		cout << "\n";
		puzzle.print_goal();
	}






}
void NPUZZLE::move(char selection){
	if(selection=='u' || selection=='U'){
		BoardObj.move_up();
	}
	else if(selection=='l' || selection=='L'){
		BoardObj.move_left();
	}
	else if(selection=='d' || selection=='D'){
		BoardObj.move_down();
	}
	else if(selection=='r' || selection=='R'){
		BoardObj.move_right();
	}
}
// Find the blank coordinat y(Boşluk kutucugunun y coordinatını bulan fonksiyon)
int NPUZZLE::Board::find_blank_coordinat_y_new(int arr[9][9]){
 int i=0;
 int k=0;
 for(i=0;i<=line;i++){
	 for(k=0;	k<=coloun;k++){
		 if(arr[i][k]==97){
			 return i ;
		 }
	 }
 }
}
// Find the blank coordinat x(Boşluk kutucugunun x coordinatını bulan fonksiyon)
int NPUZZLE::Board::find_blank_coordinat_x_new(int arr[9][9]){
 int i=0;
 int k=0;
 for(i=0;i<=line;i++){
	 for(k=0;k<=coloun;k++){
		 if(arr[i][k]==97){
			 return k ;
		 }
	 }
 }
}
// It looks solved or not solved(Çözülüp çözülmedigine bakan fonksiyon)
int NPUZZLE::Board::isSolved() const {
	int i,j;
	for(i=0;i<=line;i++){
		for(j=0;j<=coloun;j++){
			if(ptr[i][j]!=goal_ptr[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
// Display the goal state for testing (Test için hedef durumu yazdırman fonksiyon .....)
void ::NPUZZLE::Board::print_goal(){
	int i;
 	int k;
 	for(i=0;i<=line;i++){
	 for(k=0;k<=coloun;k++){
		 if(goal_ptr[i][k]!=99 && goal_ptr[i][k]!=95){
			 if(goal_ptr[i][k]==97)
				 cout << "\t" ;
			 else{
				 if(goal_ptr[i][k]<10)
					 cout << "0" ;
				 cout << "" << goal_ptr[i][k] << "\t";
			 }
		 }
	 }
	 cout << "\n" ;
 }
}
// Display the current state function (Puzzle ı ekrana yazdıran fonksiyon)
void NPUZZLE::Board::print(){
	int i;
 	int k;
 	for(i=0;i<=line;i++){
	 for(k=0;k<=coloun;k++){
		 if(ptr[i][k]!=99 && ptr[i][k]!=95){
			 if(ptr[i][k]==97)
				 cout << "\t" ;
			 else{
				 if(ptr[i][k]<10)
					 cout << "0" ;
				 cout << "" << ptr[i][k] << "\t";
			 }
		 }
	 }
	 cout << "\n" ;
 }
}
// Reading from the file function(Dosyadan okuma yapan fonksiyon)
void NPUZZLE::Board::readFromFile(string name){
	int i=0;
  int k=0;
  int l=0;
  int m=0;
  int row=0;
	int max=0;
  char transformation[3];
  string satir[9] ;
  ifstream infile(name);
  while(getline(infile,satir[i])){
    i++;
  }
  satir[++i]="\0";
  i=0;
  k=0;
  l=0;
  do{
    while(satir[i][k]!='\n'  && satir[i][k]!='\0'){
			if(satir[i][k]=='b' && satir[i][k+1]=='b'){
					transformation[l++]='9';
					transformation[l++]='7';
			}
			else if(satir[i][k]=='b' && satir[i][k-1]=='b'){
					transformation[l++]='9';
					transformation[l++]='7';
			}
			else if(satir[i][k]==' ')
      {
				k++;
				if(satir[i][k]=='b' && satir[i][k+1]=='b'){
						transformation[l++]='9';
						transformation[l++]='7';
				}
			}

		  transformation[l]=satir[i][k];
      l++;
      k++;
      if(satir[i][k]==' '){
        transformation[l]='\0';
        l=0;
        k++;
      }
      else{
        transformation[l]=satir[i][k];
        k++;
        transformation[++l]='\0';
        l=0;
      }
      ptr[i][m]=atoi(transformation);
		  m++;
			if(m>max && ptr[i][m]!=99){
				max=m;
			}
      transformation[0]='\0';
    }
		setcoloun(max-1);
		if(m<9){
			ptr[i][m]=95;
			m++;
		}
 		while(m<9){
      ptr[i][m]=99;
      m++;
    }
    i++;
    k=0;
    m=0;
    l=0;
  }while(satir[i]!="\0") ;
	row=i;
	while(i<9){
		m=0;
		while(m<9){
			ptr[i][m]=99;
			m++;
		}
		i++;
	}
	setLine(row-1);
	// First copying ptr to goal ptr and then ı will modify the goal state (Önce dosyadan okudugum puzzle ı hedef duruma
	// kopyalıcam daha sonra ise o puzzlı degiştirerek hedef durum yapıcam onu... )
	copy_ptr(ptr,goal_ptr);
}
// Write to File fuction(Dosyaya yazan fonksiyon)
void NPUZZLE::Board::writeToFile(string name){
	int i=0;
  int j=0;

  ofstream dosyaYaz(name);
  while(i<=line){
    while(j<=coloun){
			if(ptr[i][j]==97){
				dosyaYaz << "bb ";
			}
			else if(ptr[i][j]!=99){

				if(ptr[i][j]<10){
            dosyaYaz << "0" ;
        }
        dosyaYaz << ptr[i][j] << " " ;
      }
      j++;
    }
      dosyaYaz  << "\n" ;
      i++;
      j=0;
  }
}
// Move random function (Rastgele hareket yapan fonksiyon )
void NPUZZLE::Board::moveRandom(){
	int random;
	int x;
	int y;
	random=rand()%4;
	x=find_blank_coordinat_x_new(ptr);
	y=find_blank_coordinat_y_new(ptr);
	while(
	(random==0 && (y==0 || ptr[y-1][x]==0)) ||
	(random==1 && (x==0 || ptr[y][x-1]==0)) ||
	(random==2 && (y==line || ptr[y+1][x]==0)) ||
	(random==3 && (x==coloun || ptr[y][x+1]==0))
	){
		random=rand()%4;
	}
	if(random==0){
		move_up(ptr);
	}
	else if(random==1){
		move_left(ptr);
	}
	else if(random==2){
		move_down(ptr);
	}
	else if(random==3){
		move_right(ptr);
	}
}
void NPUZZLE::Board::shuffle(int number_of_move){
	int blank_coordinat_x;
	int blank_coordinat_y;
	int random;
	int selection;
	int i;
	int last_move=-1;
	number_of_move=line*coloun;

//	cout << "Number of moves : " << number_of_move << "\n" ;
	for(i=0;i<number_of_move;i++){
	//	display(ptr,line,coloun);
  //	cout << "\n" ;
		blank_coordinat_x=find_blank_coordinat_x_new(ptr);
		blank_coordinat_y=find_blank_coordinat_y_new(ptr);
		random=rand()%4; // 0=up , 1=left , 2=down , size=right

		while((random==0 && (blank_coordinat_y==0  || ptr[blank_coordinat_y-1][blank_coordinat_x]==0 || ptr[blank_coordinat_y-1][blank_coordinat_x]==95 || ptr[blank_coordinat_y-1][blank_coordinat_x]==99 ))
			|| (random==1 && (blank_coordinat_x==0 || ptr[blank_coordinat_y][blank_coordinat_x-1]==0 || ptr[blank_coordinat_y][blank_coordinat_x-1]==95 || ptr[blank_coordinat_y][blank_coordinat_x-1]==99))
			|| (random==2 && (blank_coordinat_y>line-1|| ptr[blank_coordinat_y+1][blank_coordinat_x]==0 || ptr[blank_coordinat_y+1][blank_coordinat_x]==95 || ptr[blank_coordinat_y+1][blank_coordinat_x]==99))
			|| (random==3 && (blank_coordinat_x>coloun-1  || ptr[blank_coordinat_y][blank_coordinat_x+1]==0   || ptr[blank_coordinat_y][blank_coordinat_x+1]==95 || ptr[blank_coordinat_y][blank_coordinat_x+1]==99 ))){
			random=rand()%4;
		}
	//	cout << "random : " << random << " y : "<< blank_coordinat_x << " x : " << blank_coordinat_x << "i : " << i<< "\n";
		// moving the blank tile !
		if(random==0 ){
	//		cout << "Pick them up\n";
			move_up(ptr);
			last_move=0;
		}
		else if(random==1 ){
	//		cout << "Pick them left\n";
			move_left(ptr);
			last_move=1;
		}
		else if(random==2 ){
	//		cout << "Pick them down\n";
			move_down(ptr);
			last_move=2;
		}
		else if(random==3 ){
//			cout << "Pick them right\n";
			move_right(ptr);
			last_move=3;
		}
		//display(ptr,line,coloun);
		//cout << "\n";


	}



}
void NPUZZLE :: reset(int size){

	BoardObj.reset(size);
}
void NPUZZLE::Board::reset(int size){
	int i=0;
	int k=0;
	for(i=0;i<size;i++){
		for(k=0;k<size;k++){
			ptr[i][k]=(i*size)+k+1;
		}
		for(k=k;k<9;k++){
			ptr[i][k]=99;
		}
	}
	ptr[size-1][size-1]=97;
	for(i=i;i<9;i++){
		for(k=0;k<9;k++){
			ptr[i][k]=99;
		}
	}
	setLine(size-1);
	setcoloun(size-1);
	copy_ptr(ptr,goal_ptr);
}

int NPUZZLE :: Board :: moveIntelligent(int last_move){
	int blank_coordinat_x;
	int blank_coordinat_y;
	// Beginning those are 99
	int check_up=99;
	int check_left=99;
	int check_down=99;
	int check_right=99;
	int ptr_up[9][9];
	int ptr_left[9][9];
	int ptr_down[9][9];
	int ptr_right[9][9];
	int smallest_one;
	int select=-1;
	// find the blank coordinates
	blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	copy_ptr(ptr,ptr_up);
	copy_ptr(ptr,ptr_left);
	copy_ptr(ptr,ptr_down);
	copy_ptr(ptr,ptr_right);
	// check if its over

	// find the best possibility
		if(blank_coordinat_y>0 && last_move!=2 && ptr[blank_coordinat_y-1][blank_coordinat_x]!=0 && ptr[blank_coordinat_y-1][blank_coordinat_x]!=95 && ptr[blank_coordinat_y-1][blank_coordinat_x]!=99){
		//cout << "UP\n";
		move_up(ptr_up);
		check_up=find_the_difference_between_two_ptr(ptr_up);

		}
		if(blank_coordinat_x>0 && last_move!=3 && ptr[blank_coordinat_y][blank_coordinat_x-1]!=0 && ptr[blank_coordinat_y][blank_coordinat_x-1]!=95 &&  ptr[blank_coordinat_y][blank_coordinat_x-1]!=99){
			//cout << "LEFT\n";
			move_left(ptr_left);
			check_left=find_the_difference_between_two_ptr(ptr_left);

		}
		if(blank_coordinat_y<=line-1 && last_move!=0 && ptr[blank_coordinat_y+1][blank_coordinat_x]!=0 && ptr[blank_coordinat_y+1][blank_coordinat_x]!=95 && ptr[blank_coordinat_y+1][blank_coordinat_x]!=99){
			//cout << "DOWN\n";
			move_down(ptr_down);
			check_down=find_the_difference_between_two_ptr(ptr_down);

		}
		if(blank_coordinat_x<=coloun-1 && last_move!=1 && ptr[blank_coordinat_y][blank_coordinat_x+1]!=0 && ptr[blank_coordinat_y][blank_coordinat_x+1]!=95 && ptr[blank_coordinat_y][blank_coordinat_x+1]!=99){
/*			cout << "RÄ°GHT\n"; 	*/
			move_right(ptr_right);
			check_right=find_the_difference_between_two_ptr(ptr_right);
		}
	//	cout << "Up -> " << check_up << "Left -> " << check_left << "Down -> " << check_down << "Right -> " << check_right << "\n" ;
		// Find the smallest one
		smallest_one=find_the_smallest(check_up,check_left,check_down,check_right);
		// If up move is up
		if(smallest_one==check_up){
					copy_ptr(ptr_up,ptr);
					last_move=0;
					cout << "Intelligent choose move U up"/* = " << check_up << " left = " << check_left <<"down = " << check_down <<" right = " << check_right*/<< "\n";

		}
		// If left move is left
		else if(smallest_one == check_down){
				copy_ptr(ptr_down,ptr);
					last_move=2;
					cout << "Intelligent choose move D up "/*= " << check_up << " left = " << check_left <<"down = " << check_down <<" right = " << check_right*/<< "\n";

		}
		// If down move is down
		else if(smallest_one == check_right){
					copy_ptr(ptr_right,ptr);
					last_move=3;
					cout << "Intelligent choose move R up "/*= " << check_up << " left = " << check_left <<"down = " << check_down <<" right = " << check_right*/<< "\n";

		}
		// If right move is right
		else if(smallest_one==check_left){
					copy_ptr(ptr_left,ptr);
					last_move=1;
					cout << "Intelligent choose move L up "/*= " << check_up << " left = " << check_left <<"down = " << check_down <<" right = " << check_right*/<< "\n";
		}


	return last_move;
}
// Calculate the heuristic
int NPUZZLE :: Board :: find_the_difference_between_two_ptr(int yeni[9][9]){
	int result=0;
	int x_1;
	int y_1;
	int x_2;//goal
	int y_2;//goal
	int i=0;
	int k=0;
	for(i=0;i<=line;i++){
		for(k=0;k<=coloun;k++){
			if(yeni[i][k]!=goal_ptr[i][k] && yeni[i][k]!=97){
				x_1=find_the_x(yeni,yeni[i][k],line,coloun);
				y_1=find_the_y(yeni,yeni[i][k],line,coloun);
				x_2=find_the_x(goal_ptr,yeni[i][k],line,coloun);
				y_2=find_the_y(goal_ptr,yeni[i][k],line,coloun);

				result= result+find_the_difference_between_two_coordinates(x_1,x_2,y_1,y_2);

		//	TTEESSTTIINNGG	cout << "PTR : " <<yeni[i][k] << "i : k : "<< i << k << " RESULT : " << result << "\n" ;
			}

		}
//		cout << "LÄ°ne over \n" ;
	}

	return result;
}
//////////////////////////////////////////////////////////////////

// copy ptr from another ptr
int NPUZZLE::Board::copy_ptr(int ptr2[9][9],int copy[9][9]){
	int i=0;
	int k=0;
	for(i=0;i<9;i++){
		for(k=0;k<9;k++){
			copy[i][k]=ptr2[i][k];
		}
	}
}
int NPUZZLE::Board::find_the_difference_between_two_coordinates(int x_1,int x_2,int y_1,int y_2) const {
	int result=0;
	if(x_2>x_1){
		result=x_2-x_1;
	}
	else{
		result=x_1-x_2;
	}
	if(y_2>y_1){
		result=result+y_2-y_1;
	}
	else{
		result=result+y_1-y_2;
	}
	return result;
}
int NPUZZLE::Board::find_the_x(int ptr2[][9],int x,int line,int coloun) const {
	int final=0;
	int i;
	int k;
	for(i=0;i<=line;i++){
		for(k=0;k<=coloun;k++){
			if(ptr2[i][k]==x){
				final=k;
			}
		}
	}
	return final;

}
int NPUZZLE::Board::find_the_y(int ptr2[][9],int y,int line,int coloun) const {
	int final=0;
	int i;
	int k;
	for(i=0;i<=line;i++){
		for(k=0;k<=coloun;k++){
			if(ptr2[i][k]==y){
				final=i;
			}
		}
	}
	return final;

}

int NPUZZLE::Board::find_the_smallest(int x_1,int x_2,int x_size,int x_4) const { // find the smallest number
	if(x_1<=x_2 && x_1<=x_size && x_1 <= x_4){
		return x_1 ;
	}
	else if(x_2<=x_size && x_2<=x_4 && x_2 <= x_1){
		return x_2 ;
	}
	else if(x_size<=x_4 && x_size<=x_2 && x_size <= x_1){
		return x_size ;
	}
	else if(x_4<=x_2 && x_4<=x_size && x_4<=x_1){
		return x_4 ;
	}
	}

int NPUZZLE::Board::move_left(int arr[][9]){
	int blank_coordinat_x=find_blank_coordinat_x_new(arr);
	int blank_coordinat_y=find_blank_coordinat_y_new(arr);
	if(blank_coordinat_x==0 || arr[blank_coordinat_y][blank_coordinat_x-1]==0 ){
		cout << "Something wrong !! left \n" ;
		return 99 ;
	}
	else{
		arr[blank_coordinat_y][blank_coordinat_x]=arr[blank_coordinat_y][blank_coordinat_x-1];
		arr[blank_coordinat_y][blank_coordinat_x-1]=97;
	}

}
int NPUZZLE::Board::move_right(int arr[][9]){
	int blank_coordinat_x=find_blank_coordinat_x_new(arr);
	int blank_coordinat_y=find_blank_coordinat_y_new(arr);
	if(blank_coordinat_x==coloun || arr[blank_coordinat_y][blank_coordinat_x+1]==0){
		cout << "Something wrong !! right \n" ;
		return 99 ;
	}
	else{
		arr[blank_coordinat_y][blank_coordinat_x]=arr[blank_coordinat_y][blank_coordinat_x+1];
		arr[blank_coordinat_y][blank_coordinat_x+1]=97;
	}
}
int NPUZZLE::Board::move_up(int arr[][9]){
	int blank_coordinat_x=find_blank_coordinat_x_new(arr);
	int blank_coordinat_y=find_blank_coordinat_y_new(arr);
	if(blank_coordinat_y==0 || arr[blank_coordinat_y-1][blank_coordinat_x]==0){
		cout << "Something Wrong !! up \n" ;
		return 99 ;
	}
	else{
		arr[blank_coordinat_y][blank_coordinat_x]=arr[blank_coordinat_y-1][blank_coordinat_x];
		arr[blank_coordinat_y-1][blank_coordinat_x]=97;
	}
}
int NPUZZLE::Board::move_down(int arr[][9]){
	int blank_coordinat_x=find_blank_coordinat_x_new(arr);
	int blank_coordinat_y=find_blank_coordinat_y_new(arr);
	if(blank_coordinat_y==line || arr[blank_coordinat_y+1][blank_coordinat_x]==0){
		cout << "Something wrong !!down \n";
		return 99;
	}
	else{
		arr[blank_coordinat_y][blank_coordinat_x]=arr[blank_coordinat_y+1][blank_coordinat_x];
		arr[blank_coordinat_y+1][blank_coordinat_x]=97;
	}
}

void NPUZZLE::Board::initial_goal(){
	int m=1;
	int i=0;
	int j;
	int k;
	int l;
	for(i=0;i<=line;i++){
		for(j=0;j<=coloun;j++){
			if(goal_ptr[i][j]!=99 && goal_ptr[i][j]!=95){
				if(goal_ptr[i][j]==0){
					goal_ptr[i][j]=0;
				}
				else{
					goal_ptr[i][j]=m++;
					k=i;
					l=j;
				}
			}
		}
	}
	goal_ptr[k][l]=97;

}
