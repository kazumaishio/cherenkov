#define NCIRC 5


#include "TStyle.h"
#include "TCanvas.h"
// #include "TF1.h"
#include "TH2F.h"
#include "TTimer.h"
// TF1 *f1;
TH2F *dummy; 
Float_t t=0;
Float_t ti[NCIRC]={0};
Double_t min = 0;
Double_t max=TMath::Pi()*2;
// Double_t theta[1000],x[NCIRC][1000],y[NCIRC][1000];
Double_t theta[1000],x[1000],y[1000];
TGraph *tg[NCIRC];
Double_t r[NCIRC]={0};
Double_t cen_x[NCIRC]={0};

Double_t c=1;
Double_t n=1.3;
Double_t v =1;

Double_t emit_interval;
Double_t simtime = 20;

Double_t L;
int a = 0;

void trial7()
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
  Lx=0;
  emit_interval = (Double_t)(simtime/NCIRC);
  for(Int_t i=0;i<NCIRC;i++)
    {
      tg[i] = new TGraph(1000);
      ti[i] = i * emit_interval;
      cen_x[i]= ti[i]*v;
      cout<<"ti"<<ti[i]<<endl;
    }

  for(Int_t i=0;i<1000;i++)
  {
    theta[i]=max/1000.*i;
    x[i]=0;
    y[i]=0;
    for(Int_t j=0;j<NCIRC;j++)tg[j]->SetPoint(i,x[i],y[i]);
  }
  for(Int_t i = 0; i<NCIRC;i++)  tg[i]->Draw("P");  

  TTimer *timer = new TTimer(20);
  timer->SetCommand("Animate()");
  timer->TurnOn();
}
void Animate()
{
  if(!gROOT->GetListOfCanvases()->FindObject("can1")) return;

  //time
  t += 0.05;
  if(t>simtime)
  {
    t-=simtime;
    for(Int_t i=0;i<1000;i++)
      {
	x[i]=0;
	y[i]=0;
	for(Int_t j=0;j<NCIRC;j++)tg[j]->SetPoint(i,x[i],y[i]);
      }
  }

  for(Int_t i=0;i<NCIRC;i++)
    {
	{
	  r[i] = (t-ti[i])*c/n;
	  
	}
	if(r[i]>0)      DrawCircle(tg[i],cen_x[i],0,r[i]);
    }

  

  gPad->Modified();
  gPad->Update();

}

void DrawCircle(TGraph *g,Double_t centerX,Double_t centerY,Double_t Radius)
{
  for(Int_t i=0;i<1000;i++)
  {
    x[i]=centerX + Radius*cos(theta[i]);
    y[i]=centerY + Radius*sin(theta[i]);
    g->SetPoint(i,x[i],y[i]); 
  }
  
}
