#include<stdio.h>

int main(){
int r,c, m ,n;
int a[10][10]={0};
int b[10][10]={0};
int t[10]={0};
scanf("%d %d %d",&r,&c,&m);

//printf("%d %d %d",r,c,m);

for(int i=0;i<r;i++){
    for(int j=0;  j<c;j++){
    scanf("%d",&a[i][j]);
    }
}

/*
for(int i=0;i<r;i++){
    for(int j=0; j<c;j++){
    printf("%d",a[i][j]);
    }
    printf("\n");
}

*/
for (int i=0;i<m;i++){
    scanf("%d",&t[i]);
}









printf("\n");



for(int i=0; i<m; i++){

        if(t[i]==0){
                for(int i=0;i<r;i++){
                    for(int j=0;  j<c;j++){
                        b[r-1-i][j]=a[i][j];
                    }
                }



                for(int i=0;i<r;i++){
                    for(int j=0;  j<c;j++){
                            a[i][j]=b[i][j];
                    }
                }


        }


        else if(t[i]==1){

                for(int i=0;i<r;i++){
                    for(int j=0;  j<c;j++){
                        b[j][i]=a[i][j];
                    }
                }

                n=r;
                r=c;
                c=n;


                for(int i=0;i<r;i++){
                    for(int j=0;  j<c;j++){
                        a[i][j]=b[i][j];
                    }
                }


        }


}





/*////////////¥æ´«////////////////
for(int i=0;i<r;i++){
    for(int j=0;  j<c;j++){
    b[j][i]=a[i][j];
    }
}

for(int i=0;i<r;i++){
    for(int j=0;  j<c;j++){
   a[i][j]=b[i][j];
    }
}

///////////////////////////////


///////////////Â½Âà/////////////


for(int i=0;i<r;i++){
    for(int j=0;  j<c;j++){
    b[r-1-i][j]=a[i][j];
    }
}

n=r;
r=c;
c=n;

for(int i=0;i<r;i++){
    for(int j=0;  j<c;j++){
   a[i][j]=b[i][j];
    }
}

////////////////////////*/











for(int i=0;i<c;i++){
    for(int j=0;  j<r;j++){
    printf("%d ",a[i][j]);
}
printf("\n");
}
}





