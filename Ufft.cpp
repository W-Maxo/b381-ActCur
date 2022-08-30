//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Ufft.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
void BPF(register float *x,register float *y,register int N,register int I)
{
        register  float  c,s,t1,t2,t3,t4,u1,u2,u3;
        register  int i,j,p,l,L,M,M1,K;
        L=N;
        M=N/2;
        M1=N-1;
        while(L>=2){
                 l=L/2; u1=1.; u2=0.; t1=M_PI/(float)l;
                 c=cos(t1); s=(-1)*I*sin(t1);
                 for(j=0; j<l;j++)
                 {
                       for(i=j;i<N;i+=L)
                       {
                               p=i+l;
                               t1=*(x+i)+*(x+p);
                               t2=*(y+i)+*(y+p);
                               t3=*(x+i)-*(x+p);
                               t4=*(y+i)-*(y+p);
                               *(x+p)=t3*u1-t4*u2;
                               *(y+p)=t4*u1+t3*u2;
                               *(x+i)=t1;    *(y+i)=t2;
                        }
                        u3=u1*c-u2*s;
                   u2=u2*c+u1*s;  u1=u3;
                   }
                   L/=2;
      }
      j=0;
      for(i=0;i<M1;i++)
      {
             if(i>j)
             {
                     t1=*(x+j); t2=*(y+j);
                     *(x+j)=*(x+i); *(y+j)=*(y+i);
                     *(x+i)=t1; *(y+i)=t2;
             }
             K=M;
             while(j >=K)
             {
                     j-=K;K/=2;
             }
             j+=K;
     }
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
  float *x,*y,*x1,*y1;
  float *Dat;

  Series1->Clear();
  Series2->Clear();
  Series3->Clear();
  Series4->Clear();

  int n=1;

  while (n<N)
    n=n<<1;

  Dat=new float[n];

  for(int i=0;i<N;i++) {
    Dat[i]=D[i];
    Series1->AddXY(i,Dat[i],"",clRed);
  };
  for(int i=N;i<n;i++) Dat[i]=0;

  x=new float[n];
  y=new float[n];
  x1=new float[n];
  y1=new float[n];

  for(int i=0;i<n;i++) x[i]=Dat[i];

  BPF(x,y,n,1);



  for(int i=0;i<n;i++) {
    Series3->AddXY(i,sqrt(x[i]*x[i]+y[i]*y[i]),"",clRed);
  }


/*
  for(int i=8;i<n-8;i++) {
    x1[i]=0;
    y1[i]=0;
    for(int j=i-8;j<i+8;j++) {
      x1[i]+=x[j];
      y1[i]+=y[j];
    }
    x1[i]/=16;
    y1[i]/=16;
  }

  for(int i=0;i<8;i++) {
    x1[i]=x[i];
    y1[i]=y[i];
    x1[n-1-i]=x[n-1-i];
    y1[n-1-i]=y[n-1-i];
  }
*/

for(int i=0;i<n;i++) {
  if ((i>n/4)&&(i<(n-n/4))) {
    x1[i]=0;
    y1[i]=0;
  }
  else {
    x1[i]=x[i];
    y1[i]=y[i];
  }
};


  for(int i=0;i<n;i++) {
    Series2->AddXY(i,sqrt(x1[i]*x1[i]+y1[i]*y1[i]),"",clRed);
  }


  BPF(x1,y1,n,-1);
  for(int i=0;i<N;i++)
    Series4->AddXY(i,x1[i]/n,"",clRed);

  Chart1->Repaint();
  Chart2->Repaint();


  delete[] y1;
  delete[] x1;

  delete[] y;
  delete[] x;
}
//---------------------------------------------------------------------------
