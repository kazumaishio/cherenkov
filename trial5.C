
#include "TStyle.h"
#include "TCanvas.h"
// #include "TF1.h"
#include "TH2F.h"
#include "TTimer.h"
// TF1 *f1;
TH2F *dummy; 
Float_t t=0;
Double_t min = 0;
Double_t max=TMath::Pi()*2;
Double_t theta[1000],x[1000],y[1000];
TGraph *tg;
Double_t r=0;
Double_t c=1;
Double_t n=1.3;

void trial5()
{
  gStyle->SetCanvasPreferGL(true);
  //gStyle->SetFrameFillColor(42);
  TCanvas *can1=new TCanvas("can1","can1",800,800);
  // can1->cd()->SetGrid();
  dummy = new TH2F("dummy","Cherenkov Radiation",10,-10,20,10,-10,20);
  dummy->SetStats(kFALSE);
  dummy->Draw();
  //can1->SetFillColor(17);
  // f1=new TF1("f1","[0]*x",-10,10);
  // f1->SetParameter(0,1);
  //f1->SetNpx(10);
  // f1->SetMaximum(10);
  // f1->SetMinimum(-10);
  // f1->Draw();
  tg=new TGraph(1000);
  for(Int_t i=0;i<1000;i++)
  {
    theta[i]=max/1000.*i;
    x[i]=0 + 0*cos(theta[i]);
    y[i]=0 + 0*sin(theta[i]);
    tg->SetPoint(i,x[i],y[i]);
    
  }
  tg->Draw("P");



  TTimer *timer = new TTimer(20);
  timer->SetCommand("Animate()");
  timer->TurnOn();
}
void Animate()
{
  if(!gROOT->GetListOfCanvases()->FindObject("can1")) return;
  t += 0.05;
  if(t>20)t-=20;
  r = t*c/n;


  for(Int_t i=0;i<1000;i++)
  {
    x[i]=0 + r*cos(theta[i]);
    y[i]=0 + r*sin(theta[i]);
    tg->SetPoint(i,x[i],y[i]);
    
  }


  gPad->Modified();
  gPad->Update();

}
