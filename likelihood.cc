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
double prob2(std::vector<int> daten);
int main() 
{
  ofstream fou3("deltanll.txt");
  ofstream fou2("nll.txt");
  ofstream fou("likelihood.txt");
  ifstream fin("datensumme.txt");
  int n_i;
  vector<int> daten;
  for(int i = 0 ; i < 234 ; ++i) {
      fin >> n_i;
      daten.push_back(n_i); 
  }
  fin.close();
  std::cout << prob(daten,mu) << std::endl ;
  for(double i = 0.0; i < 6.0; i = i + 0.01 )
  {
    fou << i << " "<< prob(daten, i) << endl;
    fou2 << i << " "<< -2*log(prob(daten, i)) << endl;
    fou3 << i << " "<< (-2*log(prob(daten, i)) -2 * log(prob(daten, mu))) << endl;
  }
  double qou = -2*log(prob(daten,mu)/ prob2(daten));
  cout << qou << endl;
  cout << (qou - 233)/sqrt(466) << endl;
    
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

double prob2(vector<int> daten)
{
  double p = 1.0;
  for (int k : daten)
    { 
      p = p * poisson(k,k);
    }
  return p;
}