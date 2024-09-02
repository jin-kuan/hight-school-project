#include<stdio.h>
int main(){
    int b;
    int z=0, h=0;

    scanf("%d",&b);
    printf(".\n");
    int a[b];
    for(int c=0; c<b; c++){
        scanf("%d",&a[c]);
    }
    

    for(int e=0; e<b; e++){
        for(int f=0; f<b-e; f++){
            if(a[f]>a[f+1]){
                z=a[f];
                a[f]=a[f+1];
                a[f+1]=z;
            }
        }
    }


    for(int d=0; d<b; d++){
        printf("%d ",a[d]);
    }
    printf("\n");



    for(int g=0 ; g<b; g++){
        if(a[g]<=6){
            h++;
        }

    }
    if(h>0){
        printf("wose case\n");
    }

    for(int i=0; i<b; i++){
        if(a[i]<60&&a[i]>=55){
            printf("%d ",a[i]);
        }
    }
    if (h==0)
    {
        printf("\n");
    }
    for(int j=0; j<b; j++){
        if(a[j]>=60&&a[j]<=65){
            printf("%d ",a[j]);
    }

    }



    


    

}