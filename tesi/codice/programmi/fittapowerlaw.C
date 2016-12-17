#include <iostream>
#include <fstream>
#include <cmath>
#include "TCanvas.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TF1.h"
#include "TGraphErrors.h"

#define Nmax 100

using namespace std;

int main(int argc, char**argv){
	TApplication app( "App",0, 0);
	fstream f;
	int ndati=0, i=0;
	double v1[Nmax],v2[Nmax];
	f.open(argv[1],ios::in);
	for(i=0;i<Nmax;i++){
		f >> v1[i];
		f >> v2[i];
		if(f.eof()) break;
	}
	if(i==Nmax-1){
		cout<<"errore-overflow"<<endl;
		return -1;
	}
	ndati = i;
	f.close();

	double x[ndati], y[ndati];
	for (i=1;i<ndati; i++) {
		x[i-1]=log(v1[i]);
		y[i-1]=log(v2[i]);
	}

	TGraph *retta = new TGraph( ndati-1, x, y);
	TCanvas *c3 = new TCanvas("c3","fit lineare",600,400);
	c3->cd();
	retta->Draw("A*");
	TF1 *f3 = new TF1("f3","[0]+[1]*x",0.,100000.);
	retta->Fit("f3");

	int gl;
	double ki;
	ki = f3->GetChisquare();
	gl = f3->GetNDF();
	cout << " [exp(A)]*x^B " <<endl;
	cout << " A e': " << f3->GetParameter(0)<< " +/- "<< f3->GetParError(0) << endl;
	cout << " B e': " << f3->GetParameter(1)<< " +/- "<< f3->GetParError(1)  << endl;  
	cout << " il Chi Quadro Ridotto vale : " << ki/gl << endl;

	app.Run();	

	return 0;
}
