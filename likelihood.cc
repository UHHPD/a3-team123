#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
double mu = 3.11538;

double poisson(double mu, int k) 
{
  double pw = pow(mu,k)/tgamma(k+1) * exp(-mu);
  return pw;
}
double prob(std::vector<int> daten, double mu);

int main() 
{
    ifstream fin("datensumme.txt");
    int n_i;
    vector<int> daten;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i); 
    }
    fin.close();
  std::cout << prob(daten,mu) << std::endl ;
}

double prob(vector<int> daten, double mu)
{
  double p = 1.0;
  for (int k : daten)
    { 
      p = p * poisson(mu,k);
    }
  return p;
}
