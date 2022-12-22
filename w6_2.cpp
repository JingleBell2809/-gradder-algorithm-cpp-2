#include<iostream>
using namespace std;
double a[4][4];
double b[4][4];

void insert(double x[4][4]){
	double val;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>val;
			x[i][j]=val;
		}
	}
}
double cal11(double x[4][4]){
	return (x[1][1] * x[1][2])+ (x[1][2] * x[2][1]);
}
double cal21(double x[4][4]){
	return (x[3][1] * x[4][2])+ (x[3][2] * x[4][1]);
}

double cal12(double x[4][4]){
	return (x[1][3] * x[2][4])+ (x[1][4] * x[2][3]);
}

double cal22(double x[4][4]){
	return (x[2][3] * x[1][4])+ (x[2][4] * x[1][3]);
}

void multiply(int a[5][5], int b[5][5], int row, int col, int c1){
   int c[5][5];
    for(int i=0; i<row; i++){
       for(int j=0; j<col; j++)
           c[i][j]=0;
    }
   for(int i=0; i<row; i++) {
       for(int j=0; j<col; j++){
           for(int k=0; k<c1; k++)
                  c[i][j]+=a[i][k]*b[k][j];
        }
    }
    for(int i=0; i<4; i++){
    	for(int j=0; j<4; j++){
    		printf("%d ",c[i][j]);
		}
		printf("\n");
	}
    
}

int main(){
   int a[5][5], b[5][5], r1=4, c1=4, r2=4, c2=4;
   for(int i=0; i<r1; i++){
       for(int j=0; j<c1; j++)
           cin>>a[i][j];
    }
   for(int i=0; i<r2; i++){
       for(int j=0; j<c2; j++)
           cin>>b[i][j];
    }
   multiply(a, b, r1, c2, c1);
   return 0;
}
