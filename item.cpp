The logical part of which the weapon takes derived from

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"
class UStaticMeshComponent;
class USphereComponent;
UCLASS()
class GAMEIMPLEMENTATION_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABall();

	virtual void Tick(float DeltaTime) override;
protected:
	
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* item;
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
	UFUNCTION()
	virtual void onsphereoverlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void endsphereoverlapp(UPrimitiveComponent*OverlappedComponent, AActor* OtherActor, UPrimitiveComponent*OtherComp, int32 OtherBodyIndex);
};
