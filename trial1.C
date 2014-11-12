// void trial1(){
// cout<<"a"<<endl;
// TH2F * dummy = new TH2F("dummy","GRAPH TITLE IS HERE",10,-1000,1000,10,-1000,1000);
// dummy->Draw();
//    TEllipse *e = new TEllipse(0,100,200,200);
  
//  for(int t=0; t<10000;t++){
//    e->SetX1((double)t*0.1);

//  //e->SetFillColor(2);
//  e->Draw();]
//  }
// }


#include "TStyle.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TTimer.h"
TF1 *f1;
Float_t t=0;
void trial1()
{
  gStyle->SetCanvasPreferGL(true);
  //gStyle->SetFrameFillColor(42);
  TCanvas *c1=new TCanvas("can1");
  //can1->SetFillColor(17);
  f1=new TF1("f1","[0]*x",0,10);
  f1->SetParameter(0,1);
  //f1->SetNpx(10);
  f1->SetMaximum(10);
  f1->SetMinimum(0);
  f1->Draw();
  TTimer *timer = new TTimer(20);
  timer->SetCommand("Animate()");
  timer->TurnOn();
}
void Animate()
{
  if(!gROOT->GetListOfCanvases()->FindObject("can1")) return;
  t += 0.05;
  if(t>10)t-=10;
  f1->SetParameter(0,t);
  gPad->Modified();
  gPad->Update();

}
