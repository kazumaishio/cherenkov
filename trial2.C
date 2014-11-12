
#include "TStyle.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TTimer.h"
#include "TArc.h"
TF1 *f1;
TF1 *fn;
TF1 *fp;
//TArc*newarc;
TGraph *tg;
Float_t t=0;
void trial2()
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
  

  //circular function. It doesnt go properly
  fn = new TF1("fn","sqrt(pow([0],2)-pow(x-[1],2))",0,10)
  fn->SetParameter(0,5);
  fn->SetParameter(1,0);
  fn->Draw();


  //newarc = new TArc(0,0,5,0,360);
  //newarc->Draw();
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
  fn->SetParameter(0,t);
  gPad->Modified();
  gPad->Update();

}
