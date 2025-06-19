The base class header file where the weapon takes derived from

#include "items/Ball.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "items/Doraemon.h"
ABall::ABall()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	item = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("rootcomponent"));
	SetRootComponent(item);
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(item);
}


void ABall::BeginPlay()
{
	Super::BeginPlay();
	if (Sphere)
	{
		Sphere->OnComponentBeginOverlap.AddDynamic(this, &ABall::onsphereoverlapp);
	}
	if (Sphere)
	{
		Sphere->OnComponentEndOverlap.AddDynamic(this, &ABall::endsphereoverlapp);
	}
}

void ABall::onsphereoverlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADoraemon* Character = Cast<ADoraemon>(OtherActor);
	if (Character)
	{
		Character->SetOverlapping(this);
	}
	
}

void ABall::endsphereoverlapp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ADoraemon* Character = Cast<ADoraemon>(OtherActor);
	if (Character)
	{
		Character->SetOverlapping(NULL);
	}
}


void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
