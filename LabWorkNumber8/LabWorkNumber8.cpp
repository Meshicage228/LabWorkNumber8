#include <iostream> 
#include <cmath> 
#include <iomanip>
#include <fstream>
using namespace std;
ofstream fout("showresult.txt");
typedef double (*datavar)(double, double, int&);
void chart(double startpoint, double endpoint, double step, double eps, datavar nameofchart) {
	int k = 0;
	double sum;
	for (double x = startpoint * 10; x <= endpoint * 10; x += 1){
		sum = nameofchart(double(x / 10), eps, k);
	
		fout << setw(10) << double(x / 10) << setw(13) << sum << setw(10) << k << endl;
		cout << setw(10) << double(x / 10) << setw(13) << sum << setw(10) << k << endl;
	}
}
double SecondFunction(double x, double eps, int& j) {
	double iteration = 1;
	j = 0;
	iteration = (double)(1 / 4) * log((1 + x) / (1 - x)) - pow((double)1 / (2 * tan(x)),-1);
	return iteration;
}
double FirstFunction(double x, double eps, int& k) {
	double sum = 0, iteration = x;
	k = 1;
	while (fabs(iteration) > eps) {
		iteration = pow(x, 4 * k - 1) / (4 * k - 1);
		sum += iteration; k++;
	}
	return sum;
}
int main() {
	cout <<	setprecision(10);
	fout << setw(10) << "x " << setw(19) << "FirstFunction(x)" << setw(3) << " Number of Iterations : " << endl;
	cout << setw(10) << "x " << setw(19) << "FirstFunction(x)" << setw(3) << " Number of Iterations : " << endl;
	chart(-0.8, 0.5, 0.1, 0.00001, FirstFunction);
	fout << endl;
	cout << setw(10) << "x " << setw(19) << "SecondFunction(x)" << setw(3) << " Number of Iterations" << endl;
	fout << setw(10) << "x " << setw(19) << "SecondFunction(x)" << setw(3) << " Number of Iterations" << endl;
	chart(-0.5, 0.5, 0.1, 0.00001, SecondFunction);
	return 0;
}