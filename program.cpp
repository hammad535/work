#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;
// lets define hash data structure for work 
typedef map<int, int> Polynomial;

 // reading the data from the file 
pair<Polynomial, Polynomial> readPolynomial(string fileName) {
    ifstream inputFile(fileName);
    Polynomial p1, p2;
    string line;
    getline(inputFile, line);  
    stringstream ss(line);
    int coefficient, exponent;
    while (ss >> coefficient >> exponent) {
        p1[exponent] += coefficient; 
    }
    getline(inputFile, line);
    ss.str(line);
    ss.clear();
    while (ss >> coefficient >> exponent) {
        p2[exponent] += coefficient; 
    }
    return make_pair(p1, p2);
}

// writepolynomial function to write the data into file  
void writePolynomial(string fileName, Polynomial p,string label) {
    ofstream outputFile(fileName, ios::app);
    outputFile << label << ": ";
    for (auto it = p.rbegin(); it != p.rend(); it++) {
        if (it->second != 0) {
            if (it != p.rbegin() && it->second > 0) {
                outputFile << "+";
            }
            outputFile << it->second << "x^" << it->first;
        }
    }
    outputFile << endl;
    outputFile.close();
}


 // this is a function to print the values of canonical form
void printPolynomial(Polynomial p) {
    for (auto it = p.rbegin(); it != p.rend(); it++) {
        if (it->second != 0) {
            if (it != p.rbegin() && it->second > 0) {
                cout << "+";
            }
            cout << it->second << "x^" << it->first;
        }
    }
    cout << endl;
}

// this method is for adding two polynomial 
Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial sum;
    for (auto it1 = p1.begin(); it1 != p1.end(); it1++) {
        sum[it1->first] += it1->second;
    }
    for (auto it2 = p2.begin(); it2 != p2.end(); it2++) {
        sum[it2->first] += it2->second;
    }
    return sum;
}

// this method is for subtraction of two polynomials 
Polynomial subtractPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial difference;
    for (auto it1 = p1.begin(); it1 != p1.end(); it1++) {
        difference[it1->first] += it1->second;
    }
    for (auto it2 = p2.begin(); it2 != p2.end(); it2++) {
        difference[it2->first] -= it2->second;
    }
    return difference;
}

 // this method is for product  of two polynomials 
Polynomial multiplyPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial product;
    for (auto it1 = p1.begin(); it1 != p1.end(); it1++) {
        for (auto it2 = p2.begin(); it2 != p2.end(); it2++) {
            product[it1->first+it2->first] += it1->second*it2->second;
            }
            }
            return product ;
}
// this is main method 
int main()
{

  pair< Polynomial,Polynomial>
  polynomials = readPolynomial("input.txt");
  Polynomial p1 = polynomials.first;
  Polynomial p2 = polynomials.second;
  cout << " This is how data appears in file before canonical form " << endl;
  cout << "1    2   -5     1    6    0 " << endl;
  cout << "1    2   -3     1 "<< endl;
  cout << " polynomial 1 :" ;
  printPolynomial(p1);
  cout << " polynomial 2 :" ;
  printPolynomial(p2);
  Polynomial sum = addPolynomials(p1,p2); 
  cout << " sum is  :" ;
  printPolynomial(sum);
  Polynomial diff = subtractPolynomials(p1,p2); 
  cout << " difference is    :" ;
  printPolynomial(diff);
  Polynomial multi = multiplyPolynomials(p1,p2); 
  cout << " product  is  :" ;
  printPolynomial(multi);
  // calling write function 
  writePolynomial("output.text",p1 , " polynomial 1 ");
  writePolynomial("output.text",p2 , " polynomial 2 ");
  writePolynomial("output.text",sum , " sum");
  writePolynomial("output.text",diff , "difference");
  writePolynomial("output.text",multi , " product ");
  return 0;
}






