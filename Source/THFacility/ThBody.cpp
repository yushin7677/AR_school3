// Fill out your copyright notice in the Description page of Project Settings.


#include "ThBody.h"

// Sets default values
AThBody::AThBody(const FObjectInitializer &ObjectInitializer)
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    temp = {25., 26., 30., 35., 27., 27., 21., 18., 20.};
    colors.Init({0.,0.,0.},12);
    fullTemp.Init(0.,12);
}

// Called when the game starts or when spawned
void AThBody::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AThBody::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AThBody::colors_update()
{

    for(int i = 0; i < 12; ++i)
    {
        colors[i]=FLinearColor::LerpUsingHSV(cold,heat,(fullTemp[i]-minT)/(maxT-minT));
    };
}

void AThBody::temp_update(float minT_t, float maxT_t)
{
    minT = minT_t;
    maxT = maxT_t;
    fullTemp[0]=(temp[0]-minT)/(maxT-minT);
    fullTemp[1]=(temp[1]-minT)/(maxT-minT);
    fullTemp[2]=(temp[1]-minT)/(maxT-minT);
    fullTemp[3]=(temp[2]-minT)/(maxT-minT);
    fullTemp[4]=(temp[2]-minT)/(maxT-minT);
    fullTemp[5]=(temp[2]-minT)/(maxT-minT);
    fullTemp[6]=(temp[3]-minT)/(maxT-minT);
    fullTemp[7]=(temp[3]-minT)/(maxT-minT);
    fullTemp[8]=(0.95*temp[3] + 0.05*temp[4]-minT)/(maxT-minT);
    fullTemp[9]=(0.05*temp[3] + 0.95*temp[4]-minT)/(maxT-minT);
    fullTemp[10]= (temp[4]-minT)/(maxT-minT);
    fullTemp[11]= (temp[5]-minT)/(maxT-minT);

}

