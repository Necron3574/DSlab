#include<iostream>
using namespace std;
class triple{
	public:
		int row;
		int col;
		int ele;
};
void display(triple x){
	cout<<x.row << " "<<x.col<< " "<< x.ele <<"\n";
}
void fast_transpose(triple a[], triple b[]){
	int max_cols = a[0].col;
	int num_terms = a[0].ele;
	int row_terms[max_cols];
	int startpos[max_cols];
	for(int i=0;i<max_cols;i++){
		row_terms[i] = 0;
	}
	for(int i=1;i<num_terms;i++){
		row_terms[a[i].col]++;
	}
	startpos[0] = 1;
	for(int i=1;i<max_cols;i++){
		startpos[i] = startpos[i-1]+row_terms[i-1];
	}
	for(int i=1;i<=num_terms;i++){
		int j;
		j = startpos[a[i].col]++;
		b[j].row = a[i].col;
		b[j].col = a[i].row;
		b[j].ele = a[i].ele;	
	}
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].ele = a[0].ele;
}
int main(){
	int m,n;
	int count = 0,k=0;
	triple smatrix[20];
	cout << "Enter matrix dimensions:\n";
	cin >> m >>n;
	int temp;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> temp;
			if(temp!= 0){
				smatrix[++count].row = i;
				smatrix[count].col = j;
				smatrix[count].ele = temp;		
			}
		}
	}
	smatrix[0].row = m;
	smatrix[0].col = n;
	smatrix[0].ele = count;
	cout << "Sparse Matrix\n";
	for(int i=0;i<=count;i++){
		display(smatrix[i]); 
	}
	triple transposemat[20];
	fast_transpose(smatrix,transposemat);
	cout << "Transposed Matrix\n";
	for(int i=0;i<=transposemat[0].ele;i++){
		display(transposemat[i]); 
	}
	
	return 0;
}

