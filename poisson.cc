#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
double m = 3.11538;

double poisson(double mu, int k);

int main() {
    ofstream fou2("histpoi.txt");
    ofstream fou("hist.txt");
    vector<int> zaehler(11);
    ifstream fin("datensumme.txt");
    int n_i = 0;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        if(n_i < 11){
              zaehler[n_i] += 1;
        }
      }
  fin.close();
  for ( unsigned int k = 0 ; k < zaehler.size () ; ++ k ) {
  fou << k << " " << zaehler[k] << std::endl;
  std::cout << k << ":" << zaehler [ k ] << std::endl ;
  }
  for (int k = 0 ; k < zaehler.size () ; ++k ) {
  fou2 << k << " " << zaehler[k] << " " << 234 * poisson(m, k) << std::endl;
  }
}
double poisson(double mu, int k)
{
  double pw = (pow(mu,k) * exp(-mu))/tgamma(k+1);
  return pw;
}
