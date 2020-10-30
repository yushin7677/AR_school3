// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Core/Public/Math/Color.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThBody.generated.h"



UCLASS()
class THFACILITY_API AThBody : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
    AThBody(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
    TArray<float> temp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
    TArray<FLinearColor> colors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
    TArray<float> fullTemp;

    UFUNCTION(BlueprintCallable)
    virtual void temp_update(float minT_t = 20., float maxT_t=100.);

    UFUNCTION(BlueprintCallable)
    virtual void colors_update();


protected:
    float minT, maxT;
    FLinearColor cold{0.,0.,1.};
    FLinearColor heat{1.,0.,0.};
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
