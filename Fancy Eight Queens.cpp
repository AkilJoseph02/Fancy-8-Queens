#include <iostream>
#include <cmath>
using namespace std;

//Author: Akil Joseph

typedef char box[5][7];
int solutions = 1;

bool queenOk(int queenArray[], int col){
  for(int i = 0; i < col; i++){
    if( (queenArray[i] == queenArray[col]) || ((col - i) == abs(queenArray[col] - queenArray[i])) ) {
      return false;
    }
   }

	return true;
}

void printBoard(box *b[8][8]){
  cout << "Solutions #" << solutions++ << ":\n" ;
  cout << " ";
  for(int i = 0; i < 8; i++)
    cout << "_";
  cout << endl;

  for(int i = 0; i < 8; i++)
    for(int k = 0; k < 5; k++){
      cout << " " << char(179);
      for(int j = 0; j < 8; j++)
        for(int l = 0; l < 7; l++)
          cout << (*b[i][j])[k][l];
      cout << char(179) << endl;
    }

  cout << " ";
  for(int i = 0; i < 7*8; i++)
    cout << char(196);
  cout << endl;
}

int main(){
  int i, j, k, l;
  box bb, wb, bq, wq, *board[8][8];
  int q[8] = {0};
  int c = 0;
  q[0] = 0;

  for(i = 0; i < 5; i++){
    for(j = 0; j < 7; j++){
      wb[i][j] = ' ';
      bb[i][j] = char(219);

      wq[i][j] = ' ';
      bq[i][j] = char(219);
    }
  }

  wq[1][1] = char(219);
  wq[2][1] = char(219);
  wq[3][1] = char(219);
  wq[3][2] = char(219);
  wq[1][3] = char(219);
  wq[2][3] = char(219);
  wq[3][3] = char(219);
  wq[3][4] = char(219);
  wq[1][5] = char(219);
  wq[2][5] = char(219);
  wq[3][5] = char(219);

  bq[1][1] = ' ';
  bq[2][1] = ' ';
  bq[3][1] = ' ';
  bq[3][2] = ' ';
  bq[1][3] = ' ';
  bq[2][3] = ' ';
  bq[3][3] = ' ';
  bq[3][4] = ' ';
  bq[1][5] = ' ';
  bq[2][5] = ' ';
  bq[3][5] = ' ';

  for(i = 0; i < 8; i++)
    for(j = 0; j < 8; j++)
      if( (i+j) % 2 == 0)
        board[i][j] = &wb;
      else
        board[i][j] = &bb;

      while(c>=0){
    	    c++;
    	    if(c==8){
            for(i = 0; i < 8; i++)
              if( (q[i] + i) % 2 == 0)
                board[q[i]][i] = &wq;
              else
                board[q[i]][i] = &bq;
    	    	printBoard(board);
            for(i = 0; i < 8; i++)
              for(j = 0; j < 8; j++)
                if( (i+j) % 2 == 0)
                  board[i][j] = &wb;
                else
                  board[i][j] = &bb;
    	    	c--;
    	    	if(c == -1){
    	    		return -1;
    	    		q[c]++;
    			}
    		}
    	    else{
    	        q[c]=-1;
    	    }
    	   while(c>=0){
    	       q[c]++;
               if (q[c] == 8){
               	c--;
               	if(c == -1){
    	    		return -1;
    	    		q[c]++;
    			}
    	       }
    	       else if(queenOk(q,c) == true){
    	       	break;
    		   }

    	    }
    	}


}
