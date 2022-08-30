void SmoothSignal2(float * S1,float * S2,int n,int m);

void GetMas(float * p1,float * p2,int m) {
 float a,b,c;
 float SX4,SX3,SX2,SX1,SX0,
       SX2Y,SXY,SY,X,Y,TMP;
 SX4=SX3=SX2=SX1=SX0=0;
 SX2Y=SXY=SY=0;

 for(int i=0;i<m;i++) {
   X=i;Y=p1[i];

   SX1+=TMP=X;
   SY+=Y;
   SXY+=TMP*Y;
   SX2+=TMP*=X;
   SX2Y+=TMP*Y;
   SX3+=TMP*=X;
   SX4+=TMP*X;
 }
 SX0=m;

 a=b=c=0;

 if ((SX2*SX2-SX4*SX0)*(SX2*SX2-SX3*SX1)-(SX3*SX2-SX4*SX1)*(SX2*SX1-SX3*SX0)!=0)
 a=((SY*SX2-SX2Y*SX0)*(SX2*SX2-SX3*SX1)-(SXY*SX2-SX2Y*SX1)*(SX2*SX1-SX3*SX0))/
    ((SX2*SX2-SX4*SX0)*(SX2*SX2-SX3*SX1)-(SX3*SX2-SX4*SX1)*(SX2*SX1-SX3*SX0));

 if ((SX3*SX2-SX4*SX1)*(SX2*SX1-SX3*SX0)-(SX2*SX2-SX4*SX0)*(SX2*SX2-SX3*SX1)!=0)
 b=((SY*SX2-SX2Y*SX0)*(SX3*SX2-SX4*SX1)-(SXY*SX2-SX2Y*SX1)*(SX2*SX2-SX4*SX0))/
    ((SX3*SX2-SX4*SX1)*(SX2*SX1-SX3*SX0)-(SX2*SX2-SX4*SX0)*(SX2*SX2-SX3*SX1));

 c=(SY-a*SX2-b*SX1)/SX0;

 for(int i=0;i<m;i++)
   p2[i]=a*i*i+b*i+c;

};



void SmoothSignal(float * S1,float * S2,int n) {
/* float Min,Max,c,p;

 Min=Max=S1[0];
 for (int i=0;i<n;i++) {
   if(Min>S1[i]) Min=S1[i];
   if(Max<S1[i]) Max=S1[i];
 };
 p=(Max-Min)/10;


/* c=S1[0];
 int i=0,j=0;
 while(i<n) {
   if ((abs(S1[i]-c)>p)) {
     GetMas(S1+j,S2+j,j-i);
     j=i;
     c=S1[i];
   }
   i++;
 }; */


 int k=20;
 int m=k;
 float *P1,*P2;
 P1=new float[n];
 P2=new float[n];

 for(int l=0;l<n;l+=m) {
   if (l+m>n) m=n-l;
   GetMas(S1+l,P1+l,m);
 };

 m=k;

 GetMas(S1,P2,m/2);
 for(int l=m/2;l<n;l+=m) {
   if (l+m>n) {
     GetMas(S1+l,P2+l,n-l);
     break;
   }
   GetMas(S1+l,P2+l,m);
 };

 for(int l=0;l<n;l++)
   S2[l]=(P1[l]+P2[l])/2;

 delete [] P1;
 delete [] P2;


}


void SmoothSignal1(float * S1,float * S2,int n) {

 float Min,Max,c,p;

 Min=Max=S1[0];
 for (int i=0;i<n;i++) {
   if(Min>S1[i]) Min=S1[i];
   if(Max<S1[i]) Max=S1[i];
 };
 p=(Max-Min)/5;


 c=S1[0];
 int i=0,j=0,m=10;
 while(i<n) {
   if ((fabs(S1[i]-c)>p)) {
     i=i;
    if(i-j>=m) SmoothSignal2(S1+j,S2+j,i-j,m);
     else for(int k=j;k<i-j;k++) S2[k]=S1[k];
     j=i;
     c=S1[i];
   }
   i++;
   if (i==n)
   if(i-j>m) SmoothSignal2(S1+j,S2+j,i-j,m);
   else for(int k=j;k<i-j;k++) S2[k]=S1[k];
 };
 S2[n-1]=S1[n-1];









/*  float P[5];

  for(int l=0;l<n-5;l++) {
    for (int i=0;i<5;i++) P[i]=S1[i+l];
    for (int i=0;i<4;i++) {
      int mini=i;
      for (int j=4;j>i;j--)
        if(P[mini]>P[j]) mini=j;
      if (mini!=i) {
        float k=P[mini];
        P[mini]=P[i];
        P[i]=k;
      }
    }
    S2[l]=P[3];
  }
  S2[n-1]=0;
  S2[n-2]=0;
  S2[n-3]=0;
  S2[n-4]=0;

  */
}



void SmoothSignal2(float * S1,float * S2,int n,int m) {
 double *X,*YX,**A;
 double k;

  X=new double[2*m+1];
  for(int i=0;i<=2*m;i++) X[i]=0;

  YX=new double[m+1];
  for(int i=0;i<=m;i++) YX[i]=0;

  for(int i=0;i<n;i++) {
    k=1;
    for(int j=0;j<=2*m;j++) {
      X[j]+=k;
      k*=i;
    }
    k=1;
    for(int j=m;j>=0;j--) {
      YX[j]+=k*S1[i];
      k*=i;
    }
  }

  A=new double*[m+1];
  for(int i=0;i<=m;i++) {
    A[i]=new double[m+1];
    for(int j=0;j<=m;j++) A[i][j]=X[2*m-i-j];
  }

  delete [] X;

 //Решение СЛАУ A*x=YX методом Гаусса

  //Прямой ход метода Гаусса

  double *Tmp,Temp;
  int MaxI;

  for(int i=0;i<=m;i++) {

    MaxI=i;
    for(int j=i+1;j<=m;j++)
      if(A[MaxI][i]<A[j][i]) MaxI=j;
    if (A[i][MaxI]==0) {
       ShowMessage("Невозможно решить систему");
       exit(0);
    }
    Tmp=A[i];
    A[i]=A[MaxI];
    A[MaxI]=Tmp;
    Temp=YX[i];
    YX[i]=YX[MaxI];
    YX[MaxI]=Temp;

    for(int j=i+1;j<=m;j++)
      A[i][j]/=A[i][i];
    YX[i]/=A[i][i];
    for(int l=i+1;l<=m;l++) {
      for(int j=i+1;j<=m;j++)
        A[l][j]-=A[i][j]*A[l][i];
      YX[l]-=YX[i]*A[l][i];
    }
  }

  //Обратный ход метода Гаусса

  for(int i=m;i>0;i--)
    for(int l=i-1;l>=0;l--)
      YX[l]-=YX[i]*A[l][i];

  for(int i=0;i<=m;i++)
    delete [] A[i];
  delete [] A;

  double tmp;
  for(int i=0;i<n;i++) {
    k=1;
    tmp=0;
    for(int j=m;j>=0;j--) {
      tmp+=k*YX[j];
      k*=i;
    }
    S2[i]=tmp;
  }
  delete [] YX;

}
